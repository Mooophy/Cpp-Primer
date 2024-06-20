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

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <cctype>
using std::toupper;

// chapter 6 will explain functions
// tolower and toupper change the argument itself, not a local copy
string &tolower(string &s)
{
	for (auto &i : s)
		i = tolower(i);
	return s;
}

string &toupper(string &s)
{
	for (auto &i : s)
		i = toupper(i);
	return s;
}

int main()
{
	int i = 0;
	cout << i << " " << ++i << endl;  // undefined

	string s("a string"), orig = s;
	cout << toupper(s) << endl;  // changes s to  uppercase
	cout << tolower(s) << endl;  // changes s to lowercase

	s = orig;
	// the calls to toupper and tolower change the value of s
	// << doesn't guarantee order of evaluation, 
	// so this expression is undefined
	cout << toupper(s) << " " << tolower(s) << endl; 

	string first = toupper(s);  // we control the order of evaluation
	string second = tolower(s); // by storing the results in the order in which we want

	cout << first << " " << second << endl;  // one possible evaluation
	cout << second << " " << first << endl;  // equally legal evaluation!
	cout << first << " " << first << endl;   // another legal evaluation!
	cout << second << " " << second << endl; // and a fourth!

	return 0;
}
