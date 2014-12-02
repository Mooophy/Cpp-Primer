//
//  ex9_27.cpp
//  Exercise 9.27
//
//  Created by pezy on 12/3/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Write a program to find and remove the odd-valued
//          elements in a forward_list<int>.

#include <iostream>
#include <forward_list>

using std::forward_list; using std::cout; using std::endl;

int main()
{
    forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
    for (auto prev = flst.before_begin(), curr = flst.begin(); curr != flst.end(); )
        if (*curr & 0x1) curr = flst.erase_after(prev);
        else prev = curr++;
    
    for (auto i : flst)
        cout << i << " ";
    
    return 0;
}


