/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       19  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 14.33:
//! How many operands may an overloaded function-call operator take?
//  An overloaded operator function has the same number of parameters as the
//  operator has operands. Hence the maxmium value should be around 256.
//  Discussion on SO:
//  http://stackoverflow.com/questions/21211889/how-many-operands-may-an-overloaded-function-call-operator-take
//!
//! Exercise 14.34:
//! Define a function-object class to perform an if-then-else operation:
//! The call operator for this class should take three parameters. It should
//! test its first parameter and if that test succeeds, it should return its
//! second parameter; otherwise, it should return its third parameter.
//!
//! Exercise 14.35:
//! Write a class like PrintString that reads a line of input from an istream
//! and returns a string representing what was read. If the read fails, return
//! the empty string.
//!
//! Exercise 14.36:
//! Use the class from the previous exercise to read the standard input, storing
//! each line as an element in a vector.
//!
//! Exercise 14.37:
//! Write a class that tests whether two values are equal. Use that object and the
//! library algorithms to write a program to replace all instances of a given value
//! in a sequence.
//!

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "test.h"
#include "inputstring.h"
#include "testnreplace.h"

int main()
{
    //! ex14.36
    /*
    InputString is;
    std::vector<std::string> v;

    for (unsigned u = 0; u != 5; ++u)
        v.push_back(is());

    for(const auto s : v)
        std::cout << s << "\n";
    */

    //! ex14.37
    std::vector<std::string>
            v = {"alan","alan","alan","alan","wang","wang","wang","wang"};

    for(const auto &s : v)
        std::cout << s << "\n";



    std::for_each(v.begin(), v.end(), TestNreplace("alan","moophy"));
    //!                               ~~~~~~~~~~~~~^^^^^^~^^^^^^^^~
    //! @note   The items to which iterators pont, string in this case, are implicitly passed
    //!         as argument to the function-call operator's parameter. In this case, the type
    //!         of the parameter is non-const string&, whichs ensure the functor is able to
    //!         replace the old value with new value as required.



    std::cout << "\n";
    for(const auto &s : v)
        std::cout << s << "\n";


    return 0;
}







