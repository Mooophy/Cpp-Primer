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
 * reproduced. Any commercial use of this code requires the explicit written
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
#ifndef SMALL_SI_H
#define SMALL_SI_H

// This file isn't used in our code, but illustrates the
// definitions that are equivalent to Sales_data's 
// synthesized copy control members 

#include <string>

class Sales_data {
public:
    Sales_data(const std::string & s = ""): bookNo(s),
                                          units_sold(0), revenue(0.0) { }

	Sales_data(const std::string &book, unsigned cnt, double price):
	        bookNo(book), units_sold(cnt), revenue(cnt * price) { }

	// equivalent to the synthesized copy constructor
	Sales_data(const Sales_data &rhs): bookNo(rhs.bookNo),
                    units_sold(rhs.units_sold), revenue(rhs.revenue) { }

	// equivalent to the synthesized destructor
	// no work to do other than destroying the members, 
	// which happens automatically
    ~Sales_data() { } 
   
    Sales_data& operator=(const Sales_data &); // assignment operator
private:
    std::string bookNo;
    int units_sold = 0;
    double revenue = 0.0;
};

// equivalent to the synthesized copy-assignment operator
Sales_data& 
Sales_data::operator=(const Sales_data &rhs)
{
	bookNo = rhs.bookNo;          // calls the string::operator=
	units_sold = rhs.units_sold;  // uses the built-in int assignment
	revenue = rhs.revenue;        // uses the built-in double assignment
	return *this;                 // return a reference to this object
}

#endif
