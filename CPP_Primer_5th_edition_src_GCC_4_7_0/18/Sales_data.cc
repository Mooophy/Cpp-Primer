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

#include <string>
using std::istream; using std::ostream;

#include "Sales_data.h"
#include "bookexcept.h"

// this version of the compound assignment operator
// throws an exception if the objects refer to different books
Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
    if (isbn() != rhs.isbn())
        throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// operator+ code is unchanged, but because it uses +=
// this version of the function also throws when called
// for books whose isbns differ
Sales_data 
operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;  // copy data members from lhs into sum
	sum += rhs;            // add rhs into sum
	return sum;
}

// remaning functions unchanged from chapter 16
// define the hash interface for Sales_data
namespace std {
size_t
hash<Sales_data>::operator()(const Sales_data& s) const
{
    return hash<string>()(s.bookNo) ^
           hash<unsigned>()(s.units_sold) ^
           hash<double>()(s.revenue);
}
}  // close the std namespace; note: no semicolon after the close curly

// remaining members unchanged from chapter 14
Sales_data::Sales_data(istream &is) 
{
	is >> *this; // read a transaction from is into this object
}

double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue/units_sold;
	else
		return 0;
}

istream &operator>>(istream &is, Sales_data &item)
{
	double price;  // no need to initialize; we'll read into price before we use it
	is >> item.bookNo >> item.units_sold >> price;
	if (is)        // check that the inputs succeeded
    	item.revenue = item.units_sold * price;
	else
    	item = Sales_data(); // input failed: give the object the default state
	return is;
}

ostream &operator<<(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " 
	   << item.revenue << " " << item.avg_price();
	return os;
}

// operators replace these original named functions
istream &read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}
ostream &print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " 
	   << item.revenue << " " << item.avg_price();
	return os;
}
	
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;  // copy data members from lhs into sum
	sum += rhs;            // add rhs into sum
	return sum;
}

