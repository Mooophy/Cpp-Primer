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

#include <cassert>
// assert is a preprocessor macro and therefore not in std
// hence we need to include cassert header, 
// but no using declaration for assert 

#include <string> 
using std::string;

#include <iostream> 
using std::endl; using std::cerr; using std::cin;

#include <cstddef>
using std::size_t;

void print(const int ia[], size_t size)
{
#ifndef NDEBUG
// __func__ is a local static defined by the compiler that holds the name of this function
cerr << __func__ << ": array size is " << size << endl;
#endif
// . . .
}

int main()
{
    string word = "foo";
    const string::size_type threshold = 5;
    if (word.size() < threshold) 
        cerr << "Error: " << __FILE__
             << " : in function " << __func__ 
             << " at line " << __LINE__ << endl
             << "       Compiled on " << __DATE__ 
             << " at " << __TIME__ << endl
             << "       Word read was \"" << word 
             << "\":  Length too short" << endl;
    word = "something longer than five chars";
    assert(word.size() > threshold);

    return 0;
}
