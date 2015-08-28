//
//  ex9_16.cpp
//  Exercise 9.16
//
//  Created by pezy on 12/2/14.
//
//  @Brief  Repeat the previous program, but compare elements in a
//          list<int> to a vector<int>.
//  
//  @Refactor Yue Wang Jun 2015
//


#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::list<int>      li{ 1, 2, 3, 4, 5 };
    std::vector<int>    vec2{ 1, 2, 3, 4, 5 };
    std::vector<int>    vec3{ 1, 2, 3, 4 };

    std::cout << (std::vector<int>(li.begin(), li.end()) == vec2 ? "true" : "false") << std::endl;
    std::cout << (std::vector<int>(li.begin(), li.end()) == vec3 ? "true" : "false") << std::endl;

    return 0;
}
