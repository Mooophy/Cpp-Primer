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

#include <cstring>
using std::strcmp;

#include <iostream>
using std::cout; using std::endl;

#include "compare.h"

int main()
{
    // instantiates int compare(const int&, const int&)
    cout << compare(1, 0) << endl;       // T is int

    // instantiates int compare(const vector<int>&, const vector<int>&)
    vector<int> vec1{1, 2, 3}, vec2{4, 5, 6};
    cout << compare(vec1, vec2) << endl; // T is vector<int>

    long l1, l2;
    int i1, i2;
    compare(i1, i2);      // instantiate compare(int, int)
    compare(l1, l2);      // instantiate compare(long, long)
	compare<int>(i1, l2); // uses compare(int, int)
	compare<long>(i1, l2);// uses compare(long, long)

    const char *cp1 = "hi", *cp2 = "world";
    compare(cp1, cp2);          // calls the specialization
    compare<string>(cp1, cp2);  // converts arguments to string

    return 0;
}

