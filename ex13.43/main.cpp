/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       06  JAN 2014
 *  @remark
 ***************************************************************************/
//!
//! Exercise 13.43:
//! Rewrite the free member to use for_each and a lambda (§ 10.3.2, p. 388)
//! in place of the for loop to destroy the elements. Which implementation do
//! you prefer, and why?
//!

#include <iostream>
#include "strvec.h"



int main()
{
    StrVec v{"a\n","a\n","a\n","a\n"};

    v.push_back("aaa\n");

    for(const auto &s: v)
        std::cout << s;

    return 0;
}
