/***************************************************************************
 *  @file       main.cpp
 *  @author     XDXX， Yue Wang
 *  @date       5/24/2015
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 14.43:
// Using library function objects, determine whether a given int value is
// divisible by any element in a container of ints.
//

#include <iostream>
#include <string>
#include <functional>
#include <algorithm>

int main()
{
    auto data = { 2, 3, 4, 5 };
    int input;
    std::cin >> input;
    auto p = std::find_if_not(data.begin(), data.end(), std::bind(std::modulus<int>(), input, _1));
    std::cout << (p != data.end() ? "Yes!" : "No!") << std::endl;
    return 0;
}
