/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       02  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 16.14:
//! Write a Screen class template that uses nontype parameters to define the
//! height and width of the Screen.
//!
//! Exercise 16.15:
//! Implement input and output operators for your Screen template.
//! Which, if any, friends are necessary in class Screen to make the input and
//! output operators work? Explain why each friend declaration, if any, was
//! needed.
//!

#include"Screen.h"

int main()
{
    Screen<10,5> scr;


    return 0;
}
