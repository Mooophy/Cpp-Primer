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

#include <string>
using std::string;

#include <algorithm>
using std::fill; using std::fill_n;

#include <numeric>
using std::accumulate;

#include <iterator>
using std::back_inserter;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	vector<int> vec(10);              // default initialized to 0
	fill(vec.begin(), vec.end(), 1);  // reset each element to 1

	// sum the elements in vec starting the summation with the value 0
	int sum = accumulate(vec.cbegin(), vec.cend(), 0);
	cout << sum << endl;
	
	// set a subsequence of the container to 10
	fill(vec.begin(), vec.begin() + vec.size()/2, 10);
	cout << accumulate(vec.begin(), vec.end(), 0) << endl;

	// reset the same subsequence to 0
	fill_n(vec.begin(), vec.size()/2, 0);
	cout << accumulate(vec.begin(), vec.end(), 0) << endl;

	// create 10 elements on the end of vec each with the value 42
	fill_n(back_inserter(vec), 10, 42);
	cout << accumulate(vec.begin(), vec.end(), 0) << endl;
	
	// concatenate elements in a vector of strings and store in sum 
	vector<string> v;
	string s;
	while (cin >> s)
		v.push_back(s);
	string concat = accumulate(v.cbegin(), v.cend(), string(""));
	cout << concat << endl;
	
	return 0;
}

