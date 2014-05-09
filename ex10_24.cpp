//! @Alan
//! Exercise 10.24:
//! Use bind and check_size to find the first element in a vector of ints that has a value greater
//! than the length of a specified string value.
//  Discussion over this exercise on StackOverflow
//  http://stackoverflow.com/questions/20539406/what-type-does-stdfind-if-not-return
//!



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

bool
check_size(const std::string &s, std::string::size_type sz)
{
    return s.size() > sz;
}

std::vector<int>::iterator
find_first_bigger(std::vector<int> &v, const std::string &s);

int main(){return 0;}

std::vector<int>::iterator
find_first_bigger(std::vector<int> &v, const std::string &s)
{
   auto it= std::find_if_not(v.begin(), v.end(), std::bind(check_size, s, std::placeholders::_1));
   return it;
}
