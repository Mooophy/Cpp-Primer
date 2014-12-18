//
//  ex11_23.cpp
//  Exercise 11.23
//
//  Created by pezy on 12/16/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Rewrite the map that stored vectors of children’s names with a key that is the family last name for the exercises in 11.2.1 (p. 424) to use a multimap.

#include <map>
#include <string>
#include <iostream>

using std::string;

int main()
{
    std::multimap<string, string> families;
    for (string lastName, childName; std::cin >> childName >> lastName; families.emplace(lastName, childName));
    for (const auto &s : families)
        std::cout << s.second << " " << s.first << std::endl;
}