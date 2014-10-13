/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       02  Feb 2014
 *              13  Oct 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 16.5:
//! Write a template version of the print function from § 6.2.4 (p. 217) that
//! takes a reference to an array and can handle arrays of any size and any
//! element type.
//!

#include <iostream>
#include <string>

template<typename Arr>
void print(const Arr& a)
{
    for(const auto& elem : a)
        std::cout << elem << std::endl;
}

int main()
{
    std::string p[] = {"ssss","aaa","ssssss"};
    char c[] = {'a','b','c','d'};
    int  i[] = {1};
    print(i);
    print(c);
    print(p);

    std::cout << "\nexit normally\n";
    return 0;
}
