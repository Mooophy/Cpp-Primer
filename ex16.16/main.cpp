/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       02  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 16.16:
//! Rewrite the StrVec class (§ 13.5, p. 526) as a template named Vec.
//!

#include "vec.h"
#include <vector>
#include <iostream>

int main()
{
    Vec<int> v = {1,2,3,4,5};

    Vec<int> v2;

    v2 = v;
    std::cout << v2.capacity() << "\n";
    v2.push_back(99);
    v2.resize(2,2);

    for (auto t : v2)
        std::cout << t << " ";


    std::cout << v2.capacity() << "\n";

    return 0;
}
