//
//  ex9_20.cpp
//  Exercise 9.20
//
//  Created by pezy on 12/3/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Write a program to copy elements from a list<int> into two deques.
//          The even-valued elements should go into one deque and the odd ones into the other.

#include <iostream>
#include <deque>
#include <list>

using std::deque; using std::list; using std::cout; using std::cin; using std::endl;

int main()
{
    list<int> l{1,2,3,4,5,6,7,8,9,10};
    deque<int> d_odd, d_even;
    for (auto iter = l.cbegin(); iter != l.cend(); ++iter)
        (*iter & 0x1 ? d_odd : d_even).push_back(*iter);

    for (auto i : d_odd)
        cout << i << " ";
    cout << endl;
    for (auto i : d_even)
        cout << i << " ";
    cout << endl;

    return 0;
}
