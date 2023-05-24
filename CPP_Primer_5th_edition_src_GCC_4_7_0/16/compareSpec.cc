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

#include <functional>
using std::less;

#include <cstring>
using std::strcmp;

// version of compare that will be correct even if used on pointers
template <typename T> int compare(const T &v1, const T &v2)
{
	cout << "compare(T)" << "\t";

	if (less<T>()(v1, v2)) return -1;
	if (less<T>()(v2, v1)) return 1;

	return 0;
}

template<unsigned N, unsigned M> 
int compare(const char (&p1)[N], const char (&p2)[M])
{
	cout << "compare(const char arrays)" << "\t";

	return strcmp(p1, p2);
}

template<> 
int compare(const char *const& p1, const char *const& p2)
{
	cout << "compare(const char*const)" << "\t";

	return strcmp(p1, p2);
}

int main()
{
	int *p1 = new int(45);
	int *p2 = new int(42);

	// because we're comparing pointer values, the result of
    // this call may vary each time the program is run
	cout << compare(*p1, *p2) << endl;
	cout << compare(p1, p2) << endl;

	cout << strcmp("hi", "mom") << endl;
	cout << compare("hi", "mom") << endl;

	const char *cp1 = "hi", *cp2= "mom";
	cout << compare(cp1, cp2) << endl;
	
	return 0;
}
