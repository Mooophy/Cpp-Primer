//
//  ex9_49.cpp
//  Exercise 9.49
//
//  Created by pezy on 12/5/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  A letter has an ascender if, as with d or f, part of the letter extends
//          above the middle of the line.
//          A letter has a descender if, as with p or g, part of the letter extends below the line.
//          Write a program that reads a file containing words and reports the longest word
//          that contains neither ascenders nor descenders.

#include <string>
#include <fstream>
#include <iostream>

using std::string; using std::cout; using std::endl; using std::ifstream;

int main()
{
    ifstream ifs("../data/letter.txt");
    if (!ifs) return -1;
    string longest_word;
    for (string word; ifs >> word; )
        if (word.find_first_not_of("aceimnorsuvwxz") == string::npos &&
            word.size() > longest_word.size())
            longest_word = word;
            
    cout << longest_word << endl;

    ifs.close();


    return 0;
}
