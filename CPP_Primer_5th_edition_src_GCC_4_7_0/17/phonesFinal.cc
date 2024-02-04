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
using std::regex_error;
using std::regex_constants::format_no_copy;

int main()
{
	// phone has 10 digits, optional parentheses around the area code
	// components are separated by an optional space, ',' or '-'
	string phone = "\\(?\\d{3}\\)?[-. ]?\\d{3}[-. ]?\\d{4}";

	// parentheses indicate subexpressions;
	// our overall expression has 7 subexpressions: 
	//     ( ddd ) space ddd - dddd
	// the subexpressions 1, 3, 4, and 6 are optional
	// the subexpressions 2, 5, and 7 hold the digits of the number
	phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	regex r(phone);  // a regex to find our pattern
	smatch m;        // a match object for the results
	string s;

	// generate just the phone numbers:  use a new format string
	string fmt = "$2.$5.$7"; // reformat numbers to ddd.ddd.dddd
	string fmt2 = "$2.$5.$7 "; // adds space at the end as a separator

	// read each record from the input file
	while (getline(cin, s))
	{
		cout << regex_replace(s, r, fmt) << endl;

		// tell regex_replace to copy only the text that it replaces
		cout << regex_replace(s, r, fmt2, format_no_copy) << endl;
	}

	return 0;
}
#else

// do nothing
int main() { return 0; }

#endif

