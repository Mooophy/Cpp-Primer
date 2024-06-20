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

#include "Version_test.h"

// if the regular expression library isn't support, do nothing
#ifdef REGEX

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

#include <regex>
using std::regex; using std::sregex_iterator; using std::smatch;

void checkPattern(const regex &r, const string &s)
{
	smatch results;
	if (regex_search(s, results, r))
		cout << results.str() << endl;
	else 
		cout << "no match for " << s << endl;
}

int main()
{
	// phone has 10 digits, optional parentheses around the area code
	// components are separated by an optional space, ',' or '-'
	string pattern = "\\(?\\d{3}\\)?[-. ]?\\d{3}[-. ]?\\d{4}";
	regex r(pattern);  // a regex to match our pattern

	// some numbers to try to match
	string mtch1 = "(908) 555-0181";
	string mtch2 = "(908)555-0182";
	string mtch3 = "908 555-0183";
	string mtch4 = "908.555-0184";
	string mtch5 = "9085550185";

	smatch results;
	checkPattern(r, mtch1);
	checkPattern(r, mtch2);
	checkPattern(r, mtch3);
	checkPattern(r, mtch4);
	checkPattern(r, mtch5);

	string s;
	while (getline(cin, s)) 
	{
		checkPattern(r, s);
	}
	
	return 0;
}

#else

// do nothing
int main() { return 0; }

#endif

