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

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::endl;


int main() 
{
	string s = "some string", s2 = "some other string";
	// equivalent ways to insert all the characters from s2 at beginning of s
	// insert iterator range before s.begin()
	s.insert(s.begin(), s2.begin(), s2.end());  
	cout << "insert iterators version:        " << s << endl;
	
	s = "some string";
	s.insert(0, s2); // insert a copy of s2 before position 0 in s
	cout << "insert string at given position: " << s << endl;

	s = "some string";
	// insert s2.size() characters from s2 starting at s2[0] before s[0]
	s.insert(0, s2, 0, s2.size());   
	cout << "insert positional version:       " << s << endl;

	
	s = "";  // s is now empty
	vector<char> c_vec(1, 'a');
	// insert characters from c_vec into s
	s.insert(s.begin(), c_vec.begin(), c_vec.end());  
	s.insert(s.size(), 5, '!'); // add five exclamation points at the end of s
	cout << s << endl;

	s.erase(s.size() - 5, 5);   // erase the last five characters from s
	cout << s << endl;

	s = "";  // s is now empty
	const char *cp = "Stately, plump Buck";
	s.assign(cp, 7);            // s == "Stately"
	cout << s << endl;
	s.insert(s.size(), cp + 7); // s == "Stately, plump Buck"
	cout << s << endl;
	
	s = "C++ Primer";  // reset s and s2
	s2 = s;            // to "C++ Primer"
	s.insert(s.size(), " 4th Ed."); // s == "C++ Primer 4th Ed."
	s2.append(" 4th Ed."); // equivalent: appends " 4th Ed." to s2; 
	cout << s << " " << s2 << endl;
	
	// two ways to replace "4th" by "5th"
	// 1. insert and erase
	s.erase(11, 3);                 // s == "C++ Primer Ed."
	s.insert(11, "5th");            // s == "C++ Primer 5th Ed."
	
	// 2. use replace
	// erase three characters starting at position 11
	//  and then insert "5th"
	s2.replace(11, 3, "5th"); // equivalent: s == s2
	
	cout << s << " " << s2 << endl;
	
	// two ways to replace "5th" by "Fifth"
	// 1. use replace if we know where the string we want to replace is
	s.replace(11, 3, "Fifth"); // s == "C++ Primer Fifth Ed."
	
	// 2. call find first to get position from which to replace
	auto pos = s2.find("5th");
	if (pos != string::npos)
		s2.replace(pos, 3, "Fifth");
	else
		cout << "something's wrong, s2 is: " << s2 << endl;
	cout << s << " " << s2 << endl;

	return 0;
}
