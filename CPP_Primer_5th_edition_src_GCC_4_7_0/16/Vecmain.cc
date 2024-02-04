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

#include "Vec.h"

#include <string>
using std::string;

#include <iostream>
using std::cin; using std::cout; using std::endl;
using std::istream;

void print(const Vec<string> &svec)
{
	for (auto it : svec)
		cout << it << " " ;
	cout <<endl;
}

Vec<string> getVec(istream &is)
{
	Vec<string> svec;
	string s;
	while (is >> s)
		svec.push_back(s);
	return svec;
}
	
int main()
{
	Vec<string> svec = getVec(cin);
	print(svec);

	cout << "copy " << svec.size() << endl;
	auto svec2 = svec;
	print(svec2);

	cout << "assign" << endl;
	Vec<string> svec3;
	svec3 = svec2;
	print(svec3);

	Vec<string> v1, v2;
	Vec<string> getVec(istream &);
	v1 = v2;           // copy assignment
	v2 = getVec(cin);  // move assignment

	return 0;
}
