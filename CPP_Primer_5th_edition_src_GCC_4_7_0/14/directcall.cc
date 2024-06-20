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

#include "Sales_data.h"

#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

int main()
{
	Sales_data data1, data2;
	std::cin >> data1 >> data2;    // read Sales_data transactions
	cout << data1 + data2 << endl; // write sum of Sales_data objects
	cout << 42 + 5 << endl;        // write sum of ints
	
	// equivalent calls to a nonmember operator function
	data1 + data2;            // normal expression
	operator+(data1, data2);  // equivalent function call
	cout << operator+(data1, data2) << endl;
	
	data1 += data2;           // expression-based ``call''
	data1.operator+=(data2);  // equivalent call to a member operator function
	cout << data1 << endl;
	
	return 0;
}
