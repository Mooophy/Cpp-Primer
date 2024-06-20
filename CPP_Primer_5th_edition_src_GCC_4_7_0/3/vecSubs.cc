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
using std::cin; using std::cout; using std::endl;

int main()
{
	vector<int> v = {0,1,2,3,4,5,6,7,8,9};
	auto sz = v.size(); 
	decltype(sz) i = 0;
	// duplicate contents of v onto the back of v
	while (i != sz) {
		v.push_back(*v.begin() + i);
		++i;
	}
	// prints 0...9 0...9
	for (auto it : v)
		cout << it << " ";
	cout << endl;
	
	// alternative way to stop when we get to the original last element
	vector<int> alt_v = {0,1,2,3,4,5,6,7,8,9}; // vector with values 0...9
	for (decltype(alt_v.size()) i = 0, sz = alt_v.size(); i != sz; ++i)
		alt_v.push_back(alt_v[i]);

	// prints 0...9 0...9
	for (auto it : alt_v)
		cout << it << " ";
	cout << endl;

	vector<int> v2 = {0,1,2,3,4,5,6,7,8,9}; // vector with values 0 ... 9
	decltype(v2.size()) ix = 0;   // we'll use ix to index the vector

	// set the elements with values less than 5 to 0
	while (ix != v2.size() && v2[ix] < 5) {
		v2[ix] = 0; // changes the value of the element in v
		++ix;       // increment the index so the next iteration fetches the next element
	}

	// print the elements using subscripts
	for (unsigned i = 0; i != v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;

	// equivalent but using iterators
	vector<int> alt_v2 = {0,1,2,3,4,5,6,7,8,9}; // vector with values 0...9
	// set the elements to 0 up to the first one that is 5 or greater
	auto it = alt_v2.begin();
	while (it != alt_v2.end() && *it < 5) {
		*it = 0;   // changes the value of the element in alt_v2
		++it;      // advance the iterator to denote the next element
	}
	for (auto it = alt_v2.begin(); // it denotes first element in alt_v2
	          it != alt_v2.end();  // so long as it denotes an element
	          ++it)          // increment the iterator to next element
		cout << *it << " ";  // print element denoted by it from alt_v2
	cout << endl;

	return 0;
}
