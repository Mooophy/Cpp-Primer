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

#include <algorithm>
using std::copy; using std::sort;

#include <iterator>
using std::istream_iterator; using std::ostream_iterator;

#include <vector>
using std::vector;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	vector<int> vec;
	istream_iterator<int> in(cin), eof;
	copy (in, eof, back_inserter(vec));

	sort(vec.begin(), vec.end()); // sorts vec in ``normal'' order
	vector<int> vec2(vec);        // vec2 is a copy of vec

	// sorts in reverse: puts the smallest element at the end of vec
	sort(vec.rbegin(), vec.rend());

	// prints vec
	ostream_iterator<int> out(cout, " ");
	copy(vec.begin(), vec.end(), out);    // reverse sort
	cout << endl;

	// prints vec2
	copy(vec2.begin(), vec2.end(), out);  // forward sort
	cout << endl;

	// it refers to the first element in vec
	auto it = vec.begin();

	// rev_it refers one before the first element in vec
	vector<int>::reverse_iterator rev_it(it);
	cout << *(rev_it.base()) << endl; // prints first element in vec
	
	// ways to print value at beginning of vec through it and rev_it
	cout << *it << endl;
	cout << *(rev_it.base()) << endl;  
	cout << *(rev_it - 1) << endl;

	return 0;
}
		
