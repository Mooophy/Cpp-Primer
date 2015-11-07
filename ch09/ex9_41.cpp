//
//  ex9_41.cpp
//  Exercise 9.41
//
//  Created by pezy on 12/4/14.
//
//  @Brief  Write a program that initializes a string from a vector<char>.

#include <iostream>
#include <vector>
#include <string>

using std::vector; 
using std::cout; 
using std::endl; 
using std::string;

int main()
{
    vector<char> v{ 'p', 'e', 'z', 'y' };
    string str(v.cbegin(), v.cend());
    cout << str << endl;

    return 0;
}
