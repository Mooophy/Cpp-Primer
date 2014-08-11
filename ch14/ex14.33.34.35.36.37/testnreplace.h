/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       19  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 14.37:
//! Write a class that tests whether two values are equal. Use that object
//! and the library algorithms to write a program to replace all instances of
//! a given value in a sequence.
//!

#ifndef TESTNREPLACE_H
#define TESTNREPLACE_H

#include <string>

//! a functor that tests whether two values are equal.
//! can be used with library algorithms to write a program to replace all
//! instances of a given value in a sequence.
class TestNreplace
{
public:
    TestNreplace(const std::string& r = "", const std::string& n = "") :
        reference(r), newValue(n)
    {}

    //! operator ()
    void operator()(std::string& item)
    {
        if (item == reference)  item = newValue;
    }

private:
    std::string reference ;
    std::string newValue  ;

};

#endif // TESTNREPLACE_H
