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

#include <cstddef>
using std::size_t;

#include <ctime>
using std::time;

#include <cstdlib>
using std::rand;

#include <random>
using std::default_random_engine;
using std::uniform_int_distribution;

#include <iostream>
using std::cerr; using std::cout; using std::endl;

#include <vector>
using std::vector;

// almost surely the wrong way to generate a vector of random integers
// output from this function will be the same 100 numbers on every call!
vector<unsigned> bad_randVec()
{
	default_random_engine e;    
	uniform_int_distribution<unsigned> u(0,9);
	vector<unsigned> ret;
	for (size_t i = 0; i < 100; ++i)
    	ret.push_back(u(e));
	return ret;
}

// returns a vector of 100 uniformly distributed random numbers
vector<unsigned> good_randVec()
{
	// because engines and distributions retain state, they usually should be
	// defined as static so that new numbers are generated on each call
	static default_random_engine e;    
	static uniform_int_distribution<unsigned> u(0,9);
	vector<unsigned> ret;
	for (size_t i = 0; i < 100; ++i)
    	ret.push_back(u(e));
	return ret;
}

int main()
{
	vector<unsigned> v1(bad_randVec());
	vector<unsigned> v2(bad_randVec());

	// will print equal
	cout << ((v1 == v2) ? "equal" : "not equal") << endl;

	// very unlikely to print equal
	if (good_randVec() == good_randVec())
		cout << "equal!" << endl;
	else
		cout << "not equal" << endl;
}
