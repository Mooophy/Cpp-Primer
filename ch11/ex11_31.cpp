//
//  ex11_31.cpp
//  Exercise 11.31
//
//  Created by pezy on 12/17/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Write a program that defines a multimap of authors and their works.
//  Use **find** to find **an element** in the multimap and erase that element.
//  Be sure your program works correctly if the element you look for is not in the map.

#include <map>
#include <string>
#include <iostream>

using std::string;

int main()
{
    std::multimap<string, string> map = {{"Alan","111"},{"Alan","112"},{"Alan","113"},{"Wang","222"}};
    // want to delete an element that author is [Alan], work is [112].
    string author = "Alan";
    string work = "112";
    
    auto found = map.find(author);
    auto count = map.count(author);
    while (count) {
        if (found->second == work) map.erase(found);
        ++found;
        --count;
    }
    
    for (const auto &e : map)
        std::cout << e.first << " " << e.second << std::endl;
}