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
using std::cout; using std::endl;

#include <string>
using std::string;

#include <regex>
using std::regex; using std::sregex_iterator; using std::smatch;

int main()
{
	// find the characters ei that follow a character other than c
	string pattern("[^c]ei");  
	// we want the whole word in which our pattern appears
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*"; 

	regex r(pattern); // construct a regex to find pattern
	smatch results;   // define an object to hold the results of a search

	// define a string that has text that does and doesn't match pattern
	string test_str = "receipt freind theif receive";  

	// use r to find a match to pattern in test_str
	if (regex_search(test_str, results, r)) // if there is a match
		cout << results.str() << endl;      // print the matching word

	sregex_iterator it(test_str.begin(), test_str.end(), r);
	sregex_iterator end_it;   // end iterator
	for ( ; it != end_it; ++it)
		cout << it->str() << endl;     // print current match

	// alternative way to obtain all the matches in a given string
	auto it2 = test_str.cbegin();
	while (it2 != test_str.cend() && 
	       regex_search(it2, test_str.cend(), results, r)) {
		cout << results.str() << endl;
		// reposition the iterator past any nonmatched part
		// of the string plus the size of this match
		it2 += results.prefix().length() + results.length();
	
	}

	return 0;
}
#else

// do nothing
int main() { return 0; }

#endif

