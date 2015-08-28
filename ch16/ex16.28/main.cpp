/***************************************************************************
*  @file       main.cpp
*  @author     Yue Wang
*  @date       04  Feb 2014
*                  Jul 2015  
*  @remark     This code is for the exercises from C++ Primer 5th Edition
*  @note
***************************************************************************/
//
// Exercise 16.28 Write your own versions of shared_ptr and unique_ptr
//

#include <iostream>
#include <string>
#include "shared_pointer.hpp"

int main()
{
    auto sp = cp5::SharedPointer<int>{ new int(42) };
    auto sp2 = sp;
    std::cout << *sp << std::endl;
    std::cout << sp.use_count() << std::endl;
    
    auto string_ptr = cp5::SharedPointer<std::string>{ new std::string{ "Yue" } };
    std::cout << *string_ptr << std::endl;
    std::cout << string_ptr->size() << std::endl;

    return 0;
}
