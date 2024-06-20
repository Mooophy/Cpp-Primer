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

#include <utility>
#include <iostream>
using std::cout; using std::endl;

// template that takes a callable and two parameters 
// and calls the given callable with the parameters ``flipped'' 
template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2)
{
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void f(int v1, int &v2)  // note v2 is a reference
{
	cout << v1 << " " << ++v2 << endl;
}

void g(int &&i, int& j)
{
	cout << i << " " << j << endl;
}

// flip1 is an incomplete implementation: top-level const and references are lost
template <typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2)
{
	f(t2, t1);
} 

template <typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2)
{
	f(t2, t1);
}

int main()
{
	int i = 0, j = 0, k = 0, l = 0;
	cout << i << " " << j << " " << k << " " << l << endl;

	f(42, i);        // f changes its argument i
	flip1(f, j, 42); // f called through flip1 leaves j unchanged
	flip2(f, k, 42); // ok: k is changed
	g(1, i);
	flip(g, i, 42);  // ok: rvalue-ness of the third argument is preserved
	cout << i << " " << j << " " << k << " " << l << endl;

	return 0;
}
