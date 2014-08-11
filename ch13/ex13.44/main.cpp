/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       06  JAN 2014
 *  @remark
 ***************************************************************************/
//!
//! Exercise 13.44:
//! Write a class named String that is a simplified version of the library string
//! class. Your class should have at least a default constructor and a constructor
//! that takes a pointer to a C-style string. Use an allocator to allocate memory
//! that your String class uses.
//!

#include <iostream>
#include "string.h"




int main()
{
    char ca[] = {"1234"};

    String s(ca);

    return 0;
}
