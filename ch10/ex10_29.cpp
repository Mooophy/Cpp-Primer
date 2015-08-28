//
//  ex10_29.cpp
//  Exercise 10.29
//
//  Created by pezy on 12/13/14.
//
//  Write a program using stream iterators to read a text file into a vector of strings.


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

using std::string;

int main()
{
    std::ifstream ifs("../data/book.txt");
    std::istream_iterator<string> in(ifs), eof;
    std::vector<string> vec;
    std::copy(in, eof, back_inserter(vec));
    
    // output
    std::copy(vec.cbegin(), vec.cend(), std::ostream_iterator<string>(std::cout, "\n"));
}
