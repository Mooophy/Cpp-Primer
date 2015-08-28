/***************************************************************************
 *  @file       main.cpp
 *  @author     Yue Wang
 *  @date       16  Feb 2014
                Aug, 2015
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 16.53:
// Write your own version of the print functions and test them by printing
// one, two, and five arguments, each of which should have different types.
//
// Exercise 16.54:
// What happens if we call print on a type that doesn’t have an << operator?
//  It didn't  compile.
//
// Exercise 16.55:
// Explain how the variadic version of print would execute if we declared
// the nonvariadic version of print after the definition of the variadic
// version.
//  error: no matching function for call to 'print(std::ostream&)'
//

#include <iostream>

// trivial case 
template<typename Printable>
std::ostream& print(std::ostream& os, Printable const& printable)
{
    return os << printable;
}
// recursion
template<typename Printable, typename... Args>
std::ostream& print(std::ostream& os, Printable const& printable, Args const&... rest)
{
    return print(os << printable << ", ", rest...);
}

int main()
{
    print(std::cout, 1) << std::endl;
    print(std::cout, 1, 2) << std::endl;
    print(std::cout, 1, 2, 3, 4, "sss", 42.4242) << std::endl;

    return 0;
}
