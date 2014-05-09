/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       20  Jan 2014
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
#include <algorithm>
#include <string>
#include <fstream>
#include <stack>


int main()
{
    std::vector<int> v = {5,7,8,9};
    std::modulus<int> mod;

    int num;
    while(std::cin >> num)
    {
        std::string ret = "no\n";
        for (auto i : v)
        {
            if (! mod(num,i))
            {
                ret = "yes!\n";
                break;
            }
        }
        std::cout << ret;
    }

    return 0;
}







