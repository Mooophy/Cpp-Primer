/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       07  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 16.41:
//! Write a version of sum with a return type that is guaranteed to be large
//! enough to hold the result of the addition.
//!


#include <iostream>
#include <vector>
#include <string>

template<typename T>
auto sum(T lhs, T rhs) -> decltype( lhs + rhs)
{
    return lhs + rhs;
}

int main()
{
    auto s= sum(123456789123456789123456789123456789123456789, 123456789123456789123456789123456789123456789) ;
    ;
    ;
}
