/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       05  JAN 2014
 *  @remark
 ***************************************************************************/
//!
//! Exercise 13.39:
//! Write your own version of StrVec, including versions of reserve, capacity
//! (§ 9.4, p. 356), and resize (§ 9.3.5, p. 352).
//  When implementing the member resize, two overloaded functions was being considered.
//  They were resize(size_t n) and resize(size_t n, valueType v), respectively.
//  The former calls the default construct and the latter copy constuctor, when
//  executing alloc.construct().
//
//!  design of resize():
//!
//!  [0][1][2][3][unconstructed elements]
//!  ^           ^                       ^
//!  element     first_free              cap
//!
//!  if within [0, first_free - element),           the current size is trunctated
//!
//!  if equal to first_free - elemnt,               the function will return wiouth any operation performed
//!
//!  if within (first_free - element, +infinity)    push_back will be called to append new elements,
//!                                                 using default constructor or copy constructor depending
//!                                                 on overloaded function matching.
//!
//  discussion on SO:
//  http://stackoverflow.com/questions/20930063/is-it-nessary-to-destroy-a-string-before-constructing-it-again
//  and
//  http://stackoverflow.com/questions/20931581/is-it-a-good-practice-to-use-temporary-objects-as-arguments-when-overloading-fun
//!
//! Exercise 13.40:
//! Add a constructor that takes an initializer_list<string> to your StrVec class.
//!


#include <iostream>
#include <memory>
#include <utility>
#include <vector>

#include "strvec.h"



int main()
{
    StrVec v{"1\n","2\n","3\n","4\n","5\n"} , v2;

    v =v2;

    v.push_back("alan\n");


    std::cout << v.size() << "\n";
    std::cout << v.capacity() << "\n";
    std::cout << "=============\n";

    for(const auto &s : v )
        std::cout << s;

    return 0;
}




