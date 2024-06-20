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

int main()
{
	int grade = 75;
	cout << ((grade < 60) ?  "fail" : "pass"); // prints pass or fail
	cout << endl;

	cout << (grade < 60) ?  "fail" : "pass";   // prints 1 or 0!
	cout << endl;

	// previous expression is equivalent to the following
	cout << (grade < 60);    // prints 1 or 0
	cout ?  "fail" : "pass"; // test cout and then yield one of the two literals
	                         // depending on whether cout is true or false
	cout << endl;
	int i = 15, j = 20;
	cout << (i < j ? i : j);  // ok: prints smaller of i and j
	cout << endl;

	cout << (i < j) ? i : j;  // ok: prints 1 or 0!
	cout << endl;
	
	// previous expression is equivalent to the following
	cout << (i < j); // prints 1 or 0
	cout ? i : j;    // test cout and then evaluate i or j
	                 // depending on whether cout evaluates to true or false
	cout << endl;

	return 0;
}
