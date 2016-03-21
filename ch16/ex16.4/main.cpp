/***************************************************************************
*  @file       main.cpp
*  @author     Yue Wang
*  @date       02  Feb 2014
*              18  Jun 2015
*                  Nov 2015
*  @remark     This code is for the exercises from C++ Primer 5th Edition
*  @note
***************************************************************************/
//
// Exercise 16.4:
// Write a template that acts like the library find algorithm. The function
// will need two template type parameters, one to represent the function’s
// iterator parameters and the other for the type of the value. Use your
// function to find a given value in a vector<int> and in a list<string>.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>

namespace ch16
{
    template<typename Iterator, typename Value>
    auto find(Iterator first, Iterator last, Value const& value)
    {
        for (; first != last && *first != value; ++first);
        return first;
    }
}

int main()
{
    std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto is_in_vector = v.cend() != ch16::find(v.cbegin(), v.cend(), 5);
    std::cout << (is_in_vector ? "found\n" : "not found\n");

    std::list<std::string> l = { "aa", "bb", "cc", "dd", "ee", "ff", "gg" };
    auto is_in_list = l.cend() != ch16::find(l.cbegin(), l.cend(), "zz");
    std::cout << (is_in_list ? "found\n" : "not found\n");

    return 0;
}
