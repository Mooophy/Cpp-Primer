/***************************************************************************
*  @file       main.cpp
*  @author     Alan.W  wy-ei
*  @date       02  Feb 2014
*              13  Oct 2014
*              30  Apr 2015
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

template<size_t _N, typename _Ty>
void print(const _Ty(&_Val)[_N]){
    for (size_t i = 0; i < _N; i++){
        std::cout << _Val[i] << " ";
    }
}

int main()
{
    int vi[] = { 2, 3, 4, 5, 6, 7 };
    std::string vs[] = { "aaa", "bbb", "ccc", "ddd" };
    print(vi);
    print(vs);

    return 0;
}
