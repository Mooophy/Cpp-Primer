/***************************************************************************
 *  @file       main.cpp
 *  @author     Yue Wang
 *  @date       3  Mar 2014
 *              Aug, 2015
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 16.63:
// Define a function template to count the number of occurrences of a given
// value in a vector.
// Test your program by passing it a vector of doubles, a vector of ints,
// and a vector of strings.
//
// Exercise 16.64:
// Write a specialized version of the template from the previous exercise to
// handle vector<const char*> and a program that uses this specialization.
//

#include <iostream>
#include <vector>
#include <cstring>

// template
template<typename T>
std::size_t  count(std::vector<T> const& vec, T value) 
{
    auto count = 0u;
    for(auto const& elem  : vec)
        if(value == elem) ++count;
    return count;
}

// template specialization
template<>
std::size_t count (std::vector<const char*> const& vec, const char* value)
{
    auto count = 0u;
    for(auto const& elem : vec)
        if(0 == strcmp(value, elem)) ++count;
    return count;
}
int main()
{
    // for ex16.63
    std::vector<double> vd = { 1.1, 1.1, 2.3, 4 };
    std::cout << count(vd, 1.1) << std::endl;
    
    // for ex16.64
    std::vector<const char*> vcc = { "alan", "alan", "alan", "alan", "moophy" };
    std::cout << count(vcc, "alan") << std::endl;

    return 0;
}
