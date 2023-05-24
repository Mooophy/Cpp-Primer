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

#include <string>
using std::string;

// declarations (not strictly speaking necessary in this file)
string::size_type sumLength(const string&, const string&);
string::size_type largerLength(const string&, const string&);

// definition of these functions
string::size_type sumLength(const string &s1, const string &s2)
{
	return s1.size() + s2.size();
}

string::size_type largerLength(const string &s1, const string &s2)
{
	return (s1.size() > s2.size()) ? s1.size() : s2.size();
}

// depending on the value of its string parameter,
// getFcn returns a pointer to sumLength or to largerLength

// three ways to declare getFcn 
// 1. use decltype for the return type, 
//    remembering to add a * to indicate that getFcn returns a pointer
decltype(sumLength) *getFcn(const string &);

// use trailing return type
auto getFcn(const string&) -> string::size_type(*)(const string&, const string&);

// direct definition
string::size_type (*getFcn(const string&))(const string&, const string&);

// define getFcn
decltype(sumLength)* 
getFcn(const string &fetch)
{
	if (fetch == "sum")
		return sumLength;
	return largerLength;
}

int main()
{
	// "sum" is the argument to getFcn
	// ("hello", "world!") are arguments to the function getFcn returns
	cout << getFcn("sum")("hello", "world!") << endl;    // prints 11
	cout << getFcn("larger")("hello", "world!") << endl; // prints 6

	return 0;
}
