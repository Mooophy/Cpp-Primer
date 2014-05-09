/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       10  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 14.6:
//! Define an output operator for your Sales_data class.
//!
//! Exercise 14.7:
//! Define an output operator for you String class you wrote for the exercises
//! in § 13.5 (p. 531).
//!

#include "string.h"
#include <iostream>
#include <string>

#include <vector>


int main()
{
    std::vector<int> v = {1,2,3,4,5,6,7,8,9};

    String s("123456999999999999999");
    std::cout << s <<"\n";



    return 0;
}



