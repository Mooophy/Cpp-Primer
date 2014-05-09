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

//!
//! Exercise 14.45:
//! Write conversion operators to convert a Sales_data to string and to double.
//! What values do you think these operators should return?
//!
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>


class Sales_data
{
    //! friends
    friend Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);

    friend std::ostream&
    operator << (std::ostream& os, const Sales_data& s);

    friend std::istream&
    operator >> (std::istream& is, Sales_data& s);

    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);

public:
	// constructors
	Sales_data() = default;
	Sales_data(const std::string &s): bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p):
	           bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(const Sales_data &s ):
        bookNo(s.bookNo), units_sold(s.units_sold), revenue(s.revenue)
    {}

    Sales_data(Sales_data&& s):
        bookNo(s.bookNo), units_sold(s.units_sold), revenue(s.revenue)
    {}

    ~Sales_data(){}
	Sales_data(std::istream &);

	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);

    //! assignments
    Sales_data& operator  =(const Sales_data& rhs);
    Sales_data& operator  =(const std::string&  rhs);
    Sales_data& operator +=(const Sales_data& rhs);

    //! conversion
    explicit operator std::string () const { return bookNo; }
    explicit operator double      () const { return revenue;}

	double avg_price() const;
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};


//! overloaded operators added 10.Jan.2014 for ex14.2
inline Sales_data
operator+(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data sum = lhs;
    sum += rhs;

    return sum;
}

std::ostream&
operator << (std::ostream& os, const Sales_data& item);

std::istream&
operator >> (std::istream& is, Sales_data& s);

// nonmember Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

// used in future chapters
inline 
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}
#endif
