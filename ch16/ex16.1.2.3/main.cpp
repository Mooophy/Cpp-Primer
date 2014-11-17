/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       02  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 16.1:
//! Define instantiation.
//  When the compiler instantiates a template, it creates a new “instance” of
//  the template using the actual template argument(s) in place of the
//  corresponding template parameter(s).
//!
//! Exercise 16.2:
//! Write and test your own versions of the compare functions.
//!
//! Exercise 16.3:
//! Call your compare function on two Sales_data objects to see how your compiler
//! handles errors during instantiation.
//  error: no match for 'operator<' (operand types are 'const Sales_data' and
//  'const Sales_data')
//!
//!
//!

#include <iostream>
using std::cout;
using std::endl;

#include<vector>
using std::vector;

class Sales_data
{

};

template<typename T>
int compare(const T& lhs, const T& rhs)
{
    if(lhs < rhs) return -1;
    if(rhs < lhs) return  1;
    return 0;
}

int main()
{
    //! Test compare function
    cout << compare(1, 0) << endl;

    vector<int> vec1{1, 2, 3}, vec2{4, 5, 6};
    cout << compare(vec1, vec2) << endl;

    return 0;
}

