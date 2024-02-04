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

// Version_test.h contains definitions for to_string and stod
// if the compiler does not yet define these functions,
// this code will use the definitions we provide
#include "Version_test.h" 

#include <string>
using std::string;
#ifdef STRING_NUMERIC_CONVS
using std::to_string; using std::stod;
#endif

#include <iostream>
using std::cout; using std::endl;

int main()
{
	int i = 42;
	// converts the int i to its character representation
	string s = to_string(i);  

	double d = std::stod(s);   // converts the string s to floating-point
	cout << "i = " << i << " s = " << s << " d is: " << d << endl;

	// convert the first substring in s that starts with a digit,  d = 3.14
	string s2 = "pi = 3.14";
	d = std::stod(s2.substr(s2.find_first_of("+-.0123456789")));

	cout << "d = " << d << " s = " << s << " s2 is: " << s2 << endl;

	return 0;
}
