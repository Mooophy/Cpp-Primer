/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       12  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 14.9:
//! Define an input operator for your Sales_data class.
//!
//! Exercise 14.10:
//! Describe the behavior of the Sales_data input operator if given the following
//! input:
//!     (a) 0-201-99999-9 10 24.95
//          -- correct format.
//!
//!     (b) 10 24.95 0-210-99999-9
//          -- ilegal input.But 0-210-99999-9 will be converted to a float stored in this
//             object.As a result, the data inside will be a wrong one.
//!
//! Exercise 14.11:
//! What, if anything, is wrong with the following Sales_data input operator?
//! What would happen if we gave this operator the data in the previous exercise?
//  no input check. nothing special.
//
#include <iostream>
#include "Sales_data.h"

int main()
{

    Sales_data s;
    std::cin >> s;
    std::cout << s;

    return 0;
}







