//
//  ex9_20.cpp
//  Exercise 9.20
//
//  Created by pezy on 12/3/14.
//
//  @Brief  Write a program to copy elements from a list<int> into two deques.
//          The even-valued elements should go into one deque and the odd ones into the other.

#include <iostream>
#include <deque>
#include <list>
using std::deque; using std::list; using std::cout; using std::cin; using std::endl;

int main()
{
    list<int> l{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    deque<int> odd, even;
    for (auto i : l)
        (i & 0x1 ? odd : even).push_back(i);

    for (auto i : odd) cout << i << " ";
    cout << endl;
    for (auto i : even)cout << i << " ";
    cout << endl;

    return 0;
}
