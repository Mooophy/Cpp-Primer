/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       12  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 16.51:
// Determine what sizeof...(Args) and sizeof...(rest) return for each call to foo in this section.
//
// Exercise 16.52:
// Write a program to check your answer to the previous question.
//

#include <iostream>

template<typename T, typename ...Args>
void foo(T t, Args ...args)
{
    std::cout << sizeof...(Args) << std::endl;
    std::cout << sizeof...(args) << std::endl;
}


int main()
{
    foo(1, 2);
    foo(1, 23, 4, 5, 6);
}
