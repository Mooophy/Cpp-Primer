/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       12  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 14.13:
//! Which other arithmetic operators (Table 4.1 (p. 139)), if any, do you think
//! Sales_data ought to support? Define any you think the class should include.
//  -   *   /   -=  *=  /=
//  definitions for them should be performed after the assignment section.
//!
//! Exercise 14.14:
//! Why do you think it is more efficient to define operator+ to call operator+=
//! rather than the other way around?(P.561)
//  Discussiing on SO:
//  http://stackoverflow.com/questions/21071167/why-is-it-more-efficient-to-define-operator-to-call-operator-rather-than-the
//!
//! Exercise 14.15:
//! Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define
//! any of the arithmetic operators? If so, implement them. If not, explain
//! why not.
//  operator- is the only one to be defined. It returns an int representing the
//  sequece difference between two operands.
//!
#include <iostream>
#include <vector>

#include "Sales_data.h"
#include "block.h"


int main()
{
    std::vector<Block::Pointer> iv;

    for(unsigned i =0 ; i != 10; ++i )
    {
        static bool flag = false;
        iv.push_back(std::make_shared<bool>(flag));

        flag = !flag;
    }


    const Block add(890, iv, std::make_shared<bool>(true ));
    const Block sub(89,iv, std::make_shared<bool>(false));

    std::cout << add - sub << "\n";

    return 0;
}







