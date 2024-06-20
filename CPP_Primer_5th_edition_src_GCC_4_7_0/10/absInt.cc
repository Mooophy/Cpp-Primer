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

#include <vector>
using std::vector;

#include <iterator>
using std::inserter;

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <algorithm>
using std::for_each; using std::transform;

int main() {
	vector<int> vi;
	int i;
	while (cin >> i)
		vi.push_back(i);
	// pass a lambda to for_each to print each element in vi
	for_each(vi.begin(), vi.end(), [](int i) { cout << i << " "; });
	cout << endl;

	vector<int> orig = vi; // save original data in vi

	// replace negative values by their absolute value
	transform(vi.begin(), vi.end(), vi.begin(),
	          [](int i) { return i < 0 ? -i : i; });
	// print the elements now in vi
	for_each(vi.begin(), vi.end(), [](int i) { cout << i << " "; });
	cout << endl;

	vi = orig;  // start afresh
	// use a lambda with a specified return type to transform vi
	transform(vi.begin(), vi.end(), vi.begin(),
	          [](int i) -> int 
	          { if (i < 0) return -i; else return i; });
	// print the elements now in vi
	for_each(vi.begin(), vi.end(), [](int i) { cout << i << " "; });
	cout << endl;

    return 0;
}
