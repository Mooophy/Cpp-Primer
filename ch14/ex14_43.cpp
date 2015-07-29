/***************************************************************************
 *  @file       main.cpp
 *  @author     XDXX， Yue Wang
 *  @date       5/24/2015
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 14.43:
//! Using library function objects, determine whether a given int value is
//! divisible by any element in a container of ints.
//!

#include <iostream>
#include <string>
#include <functional>
#include <algorithm>

int main()
{
    auto data = { 2, 3, 4, 5 };
    int input;
    std::cin >> input;
    std::modulus<int> mod;
    auto predicator = [&](int i){ return 0 == mod(input, i); };
    auto iter = data.begin();
    for(; iter != data.end() && !(predicator(*iter)); ++iter)
            ;
    std :: cout << (iter == data.end()? "Yes!" : "No!") << std :: endl;

    return 0;
}
