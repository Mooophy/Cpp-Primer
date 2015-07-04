//
//  ex9_18.cpp
//  Exercise 9.18
//
//  Created by pezy on 12/3/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Write a program to read a sequence of strings from the standard input into
//          a deque. Use iterators to write a loop to print the elements in the deque.

#include <iostream>
#include <string>
#include <deque>

using std::string; using std::deque; using std::cout; using std::cin; using std::endl;

int main()
{
    deque<string> input;
    for (string str; cin >> str; input.push_back(str));
    for (auto &iter : input) cout << iter << endl;

    return 0;
}
