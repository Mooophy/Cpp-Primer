//
//  ex9_44.cpp
//  Exercise 9.44
//
//  Created by pezy on 12/4/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Rewrite the previous function using an index and replace.
//  @See    9.43

#include <iostream>
#include <string>

using std::cout; using std::endl; using std::string;

void func(string &s, const string &oldVal, const string &newVal)
{
    auto found = s.find(oldVal);
    if (found == string::npos) return;
    s.replace(found, oldVal.size(), newVal);
}

int main()
{
    string str{"To drive straight thru is a foolish, tho courageous act."};
    func(str, "tho", "though");
    func(str, "thru", "through");
    cout << str << endl;

    return 0;
}
