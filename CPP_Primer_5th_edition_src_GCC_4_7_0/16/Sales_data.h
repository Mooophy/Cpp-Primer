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

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

// unchanged from chapter 14 except for added friend declaration for hash
class Sales_data {
friend class std::hash<Sales_data>;
friend std::ostream &operator<<
                         (std::ostream&, const Sales_data&);
friend std::istream &operator>>(std::istream&, Sales_data&);
friend bool operator==(const Sales_data &, const Sales_data &);

friend std::ostream &print(std::ostream&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
public:
	// constructors
	Sales_data() = default;
	Sales_data(const std::string &s): bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p):
	           bookNo(s), units_sold(n), revenue(p*n) { }
	Sales_data(std::istream &);
	std::string isbn() const { return bookNo; }
	Sales_data& operator+=(const Sales_data&);
private:
	double avg_price() const;  
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

namespace std {
template <>              // we're defining a specialization with
struct hash<Sales_data>  // the template parameter of Sales_data
{
    // the type used to hash an unordered container must define these types
    typedef size_t result_type;
    typedef Sales_data argument_type; // by default, this type needs ==

    size_t operator()(const Sales_data& s) const;

    // our class uses synthesized copy control and default constructor
    // other members as before
};
}  // close the std namespace; note: no semicolon after the close curly

// non-member Sales_data operations
inline
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{ return lhs.isbn() < rhs.isbn(); }

inline
bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn() && 
	       lhs.units_sold == rhs.units_sold && 
	       lhs.revenue == rhs.revenue;
}
inline
bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
	return !(lhs == rhs);
}

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);
std::ostream &operator<<(std::ostream&, const Sales_data&);
std::istream &operator>>(std::istream&, Sales_data&);
#endif
