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

#include <iostream>
using std::cout; using std::endl;

int main()
{
	string str("some string"), orig = str;
	if (!str.empty())          // make sure there's a character to print
		cout << str[0] << endl;// print the first character in str

	if (!str.empty())       // make sure there's a character in str[0]
		// assign a new value to the first character in str
		str[0] = toupper(str[0]);
	cout << str << endl;

	str = orig; // restore str to its original value

	// equivalent code using iterators instead of subscripts
	if (str.begin() != str.end()) { // make sure str is not empty
		auto it = str.begin();  // it denotes the first character in str
		*it = toupper(*it);     // make that character uppercase
	}
	cout << str << endl;

	str = orig; // restore str to its original value

	// four wasy to capitalize first word in str:
	// 1. for loop with subscripts
	for (decltype(str.size()) index = 0; 
		 index != str.size() && !isspace(str[index]); ++index) 
    		str[index] = toupper(str[index]); // capitalize the current character
	cout << str << endl;

	str = orig; // restore str to its original value

	// 2. for loop with iterators instead of subscripts
	for (auto it = str.begin(); it != str.end() && !isspace(*it); ++it)
		*it = toupper(*it); // capitalize the current character
	cout << str << endl;

	str = orig; // restore str to its original value

	// 3. while instead of a for with subscripts
	decltype(str.size()) index = 0; // subscript to look at characters in str
	while (index != str.size() && !isspace(str[index])) {
		str[index] = toupper(str[index]);  // capitalize the current character
		++index;        // advance the index to get the next character
	}
	cout << str << endl;

	// 4. while loop with iterators
	auto beg = str.begin();
	while (beg != str.end() && !isspace(*beg)) {
		*beg = toupper(*beg);
		++beg;
	}
	cout << str << endl;

	str = orig; // restore str to its original value

	// range for loop to process every character
	// first a loop to print the characters in str one character to a line
	for (auto c : str)      // for every char in str
		cout << c << endl;  // print the current character followed by a newline

	// next change every character in str
	for (auto &c : str)  // note: c is a reference 
		c = '*';         // assign a new value to the underlying char in str
	cout << str << endl;
	
	str = orig;  // restore str to its original value

	// equivalent code using traditional for loops
	// first print the characters in str
	for (decltype(str.size()) ix = 0; ix != str.size(); ++ix)
		cout << str[ix] << endl;  // print current character followd by a newline

	// next change every character in str
	for (decltype(str.size()) ix = 0; ix != str.size(); ++ix)
		str[ix] = '*';  // assigns a new value to the character in str
	cout << str << endl;

	str = orig;  // restore str to its original value

	// equivalent code using traditional for loops and iterators
	// first print the characters in str
	for (auto beg = str.begin(); beg != str.end(); ++beg)
		cout << *beg << endl;  // print current character followd by a newline

	// next change every character in str
	for (auto beg = str.begin(); beg != str.end(); ++beg)
		*beg = '*';  // assigns a new value to the character in str
	cout << str << endl;
	return 0;
}
