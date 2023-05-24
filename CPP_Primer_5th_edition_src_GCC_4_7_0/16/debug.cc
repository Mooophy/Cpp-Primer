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

#include "debug_rep.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::endl;

int main()
{
	vector<int> v = {1,2,3,4,5,6,7,8,9};
	string s("hi");
	cout << debug_rep(v) << endl;
	cout << debug_rep(s) << endl; 
	cout << debug_rep("hi") << endl;
	cout << debug_rep(&v[0]) << endl;
	cout << debug_rep(&s) << endl;
	const string *sp = &s;
	cout << debug_rep(sp) << endl;

	char carr[] = "bye";            // calls pointer version if no overloads
	cout << debug_rep(carr) << endl;
	vector<string> authors = {"Proust", "Shakespeare", "Barth"};
	vector<const char*> authors2 = {"Proust", "Shakespeare", "Barth"};
	cout << debug_rep(authors) << endl;
	cout << debug_rep(authors2) << endl;
	cout << debug_rep(s) << endl;
	s += "more stuff";
	cout << debug_rep(s) << endl;
	s += "\\escape\"and quotes";
	cout << debug_rep(s) << endl;

	cout << debug_rep("hi world!") << endl; // calls debug_rep(T*)

	s = "hi";
	const char *cp = "bye";
	char arr[] = "world";

	cout << debug_rep(s) << endl;  // calls specialization debug_rep(const string&
	cout << debug_rep(cp) << endl; // calls specialization debug_rep(const char*
	cout << debug_rep(arr) << endl;// calls specialization debug_rep(char*
	cout << debug_rep(&s) << endl; // calls template debug_rep(T*)

	return 0;
}
