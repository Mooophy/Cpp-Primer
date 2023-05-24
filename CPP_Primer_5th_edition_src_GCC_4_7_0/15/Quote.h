/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/ 

#ifndef QUOTE_H
#define QUOTE_H

#include "Version_test.h"

#include <memory>
#include <iostream>
#include <string>
#include <cstddef>

// Item sold at an undiscounted price
// derived classes will define various discount strategies
class Quote {
friend std::istream& operator>>(std::istream&, Quote&);
friend std::ostream& operator<<(std::ostream&, const Quote&);
public:
	Quote() = default;  
    Quote(const std::string &book, double sales_price):
                     bookNo(book), price(sales_price) { }

    // virtual destructor needed 
	// if a base pointer pointing to a derived object is deleted
    virtual ~Quote() = default; // dynamic binding for the destructor

    std::string isbn() const { return bookNo; }

    // returns the total sales price for the specified number of items
    // derived classes will override and apply different discount algorithms
    virtual double net_price(std::size_t n) const 
               { return n * price; }

	// virtual function to return a dynamically allocated copy of itself

#ifdef REFMEMS
    virtual Quote* clone() const & {return new Quote(*this);}
    virtual Quote* clone() && {return new Quote(std::move(*this));}
#else
	// without reference qualification on member functions
	// we can't overloaded on rvalue reference and const lvalue reference
	// so for now we just implement a single version that copies itself
    virtual Quote* clone() const {return new Quote(*this);}
#endif
private:
    std::string bookNo; // ISBN number of this item
protected:
    double price = 0.0; // normal, undiscounted price
};

// abstract base class to hold the discount rate and quantity
// derived classes will implement pricing strategies using these data
class Disc_quote : public Quote {
public:
    // other members as before
    Disc_quote() = default;
    Disc_quote(const std::string& book, double price,
              std::size_t qty, double disc):
                 Quote(book, price),
                 quantity(qty), discount(disc) { }

    double net_price(std::size_t) const = 0;

    std::pair<size_t, double> discount_policy() const
        { return {quantity, discount}; }
protected:
    std::size_t quantity = 0; // purchase size for the discount to apply
    double discount = 0.0;    // fractional discount to apply
};

// the discount kicks in when a specified number of copies of the same book are sold
// the discount is expressed as a fraction used to reduce the normal price

class Bulk_quote : public Disc_quote { // Bulk_quote inherits from Quote
public:
    Bulk_quote() = default;  
    Bulk_quote(const std::string& book, double p, 
	           std::size_t qty, double disc) :
               Disc_quote(book, p, qty, disc) { }

    // overrides the base version in order to implement the bulk purchase discount policy
    double net_price(std::size_t) const override;

#ifdef REFMEMS
    Bulk_quote* clone() const & {return new Bulk_quote(*this);}
    Bulk_quote* clone() && {return new Bulk_quote(std::move(*this));}
#else
    Bulk_quote* clone() const {return new Bulk_quote(*this);}
#endif
};

// discount (a fraction off list) for only a specified number of copies, 
// additional copies sold at standard price
class Lim_quote : public Disc_quote {
public:
    Lim_quote(const std::string& book = "", 
             double sales_price = 0.0,
             std::size_t qty = 0, double disc_rate = 0.0):
                 Disc_quote(book, sales_price, qty, disc_rate) { }

    // overrides base version so as to implement limited discount policy
    double net_price(std::size_t) const;

#ifdef REFMEMS
    Lim_quote* clone() const & { return new Lim_quote(*this); }
    Lim_quote* clone() && { return new Lim_quote(std::move(*this)); }
#else
    Lim_quote* clone() const { return new Lim_quote(*this); }
#endif
};

double print_total(std::ostream &, const Quote&, std::size_t);

#endif

