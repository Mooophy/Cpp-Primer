/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       11  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 14.8:
//! Define an output operator for the class you chose in exercise 7.40 from
//! § 7.5.1 (p. 291).
//!
//! Exercise 7.40:
//! Choose one of the following abstractions (or an abstraction of your own
//! choosing). Determine what data are needed in the class. Provide an appropriate
//! set of constructors. Explain your decisions.
//!

#include <iostream>
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


    const Block add(8, iv, std::make_shared<bool>(true));


    std::cout << add;
    return 0;
}







