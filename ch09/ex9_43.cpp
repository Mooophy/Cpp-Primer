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
//          such as "tho" by "though" and "thru" by "through".
//  @Compile    Gcc can't support return iterator of string::insert. Please use clang or VS2013

#include <iostream>
#include <string>

using std::cout; using std::endl; using std::string; using std::prev;

void Replace(string &s, string const& oldVal, string const& newVal) {
    auto val_size = oldVal.size();
    if (s.size() < val_size) return;

    for (auto iter = s.begin(), end = prev(s.end(), val_size - 1); iter != end; ++iter) {
        if (string{iter, iter + val_size} == oldVal) {
            iter = s.earse(iter, iter + val_size);
            iter = s.insert(iter, newVal.cbegin(), newVal.cend()); // gcc 4.9 bug (see http://stackoverflow.com/questions/29690369)
            iter += newVal.size();
        }
    }
}

int main()
{
    string str{"To drive straight thru is a foolish, tho courageous act."};
    Replace(str, "tho", "though");
    Replace(str, "thru", "through");
    cout << str << endl;
}
