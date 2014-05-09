/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       07  JAN 2014
 *  @remark
 ***************************************************************************/
//!
//! Exercise 13.47:
//! Give the copy constructor and copy-assignment operator in your String class
//! from exercise 13.44 in § 13.5 (p. 531) a statement that prints a message
//! each time the function is executed.
//!
//! Exercise 13.48:
//! Define a vector<String> and call push_back several times on that vector.
//! Run your program and see how often Strings are copied.
//  times = 2i;
//!
#include "string.h"
#include <vector>

int main()
{
    std::vector<String> v;

    String s("sssssss");

    for (unsigned i = 0; i != 3; ++i)
        v.push_back(s);


    return 0;
}
