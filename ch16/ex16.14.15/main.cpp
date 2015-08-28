/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       02  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 16.14:
// Write a Screen class template that uses nontype parameters to define the
// height and width of the Screen.
//
// Exercise 16.15:
// Implement input and output operators for your Screen template.
// Which, if any, friends are necessary in class Screen to make the input and
// output operators work? Explain why each friend declaration, if any, was
// needed.
//    According to  the chapter of 14.2.1, the class of << and <<  should be a friend of this class.
//

#include "Screen.h"
#include <iostream>

int main()
{
    Screen<5, 5> scr('c');
    Screen<5, 5> scr2;

    // output src to the screen
    std::cout<<scr;
    // input connet  to the  src 
    std::cin>>scr2;
    // test input
    std::cout<<scr2;

    return 0;
}
