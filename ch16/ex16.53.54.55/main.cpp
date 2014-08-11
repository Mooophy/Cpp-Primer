/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       16  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 16.53:
//! Write your own version of the print functions and test them by printing
//! one, two, and five arguments, each of which should have different types.
//!
//! Exercise 16.54:
//! What happens if we call print on a type that doesn’t have an << operator?
//  didn't compile.
//!
//! Exercise 16.55:
//! Explain how the variadic version of print would execute if we declared
//! the nonvariadic version of print after the definition of the variadic
//! version.
//  error: no matching function for call to 'print(std::ostream&)'
//!


#include <iostream>

class Foo
{};

//! function to end the recursion and print the last element
//! this function must be declared before the variadic version of
//! print is defined
template<typename T>
std::ostream& print(std::ostream& os, const T& t)
{
    return os << t;
    //!           ^
    //! note: no seperator after the last element in the pack
}


//! this version of print will be called for all but the last element in the pack
template<typename T, typename... Args>
std::ostream&
print(std::ostream &os, const T &t, const Args&... rest)
{
    //! print the first argument
    os << t << ",";

    //! recursive call; print the other arguments
    return print(os,rest...);
}


int main()
{
    //! printing one argument
    //print(std::cout, 1);

    //! printing two arguments
    print(std::cout, 1,2);

    //! printing 5 arguments
    //print(std::cout, 1,2,3,4,"sss");

    //Foo foo,bar;
    //print(std::cout,foo,bar);

}
