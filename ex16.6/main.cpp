/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       02  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 16.6:
//! How do you think the library begin and end functions that take an array
//! argument work?
//  std::begin  is a template function that takes a reference to an array.It
//  returns this reference as the iterator pointing to the first element in
//  this array.
//
//  std::end    is a template function that takes a reference to an array and
//  capture the size. It return this reference plus the size as the iterator pointing
//  to one past last element
//
//! Define your own versions of these functions.
//!

#include <iostream>
#include <vector>
#include <list>
#include <string>

//! the same as std::begin
template<typename T, unsigned size>
T* begin(const T(&arr)[size])
{
    return arr;
}


//! the same as std::end
template<typename T, unsigned size>
T* end(const T (&arr)[size])
{
    return arr + size;
}

int main()
{
    std::string s[] = {"sssss","ss","ss","ssssszzzz"};
    std::cout << *(begin(s)+1) << std::endl;
    std::cout << *(end(s) - 1) << std::endl;
    return 0;
}

