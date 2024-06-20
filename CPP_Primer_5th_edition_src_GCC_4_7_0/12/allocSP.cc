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

#include <memory>
using std::make_shared; using std::shared_ptr;

#include <iostream>
using std::istream; using std::ostream; 
using std::cin; using std::cout; using std::endl;

#include "Foo.h"

// factory returns a shared_ptr to a dynamically allocated object 
shared_ptr<Foo> factory(T arg)
{
	// process arg as appropriate
	// shared_ptr will take care of deleting this memory
	return make_shared<Foo>(arg); 
}

shared_ptr<Foo> use_factory(T arg)
{
	shared_ptr<Foo> p = factory(arg);
	print(cout, *p);
	cout << endl;
	// use p
	return p;  // reference count is incremented when we return p
} 

int main()
{
	T arg;
	while (cin >> arg)
		use_factory(arg);
}

