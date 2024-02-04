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

#include <algorithm>
using std::max_element;

#include <cstddef>
using std::size_t;

int main()
{
	default_random_engine e;  // generates random unsigned integers
	for (size_t i = 0; i < 10; ++i)
		// e() "calls" the object to produce the next random number
		cout << e() << " ";
	cout << endl;

	// uniformly distributed from 0 to 9 inclusive
	uniform_int_distribution<unsigned> u(0,9);
	default_random_engine e2;  
	for (size_t i = 0; i < 10; ++i)
		// u uses e as a source of numbers
		// each call returns a uniformly distributed value 
		// in the specified range
    	cout << u(e2) << " ";
	cout << endl;

	default_random_engine e3;  
	// generates normally distributed doubles 
	// with mean 100, standard deviation 15
	normal_distribution<> n(100,15);  
	for (size_t i = 0; i < 10; ++i)
    	cout << n(e3) << " ";
	cout << endl;

	// bad, but common way to generate random numbers in a given range
	for (size_t i = 0; i < 10; ++i)
		// r will be a between 0 and 9, but randomness is compromised
		cout << rand()%10 << " ";
	cout << endl;

	default_random_engine e4;
	// uniformly distributed from 0 to 9 inclusive
	uniform_int_distribution<unsigned> u2(0,9);
	for (size_t i = 0; i < 10; ++i)
    	cout << u2(e4) << " ";
	cout << endl;

	// seeding the engine causes it to generate different numbers 
	// on different executions
	default_random_engine e5(time(0));  
	for (size_t i = 0; i < 10; ++i)
    	cout << u2(e5) << " ";
	cout << endl;

    // assuming shorts have 16 bits
    uniform_int_distribution<short> us1;     // values from 0 to 32767
    uniform_int_distribution<short> us2(42); // values from 42 to 32767
    cout << "min: " << us1.min() << " max: " << us1.max() << endl;
    cout << "min: " << us2.min() << " max: " << us2.max() << endl;

    default_random_engine e6;
    cout << "min: " << e6.min() << " max: " << e6.max() << endl;

	return 0;
}
