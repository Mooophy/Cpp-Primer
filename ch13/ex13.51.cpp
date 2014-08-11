/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       9  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 13.51:
//! Although unique_ptrs cannot be copied, in § 12.1.5 (p. 471) we wrote a clone
//! function that returned a unique_ptr by value. Explain why that function is
//! legal and how it works.
//!

#include <iostream>
#include <memory>
#include <utility>

std::unique_ptr<int> clone(int p)
{
    // ok: explicitly create a unique_ptr<int> from int*
    return std::unique_ptr<int>(new int(p));
}

std::unique_ptr<int> clone_ver2(int p)
{
    std::unique_ptr<int> ret(new int (p));
    // . . .
    return ret;
}
int main (){}
//!
//   As it goes in the textbook, functions that return a nonreference type, along with
//   the arithmetic, relational, bitwise, and postfix increment/decrement operators, all
//   yield rvalues. Hence, the functions above return rvalue on which move constructor
//   can be called on to steal the value inside.
