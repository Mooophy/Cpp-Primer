//
//  ex10_31.cpp
//  Exercise 10.31
//
//  Created by pezy on 12/13/14.
//
//  Update the program from the previous exercise so that it prints only the unique elements.
//  Your program should use unqiue_copy


#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::istream_iterator<int> in_iter(std::cin), eof;
    std::vector<int> vec;
    while (in_iter != eof)
        vec.push_back(*in_iter++);
    std::sort(vec.begin(), vec.end());
    std::unique_copy(vec.cbegin(), vec.cend(), std::ostream_iterator<int>(std::cout, " "));
}
