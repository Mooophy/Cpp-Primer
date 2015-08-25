//
// @author Yue Wang
// @date   01.12.2014
//
// Exercise 10.1:
// The algorithm header defines a function named count that, like find,
// takes a pair of iterators and a value.count returns a count of how
// often that value appears.
// Read a sequence of ints into a vector and print the count of how many
// elements have a given value.
//
// Exercise 10.2:
// Repeat the previous program, but read values into a list of strings.
//


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>


int main()
{
    // 10.1
    std::vector<int> v = { 1, 2, 3, 4, 5, 6, 6, 6, 2 };
    std::cout << "ex 10.01: " << std::count(v.cbegin(), v.cend(), 6) << std::endl;

    // 10.2
    std::list<std::string> l = { "aa", "aaa", "aa", "cc" };
    std::cout << "ex 10.02: " << std::count(l.cbegin(), l.cend(), "aa") << std::endl;

    return 0;
}
