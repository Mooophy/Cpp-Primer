//
//  ex10_30.cpp
//  Exercise 10.30
//
//  Created by pezy on 12/13/14.
//
//  Use stream iterators, sort, and copy to read a sequence of integers from the standard input,
//  sort them, and then write them back to the standard output.


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
    std::copy(vec.cbegin(), vec.cend(), std::ostream_iterator<int>(std::cout, " "));
}
