//
//  ex9_41.cpp
//  Exercise 9.41
//
//  Created by pezy on 12/4/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Write a program that initializes a string from a vector<char>.

#include <iostream>
#include <vector>
#include <string>

using std::vector; using std::cout; using std::endl; using std::string;

int main()
{
    vector<char> vec{'p', 'e', 'z', 'y'};
    string str(vec.begin(), vec.end());
    
    cout << str << endl;
    
    return 0;
}
