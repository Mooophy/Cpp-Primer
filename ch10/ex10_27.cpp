//
//  ex10_27.cpp
//  Exercise 10.27
//
//  Created by pezy on 12/13/14.
//
//  In addition to unique, the library defines function named unique_copy that
//  takes a third iterator denoting a destination into which to copy the unique elements.
//  Write a program that uses unique_copy to copy the unique elements from
//  a vector into an initially empty list.

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

int main()
{
    std::vector<int> vec{ 1, 1, 3, 3, 5, 5, 7, 7, 9 };
    std::list<int> lst;
    
    std::unique_copy(vec.begin(), vec.end(), back_inserter(lst));
    for (auto i : lst)
        std::cout << i << " ";
    std::cout << std::endl;
}
