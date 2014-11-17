/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       02  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 16.4:
//! Write a template that acts like the library find algorithm. The function
//! will need two template type parameters, one to represent the function’s
//! iterator parameters and the other for the type of the value. Use your
//! function to find a given value in a vector<int> and in a list<string>.
//!

#include <iostream>
#include <vector>
#include <list>
#include <string>


template<typename iteratorT, typename valueT>
iteratorT find(const iteratorT& first, const iteratorT& last,const valueT& value )
{
    auto iter = first;
    while(iter != last && *iter != value) ++iter;
    return iter;
}

int main()
{
    /** @brief  test using vector<int>
      */
    std::vector<int> vi = {1,2,3,4,5,6,7,8,9};

    auto it = find(vi.cbegin(), vi.cend(), 5);

    std::cout << *it << std::endl;


    /** @brief  test using list<int>
      */
    std::list<std::string> l = {"aa","bb","cc","dd","ee","ff","gg"};

    std::list<std::string>::const_iterator itL = find(l.cbegin(), l.cend(), "ee");

    std::cout << *itL << std::endl;

    return 0;
}

