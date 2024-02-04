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

#include "StrVec.h"

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;
using std::istream;

#include <fstream>
using std::ifstream;

void print(const StrVec &svec)
{
	for (auto it : svec)
		cout << it << " " ;
	cout <<endl;
}

StrVec getVec(istream &is)
{
	StrVec svec;
	string s;
	while (is >> s)
		svec.push_back(s);
	return svec;
}
	
int main()
{
	StrVec sv = {"one", "two", "three"};
	// run the string empty funciton on the first element in sv
	if (!sv[0].empty()) 
		sv[0] = "None"; // assign a new value to the first string 

	// we'll call getVec a couple of times
	// and will read the same file each time
	ifstream in("data/storyDataFile");
	StrVec svec = getVec(in);
	print(svec);
	in.close();

	cout << "copy " << svec.size() << endl;
	auto svec2 = svec;
	print(svec2);

	cout << "assign" << endl;
	StrVec svec3;
	svec3 = svec2;
	print(svec3);

	StrVec v1, v2;
	v1 = v2;                   // v2 is an lvalue; copy assignment

	in.open("data/storyDataFile");
	v2 = getVec(in);          // getVec(in) is an rvalue; move assignment
	in.close();

	StrVec vec;  // empty StrVec
	string s = "some string or another";
	vec.push_back(s);      // calls push_back(const string&)
	vec.push_back("done"); // calls push_back(string&&)

	// emplace member covered in chpater 16
	s = "the end";
	vec.emplace_back(10, 'c'); // adds cccccccccc as a new last element
	vec.emplace_back(s);  // uses the string copy constructor
	string s1 = "the beginning", s2 = s;
	vec.emplace_back(s1 + s2); // uses the move constructor

	return 0;
}

