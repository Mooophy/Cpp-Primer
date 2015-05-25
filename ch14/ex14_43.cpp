/***************************************************************************
 *  @file       main.cpp
 *  @author     XDXX
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
#include <vector>
#include <string>
#include <functional>

int main()
{
    std::vector<int> vec = {1, 2, 3, 4};
    std::modulus<int> mod;
    int num;
    std::cin >> num;
    std::string result = "yes";
    for (const auto i : vec) {
        if (mod(num, i)) {
            result = "no";
            break;
        }
    }

    std::cout << result << std::endl;
    return 0;
}