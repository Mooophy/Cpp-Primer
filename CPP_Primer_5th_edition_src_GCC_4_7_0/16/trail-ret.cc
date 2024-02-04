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

#include <iostream>
using std::cout; using std::endl;

#include <type_traits>
using std::remove_reference;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "Blob.h"

// auto as function return type indicates we're using a trailing return type
// function that returns a reference to an element in the range
template <typename It>
auto reffcn(It beg, It end) -> decltype(*beg)
{
    // process the range
    return *beg;  // return a copy of an element from the range
}

// function that returns an element in the range by value
// must use typename to use a type member of a template parameter
template <typename It>
auto valfcn(It beg, It end) -> 
	typename remove_reference<decltype(*beg)>::type
{
    // process the range
    return *beg;  // return a copy of an element from the range
}

int main()
{
	vector<int> vi = {1,2,3,4,5};
	Blob<string> ca = { "hi", "bye" };

	auto &i = reffcn(vi.begin(), vi.end()); // reffcn should return int&
	auto &s = reffcn(ca.begin(), ca.end()); // reffcn should return string&

	vi = {1,2,3,4};
	for (auto i : vi) cout << i << " "; cout << endl;
	auto &ref = reffcn(vi.begin(), vi.end());  // ref is int&
	ref = 5; // changes the value of *beg to which ref refers
	for (auto i : vi) cout << i << " "; cout << endl;

	auto val = valfcn(vi.begin(), vi.end()); // val is int
	cout << val << endl;  // will print 5
	
	return 0;
}

