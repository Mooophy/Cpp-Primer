/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       20  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 14.38:
//! Write a class that tests whether the length of a given string matches a
//! given bound. Use that object to write a program to report how many words
//! in an input file are of sizes 1 through 10 inclusive.
//!
//! Exercise 14.39:
//! Revise the previous program to report the count of words that are sizes
//! 1 through 9 and 10 or more.
//!

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

class BoundTest
{
public:
    BoundTest(std::size_t l = 0, std::size_t u = 0) : lower(l), upper(u){}
    bool operator() (const std::string& s) { return lower <= s.length() && s.length() <= upper; }

private:
    std::size_t lower;
    std::size_t upper;
};

int main()
{
    std::ifstream fin ("../data/storyDataFile.txt");

    std::size_t quantity9 = 0, quantity10 = 0;
    BoundTest test9(1, 9);
    BoundTest test10(1, 10);

    for (std::string word; fin >> word; ) {
        if (test9(word)) ++quantity9;
        if (test10(word)) ++quantity10;
    }

    std::cout << quantity9 << ", " << quantity10 << std::endl;
}
