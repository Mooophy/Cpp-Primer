/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       19  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/

//!
//! Exercise 14.35:
//! Write a class like PrintString that reads a line of input from an istream
//! and returns a string representing what was read. If the read fails, return
//! the empty string.
//!

#ifndef INPUTSTRING_H
#define INPUTSTRING_H

#include <iostream>
#include <istream>
#include <string>

class InputString
{
public:
    InputString(std::istream& i = std::cin) :
        is(i)
    {}

    std::string operator()(void) const
    {
        std::string ret;
        std::getline(is, ret);

        if(is)  return ret;
        else    return "";
    }

private:
    std::istream& is;
};

#endif // INPUTSTRING_H
