//
//  ex10_05.cpp
//  Exercise 10.5
//
//  Created by pezy on 11/9/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  In the call to equal on rosters, what would happen if both rosters held C-style strings, rather than library strings? 
//  @Answer It's the same as `std::string`

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::vector<const char *> roster1{"Mooophy", "pezy", "Queequeg"};
    std::list<const char *>  roster2{"Mooophy", "pezy", "Queequeg", "shbling", "evan617"};
    std::cout << std::equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
}

// out
// 1
