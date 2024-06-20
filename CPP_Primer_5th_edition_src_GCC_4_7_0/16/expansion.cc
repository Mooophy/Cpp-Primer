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

template <typename T>
T accum(const T &t)
{
	return t;
}

template <typename T, typename... Args>
T accum(const T &t, Args... args)
{
	return t + accum(args...);
}

// h adds its variadic arguments to the starting value of 42
int h()
{
	return 42; // starting point for the accumulation 
}

template <typename ...Args> int h(int t, Args ... args)
{
	return t + h(args...); // sum of all the values in args plus 42
}

// produces the sum of up to 4 integral values
void f(int i, int j = 0, int k = 0, int l = 0)
{
	cout << i << " + " 
	     << j << " + " 
	     << k << " + " 
	     << l << " =  "  
	     << i + j + k + l << endl;
}

// expansion: applies the pattern to each member of the pack
//            using a separator appropriate to the context
template<typename ... Args> void g(Args ... args) {
	cout << sizeof...(Args) << endl;  // number of type parameters
	cout << sizeof...(args) << endl;  // number of function parameters
	// call f passing it the arguments from args
	f(args...);                // f(a1, a2, a3, ..., an)

	// call h passing it the arguments from args
	cout << h(args...) << endl; // h(a1, a2, a3, ..., an)

	// the pattern is h(x), 
	// the expansion calls h on each argument in args
	f(h(args) ...);            // f(h(a1), h(a2), h(a3), ..., h(an))

	// args is expanded in the call to h 
	f(h(args ...));            // f(h(a1, a2, a3, ..., an2)

	// pattern adds the argument value to result from calling h(5,6,7,8) 
	f(h(5,6,7,8 ) + args ...); // f(h(5,6,7,8) + a1, h(5,6,7,8) + a2,
	                           //   h(5,6,7,8) + a3, ..., h(5,6,7,8) + an)
}

int main()
{
	cout << accum(1,2,3,4) << endl;

	g(1,2,3,4);

	return 0;
}
