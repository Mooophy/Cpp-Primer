/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Alan.W
 *  @date       26  DEC 2013
 *  @remark
 ***************************************************************************/

//!
//! Exercise 12.24:
//! Write a program that reads a string from the standard input into a dynamically
//! allocated character array. Describe how your program handles varying size inputs.
//! Test your program by giving it a string of data that is longer than the array
//! size you’ve allocated.
//  Check the size of the string first and use this size to allocate the dynamic array.
//!

#include <iostream>





int main()
{
    char *s;
    std::string str;

    while (std::cin >> str)
    {
        s = new char[str.size()];
        str.copy(s, str.size());

        std::cout << s <<"\n";
    }

    delete [] s;


    return 0;
}
