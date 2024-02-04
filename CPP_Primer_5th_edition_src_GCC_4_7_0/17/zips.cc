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

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

#include <regex>
using std::regex; using std::sregex_iterator; using std::smatch;

int main()
{
	string zip = "\\d{5}-\\d{4}|\\d{5}";

	string test_str = "908.647.4306 164 gates, 07933 07933-1257";
	regex r(zip);  // a regex to find the parts in our pattern
	smatch results;

	if (regex_search(test_str, results, r))
		cout << results.str() << endl;
	
	sregex_iterator it(test_str.begin(), test_str.end(), r);
	sregex_iterator end_it;         // end iterator
	while (it != end_it) {
		cout << it->str() << endl;  // print current match
		++it;                       // advance iterator for next search
	}

	return 0;
}
#else

// do nothing
int main() { return 0; }

#endif

