/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       10  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 13.55:
//! Add an rvalue reference version of push_back to your StrBlob.
//!

#include <utility>
#include <vector>
#include <iostream>
#include <Alan.h>
#include "StrBlob.h"

int main()
{
    StrBlob s;
    s.push_back(std::string());


    return 0;
}


