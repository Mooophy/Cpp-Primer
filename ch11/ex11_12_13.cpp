//
//  ex11_12_13.cpp
//  Exercise 11.12 11.13
//
//  Created by pezy on 12/15/14.
//
//  Write a program to read a sequence of strings and ints,
//  storing each into a pair. Store the pairs in a vector.
//
//  There are at least three ways to create the pairs in the program for the previous exercise.
//  Write three versions of that program, creating the pairs in each way.
//  Explain which form you think is easiest to write and understand, and why.

#include <vector>
#include <utility>
#include <string>
#include <iostream>

int main()
{
    std::vector<std::pair<std::string, int>> vec;
    std::string str;
    int i;
    while (std::cin >> str >> i)
        vec.push_back(std::pair<std::string, int>(str, i));
        //vec.push_back(std::make_pair(str, i));
        //vec.push_back({ str, i });
        //vec.emplace_back(str, i); //!! easiest way.
    
    for (const auto &p : vec)
        std::cout << p.first << ":" << p.second << std::endl;
}
