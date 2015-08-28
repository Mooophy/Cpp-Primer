//
//  ex9_49.cpp
//  Exercise 9.49
//
//  Created by pezy on 12/5/14.
//
//  @Brief  A letter has an ascender if, as with d or f, part of the letter extends
//          above the middle of the line.
//          A letter has a descender if, as with p or g, part of the letter extends below the line.
//          Write a program that reads a file containing words and reports the longest word
//          that contains neither ascenders nor descenders.
//  
//  @Refactor  @Yue Wang Jun 2015
//

#include <string>
#include <fstream>
#include <iostream>

using std::string; using std::cout; using std::endl; using std::ifstream;

int main()
{
    ifstream ifs("../data/letter.txt");
    if (!ifs) return -1;

    string longest;
    auto update_with = [&longest](string const& curr)
    {
        if (string::npos == curr.find_first_not_of("aceimnorsuvwxz"))
            longest = longest.size() < curr.size() ? curr : longest;
    };
    for (string curr; ifs >> curr; update_with(curr));
    cout << longest << endl;

    return 0;
}
