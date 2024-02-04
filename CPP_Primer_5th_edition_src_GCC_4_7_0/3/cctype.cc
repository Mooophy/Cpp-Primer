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

#include <cctype>
using std::isupper; using std::toupper;
using std::islower; using std::tolower;
using std::isalpha; using std::isspace;

#include <iostream>
using std::cout; using std::endl;

int main()
{
	string s("Hello World!!!");
	// punct_cnt has the same type that s.size returns
	decltype(s.size()) punct_cnt = 0; 
	
	// count the number of punctuation characters in s
	for (auto c : s)         // for every char in s
		if (ispunct(c))      // if the character is punctuation
			++punct_cnt;     // increment the punctuation counter
	
	cout << punct_cnt 
	     << " punctuation characters in " << s << endl;
	
	// convert s to uppercase
	string orig = s;
	for (auto &c : s)   // for every char in s (note: c is a reference)
		// c is a reference, so this assignment changes the char in s
		c = toupper(c);
	cout << s << endl;
	
	// convert first word in s to uppercase
	s = orig;  // restore s to original case
	decltype(s.size()) index = 0;

	// process characters in s until we run out of characters 
	// or we hit a whitespace
	while (index != s.size() && !isspace(s[index])) {

	    // s[index] returns a reference so we can change 
		// the underlying character
		s[index] = toupper(s[index]);

		// increment the index to look at the next character 
		// on the next iteration
		++index; 
	}
	cout << s << endl;
	
	return 0;
}
