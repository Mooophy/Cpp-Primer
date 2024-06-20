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

#include <algorithm>
using std::find;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	string line;
	getline(cin, line);

	// find the first element in a comma-separated list
	auto comma = find(line.cbegin(), line.cend(), ',');
	cout << string(line.cbegin(), comma) << endl;
	
	// find the last element in a comma-separated list
	auto rcomma = find(line.crbegin(), line.crend(), ',');
	
	// WRONG: will generate the word in reverse order
	cout << string(line.crbegin(), rcomma) << endl;
	
	// ok: get a forward iterator and read to the end of line
	cout << string(rcomma.base(), line.cend()) << endl;

	return 0;
}
