/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       3  Mar 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 17.1:
//! Define a tuple that holds three int values and initialize the members to 10, 20, and 30.
//!
//! Exercise 17.2:
//! Define a tuple that holds a string, a vector<string>, and a pair<string, int>.
//!

#include <iostream>
#include <tuple>
#include <string>
#include <vector>


int main()
{
    std::tuple<int,int,int> i3 {10,20,30};
    std::tuple<std::string,std::vector<std::string>, std::pair<std::string, int>> t;

}
