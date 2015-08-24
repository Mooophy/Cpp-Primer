//
//  ex9_19.cpp
//  Exercise 9.19
//
//  Created by pezy on 12/3/14.
//
//  @Brief  Rewrite the program from the previous exercise to use a list.
//          List the changes you needed to make.
//  @See    ex9_18.cpp

#include <iostream>
#include <string>
#include <list>

using std::string; using std::list; using std::cout; using std::cin; using std::endl;

int main()
{
    list<string> input;
    for (string str; cin >> str; input.push_back(str));
    for (auto iter = input.cbegin(); iter != input.cend(); ++iter)
        cout << *iter << endl;

    return 0;
}
