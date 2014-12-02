//
//  ex9_16.cpp
//  Exercise 9.16
//
//  Created by pezy on 12/2/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Repeat the previous program, but compare elements in a
//          list<int> to a vector<int>.

#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::list<int> vec1{1,2,3,4,5};
    std::vector<int> vec2{1,2,3,4,5};
    std::vector<int> vec3{1,2,3,4};

    std::cout << (std::vector<int>(vec1.begin(), vec1.end()) == vec2 ? "true" : "false")
              << std::endl;
    std::cout << (std::vector<int>(vec1.begin(), vec1.end()) == vec3 ? "true" : "false")
              << std::endl;

    return 0;
}
