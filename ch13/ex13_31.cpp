//
//  ex13_31
//  Exercise 13.31
//  Created by Soyn on 21/7/15.
//  Add the vector<HasPtr>, and sort it.
//
//  Refactored by Yue Wang Jul 2015
//
#include <vector>
#include <algorithm>
#include "ex13_31.h"

int main(void)
{
    HasPtr s{ "s" }, a{ "a" }, c{ "c" };
    std::vector<HasPtr> vec{ s, a, c };
    std::sort(vec.begin(), vec.end());

    for (auto const& elem : vec) elem.show();
    return 0;
}
