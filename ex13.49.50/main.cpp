/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       07--08  JAN 2014
 *  @remark
 ***************************************************************************/
//!
//! Exercise 13.49:
//! Add a move constructor and move-assignment operator to your StrVec, String,
//! and Message classes.
//!
//! Exercise 13.50:
//! Put print statements in the move operations in your String class and rerun
//! the program from exercise 13.48 in § 13.6.1 (p. 534) that used a vector<String>
//! to see when the copies are avoided.
//  Dissucssion on SO:
//  http://stackoverflow.com/questions/20967732/why-wasnt-the-move-constructor-called
//!

#include "strvec.h"
#include "string.h"
#include "message.h"
#include "folder.h"
#include <vector>
#include <iostream>

int main()
{
    std::vector<String> v;
    String s;
    for (unsigned i = 0; i != 4; ++i)
    {
        std::cout << v.capacity() << "\n";
        v.push_back(s);
    }

    return 0;
}
