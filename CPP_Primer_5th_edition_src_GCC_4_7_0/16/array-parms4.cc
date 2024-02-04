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

#include <cstddef>
using std::size_t;

// when we call print the compiler will instantiate a version of print
// with T replaced by the argument's element type, and N by that array's dimension
template <typename T, size_t N>
void print(T (&arr)[N])
{
    for (auto elem : arr)
        cout << elem << endl;
}

int main()
{
	int a1[] = {0,1,2,3,4,5,6,7,8,9};
	int a2[] = {1,3,5};
	string a3[4];

	print(a1);  // instantiates print(int (&arr)[10])

	print(a2);  // instantiates print(int (&arr)[3])

	print(a3);  // instantiates print(string (&arr)[42])

	return 0;
}
