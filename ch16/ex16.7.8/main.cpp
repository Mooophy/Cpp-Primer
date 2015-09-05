/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       02  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 16.7:
// Write a constexpr template that returns the size of a given array.
//
// Exercise 16.8:
// In the “Key Concept” box on page 108, we noted that as a matter of habit
// C++ programmers prefer using != to using <. Explain the rationale for
// this habit.
//
//  The reason is that more class defines "!=" rather than "<". Doing so can
//  reduce the number of requirement of the class used with a template class.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>

template<typename T, unsigned size>
constexpr unsigned getSize(const T(&)[size])
{
    return size;
}

int main()
{
    std::string s[] = { "sss" };
    std::cout << getSize(s) << std::endl;

    char c[] = "s";
    std::cout << getSize(c) << std::endl;
    // the output is 2, as '\0' is added at the end of the array
    return 0;
}
