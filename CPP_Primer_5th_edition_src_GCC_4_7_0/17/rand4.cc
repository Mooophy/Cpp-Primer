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
using std::uniform_real_distribution;

#include <iostream>
using std::cerr; using std::cout; using std::endl;

#include <vector>
using std::vector; 

#include <cstddef>
using std::size_t;

#include <algorithm>
using std::max_element;

int main()
{
	default_random_engine e;  // generates unsigned random integers
	// uniformly distributed from 0 to 1 inclusive
	uniform_real_distribution<double> u(0,1);
	for (size_t i = 0; i < 10; ++i)
    	cout << u(e) << " ";
	cout << endl;

	// empty <> signify we want to use the default result type
	uniform_real_distribution<> u2(0,1); // generates double by default
	default_random_engine e2;
	for (size_t i = 0; i < 10; ++i)
    	cout << u2(e2) << " ";  // should generate the same sequence 
	cout << endl;

	default_random_engine e3;
	// uniformly distributed from 0 to 9 inclusive
	uniform_int_distribution<unsigned> u3(0,9);
	for (size_t i = 0; i < 100; ++i)
    	cout << u3(e3) << ((i != 99)? " ": "");
	cout << endl;

	return 0;
}
