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

#include <ctime>
using std::time;

#include <cstdlib>
using std::rand;

#include <random>
using std::default_random_engine;
using std::normal_distribution;

#include <iostream>
using std::cerr; using std::cout; using std::endl;

#include <vector>
using std::vector; 

#include <algorithm>
using std::max_element; 

#include <numeric>
using std::accumulate;

#include <cmath>
using std::lround;

#include <cstddef>
using std::size_t;

int main()
{
	default_random_engine e;        // generates random integers
	normal_distribution<> n(4,1.5); // mean 4, standard deviation 1.5
	vector<unsigned> vals(9);       // nine elements each 0

	for (size_t i = 0; i != 200; ++i) {
		unsigned v = lround(n(e));  // round to the nearest integer
		if (v < vals.size())        // if this result is in range 
			++vals[v];              // count how often each number appears
	}

	int sum = accumulate(vals.begin(), vals.end(), 0);

	if (sum != 200)
		cout << "discarded " << 200 - sum << " results" << endl;

	for (size_t j = 0; j != vals.size(); ++j)
		cout << j << ": " << string(vals[j], '*') << endl;

	return 0;
}
