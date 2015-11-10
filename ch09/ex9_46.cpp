//
//  ex9_46.cpp
//  Exercise 9.46
//
//  Created by pezy on 12/5/14.
//
//  @Brief  Rewrite the previous exercise using a position and length to manage the strings.
//          This time use only the insert function.
//  @See    9.45
//
//  Refactored by Yue Wang Oct, 2015
//

#include <iostream>
#include <string>

auto add_pre_and_suffix(std::string name, std::string const& pre, std::string const& su)
{
    name.insert(0, pre);
    name.insert(name.size(), su);
    return name;
}

int main()
{
    std::string name("alan");
    std::cout << add_pre_and_suffix(name, "Mr.", ",Jr.");
    return 0;
}
