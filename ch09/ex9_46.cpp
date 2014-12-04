//
//  ex9_46.cpp
//  Exercise 9.46
//
//  Created by pezy on 12/5/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Rewrite the previous exercise using a position and length to manage the strings.
//          This time use only the insert function.
//  @See    9.45

#include <iostream>
#include <string>

std::string
pre_suffix(const std::string &name, const std::string &pre, const std::string &su)
{
    std::string ret(name);
    ret.insert(0, pre);
    ret.insert(ret.size(), su);
    
    return ret;
}

int main()
{
    std::string name("alan");
    std::cout << pre_suffix(name, "Mr.", ",Jr.");
    
    return 0;
}