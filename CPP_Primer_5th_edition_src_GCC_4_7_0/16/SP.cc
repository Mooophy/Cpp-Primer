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

#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <memory>
using std::unique_ptr; using std::shared_ptr;

// function-object class that calls delete on a given pointer
#include "DebugDelete.h"

int main()
{
	double* p = new double;
	// an object that can act like a delete expression
	DebugDelete d("plain pointer");
	d(p); // calls DebugDelete::operator()(double*), which deletes p

	int* ip = new int;
	// calls operator()(int*) on a temporary DebugDelete object
	DebugDelete("plain pointer")(ip); 

	// destroying the the object to which upi points
	// instantiates DebugDelete::operator()<int>(int *) 
	unique_ptr<int, DebugDelete> upi(new int, DebugDelete()); 

	// destroying the the object to which ups points
	// instantiates DebugDelete::operator()<string>(string*)
	unique_ptr<string, DebugDelete> ups(new string, DebugDelete()); 

	// illustrate other types using DebugDelete as their deleter
	shared_ptr<int> sp1(new int(42), DebugDelete("shared_ptr"));

	return 0;
}

