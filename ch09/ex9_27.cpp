//
//  ex9_27.cpp
//  Exercise 9.27
//
//  Created by pezy on 12/3/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Write a program to find and remove the odd-valued
//          elements in a forward_list<int>.
//
//  @Refactored by @Yue Wang Jun 2015
//

#include <iostream>
#include <forward_list>

using std::forward_list; using std::cout;

int main()
{
    forward_list<int> li = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    li.remove_if([](int i){ return i & 0x1; });
    for (auto i : li) cout << i << " ";

    return 0;
}
