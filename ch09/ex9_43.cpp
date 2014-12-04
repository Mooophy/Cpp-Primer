//
//  ex9_43.cpp
//  Exercise 9.43
//
//  Created by pezy on 12/4/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Write a function that takes three strings, s, oldVal, and newVal.
//          Using iterators, and the insert and erase functions replace
//          all instances of oldVal that appear in s by newVal.
//          Test your function by using it to replace common abbreviations,
//          such as “tho” by “though” and “thru” by “through”.

#include <iostream>
#include <string>

using std::cout; using std::endl; using std::string;

void func(string &s, const string &oldVal, const string &newVal)
{
    for (string::size_type i=0; i!=s.size(); ++i)
        if (s.substr(i, oldVal.size()) == oldVal)
            {
                s.erase(i, oldVal.size());
                s.insert(i, newVal);
            }
}

int main()
{
    string str{"To drive straight thru is a foolish, tho courageous act."};
    func(str, "tho", "though");
    func(str, "thru", "through");
    cout << str << endl;

    return 0;
}
