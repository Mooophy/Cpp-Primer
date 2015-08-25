/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * 
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


#include <iostream>
using std::istream; using std::ostream;

#include "ex17_4_5_6_7_8_SalesData.h"

Sales_data::Sales_data(std::istream &is) 
{
	// read will read a transaction from is into this object
	read(is, *this);
}

double 
Sales_data::avg_price() const {
	if (units_sold)
		return revenue/units_sold;
	else
		return 0;
}

// add the value of the given Sales_data into this object
Sales_data& 
Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold; // add the members of rhs into 
	revenue += rhs.revenue;       // the members of ``this'' object
    return *this; // return the object on which the function was called
}
// = Sales_data
Sales_data &Sales_data::operator =(const Sales_data &rhs)
{
    this->bookNo        = rhs.bookNo;
    this->revenue       = rhs.revenue;
    this->units_sold    = rhs.units_sold;

    return *this;
}

// =string
Sales_data &Sales_data::operator =(const std::string &rhs)
{
    *this= Sales_data(rhs);
    return *this;
}

// +=
Sales_data &Sales_data::operator +=(const Sales_data &rhs)
{
    this->revenue += rhs.revenue;
    this->units_sold += rhs.units_sold;

    return *this;
}

Sales_data 
add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;  // copy data members from lhs into sum
	sum.combine(rhs);      // add data members from rhs into sum
	return sum;
}

// transactions contain ISBN, number of copies sold, and sales price
istream&
read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream&
print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " 
	   << item.revenue << " " << item.avg_price();
	return os;
}

// added 10.Jan 2014
std::ostream &
operator <<(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();

    return os;
}

// added 12.Jan 2014
std::istream&
operator >>(std::istream &is, Sales_data &s)
{
    double price;

    // read input
    is >> s.bookNo >> s.units_sold >> price;

    // if successful, write into the object, give the object default state otherwise.
    if(is)
        s.revenue = s.units_sold * price;
    else
        s = Sales_data();

    return is;
}
