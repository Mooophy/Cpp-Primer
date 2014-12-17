//
//  ex11_32.cpp
//  Exercise 11.32
//
//  Created by pezy on 12/17/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Using the multimap from the previous exercise, write a program to print the list of **authors and their works** alphabetically.

#include <map>
#include <set>
#include <string>
#include <iostream>

using std::string;

int main()
{
    std::multimap<string, string> map{
        {"alan", "DMA"},
        {"pezy", "LeetCode"},
        {"alan", "CLRS"},
        {"wang", "FTP"},
        {"pezy", "CP5"},
        {"wang", "CPP-Concurrency"}
    };
    std::map<string, std::multiset<string>> ordermap;
    for (const auto &e : map)
        ordermap[e.first].insert(e.second);
    for (const auto &e : ordermap) {
        std::cout << e.first << ": ";
        for (const auto &work : e.second)
            std::cout << work << " ";
        std::cout << std::endl;
    }
}