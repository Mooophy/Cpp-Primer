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

#include <iostream>
using std::cout; using std::endl;

// declarations before definitions
template <typename T> void f(T);
template <typename T> void f(const T*);

template <typename T> void g(T);
template <typename T> void g(T*);

// definitions
template <typename T> void f(T) { cout << "f(T)" << endl; }
template <typename T> void f(const T*) 
{ cout << "f(const T*)" << endl; }

template <typename T> void g(T) { cout << "g(T)" << endl; }
template <typename T> void g(T*) { cout << "g(T*)" << endl; }

int main()
{
	int i = 42;
	f(i);  // calls f(T), f(const T*) isn't viable
	
	f(&i); // calls f(T), which is an exact match, 
	       // f(const T*) requires a conversion 
	
	g(i);  // calls g(T), g(T*) isn't viable
	g(&i); // calls g(T*), both templates are viable, 
	       // but g(T*) is more specialized 
	
	int *p = &i;
	const int ci = 0, *p2 = &ci;
	g(42);   g(p);   g(ci);   g(p2);
	f(42);   f(p);   f(ci);   f(p2);

	return 0;
}
