//
//  ex10_22.cpp
//  Exercise 10.22
//
//  Created by pezy on 12/11/14.
//  Updated by pezy on 10/12/15.
//
//  @Brief  Rewrite the program to count words of size 6 or less using
//          functions in place of the lambdas.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using std::string;
using namespace std::placeholders;

bool isLesserThanOrEqualTo6(const string &s, string::size_type sz)
{
    return s.size() <= sz;
}

int main()
{
    std::vector<string> authors{ "Mooophy", "pezy", "Queequeg90", "shbling", "evan617" };
    std::cout << count_if(authors.cbegin(), authors.cend(), bind(isLesserThanOrEqualTo6, _1, 6));
}
