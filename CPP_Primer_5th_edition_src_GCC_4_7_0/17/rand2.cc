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

#include <ctime>
using std::time;

#include <cstdlib>
using std::rand;

#include <random>
using std::default_random_engine;
using std::uniform_int_distribution;
using std::normal_distribution;

#include <iostream>
using std::cerr; using std::cout; using std::endl;

#include <vector>
using std::vector; 

#include <cstddef>
using std::size_t;

#include <algorithm>
using std::max_element; 

#include <numeric>
using std::accumulate;

#include <cmath>
using std::lround;

int main()
{
	vector<int> vals(32);     // preallocate so each element is 0 
	default_random_engine e;  // generates numbers
	uniform_int_distribution<unsigned> u(0,31); // inclusive range 
	for (size_t i = 0; i != 100; ++i)
		++vals[u(e)];         // count how often each number appears
	int m = *max_element(vals.begin(), vals.end());
	for (int i = m; i != 0; --i) {
		for (size_t j = 0; j != vals.size(); ++j)
			if (vals[j] > i-1) cout << "* ";
			else               cout << "  ";
		cout << endl;
	}

	vector<int> vals2(32);     // preallocate so each element 0 value
	default_random_engine e2;  // restart the sequence
	normal_distribution<> n(15,5); // mean 15, standard deviation 5
	for (size_t i = 0; i != 100; ++i) {
		size_t v = lround(n(e));
		if (v < vals.size())
			++vals[v];         // count how often each number appears
		else
			cout << "discarding: " << v << " ";
	}
	cout << endl;

	cout << std::accumulate(vals.begin(), vals.end(), 0) << endl;
	m = *max_element(vals.begin(), vals.end());
	for (int i = m; i != 0; --i) {
		for (size_t j = 0; j != vals.size(); ++j)
			if (vals[j] > i-1) cout << "* ";
			else               cout << "  ";
		cout << endl;
	}

	return 0;
}
