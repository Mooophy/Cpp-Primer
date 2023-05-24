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

#include <iterator>
using std::begin; using std::end;

#include <cstddef>
using std::size_t; 

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	int ia[] = {0,1,2,3,4,5,6,7,8,9};

	int *p = ia; // p points to the first element in ia
	++p;           // p points to ia[1]

	int *e = &ia[10]; // pointer just past the last element in ia
	for (int *b = ia; b != e; ++b)
		cout << *b << " "; // print the elements in ia
	cout << endl;

	const size_t sz = 10;
	int arr[sz];  // array of 10 ints

	for (auto &n : arr) // for each element in arr
		cin >> n;  // read values from the standard input

	for (auto i : arr)
		cout << i << " ";
	cout << endl;

	// pbeg points to the first and 
	// pend points just past the last element in arr
	int *pbeg = begin(arr),  *pend = end(arr);

	// find the first negative element, 
	// stopping if we've seen all the elements
	while (pbeg != pend && *pbeg >= 0)
		++pbeg;
	if (pbeg == pend)
		cout << "no negative elements in arr" << endl;
	else
		cout << "first negative number was " << *pbeg << endl;
	return 0;
}

