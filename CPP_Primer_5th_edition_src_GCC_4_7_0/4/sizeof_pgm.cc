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

#include <iostream>
using std::cout; using std::endl;

#include "Sales_data.h"

int main() 
{
	Sales_data data, *p;
	sizeof(Sales_data); // size required to hold an object of type Sales_data 
	sizeof data; // size of data's type, i.e., sizeof(Sales_data)
	sizeof p;    // size of a pointer
	sizeof *p;   // size of the type to which p points, i.e., sizeof(Sales_data)
	sizeof data.revenue; // size of the type of Sales_data's revenue member 
	sizeof Sales_data::revenue; // alternative way to get the size of revenue
	
	cout << "short: " << sizeof(short) << "\n"
	     << "short[3]: " << sizeof(short[3]) << "\n"
	     << "short*: " << sizeof(short*) << "\n"
	     << "short&: " << sizeof(short&) << endl;
	
	cout << endl; 
	
	cout << "int: " << sizeof(int) << "\n"
	     << "int[3]: " << sizeof(int[3]) << "\n"
	     << "int*: " << sizeof(int*) << "\n"
	     << "int&: " << sizeof(int&) << endl;
	
	cout << endl; 
	
	cout << "Sales_data: " << sizeof(Sales_data) << "\n"
	     << "Sales_data[3]: " << sizeof(Sales_data[3]) << "\n"
	     << "Sales_data*: " << sizeof(Sales_data*) << "\n"
	     << "Sales_data&: " << sizeof(Sales_data&) << endl;
	
	cout << "Sales_data::revenue: " << sizeof Sales_data::revenue << "\n"
	     << "data.revenue: " << sizeof data.revenue << endl;

	int x[10];   
	int *ip = x;

	// number of elements in x
	cout << sizeof(x)/sizeof(*x) << endl;

	// divides sizeof a pointer by sizeof an int
	cout << sizeof(ip)/sizeof(*ip) << endl;
	
	return 0;
}
