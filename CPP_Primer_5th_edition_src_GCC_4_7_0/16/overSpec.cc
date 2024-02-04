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

#include <cstring>
using std::strcmp;

#include <iostream>
using std::cout; using std::endl;

// first version; can compare any two types
template <typename T> int compare(const T&, const T&);

// second version to handle string literals 
template<size_t N, size_t M>
int compare(const char (&)[N], const char (&)[M]);

// specialized verson of the first template, handles character arrays
template <>
int compare(const char* const &, const char* const &);

template <typename T> int compare(const T& v1, const T& v2)
{
cout << "base template" << endl;
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

template<size_t N, size_t M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
cout << "array template" << endl;
	return strcmp(p1, p2);
}


// special version of compare to handle pointers to character arrays
template <>
int compare(const char* const &p1, const char* const &p2)
{
cout << "specialized template" << endl;
    return strcmp(p1, p2);
}

int main()
{
	const char *p1 = "hi", *p2 = "mom";
	compare(p1, p2);      // calls the first template
	compare("hi", "mom"); // calls the template with two nontype parameters
}
