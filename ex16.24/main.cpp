/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       03  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 16.24:
//! Add a constructor that takes two iterators to your Blob template.
//!

#include <iostream>
#include <vector>
#include <list>


#include <memory>
#include <Blob.h>


int main()
{
    std::vector<int> v = {1,2,3,4,5};
    Blob<int> b(v.begin(), v.end());
    return 0;
}

