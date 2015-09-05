//
//  ex11_31.cpp
//  Exercise 11.31
//
//  Created by pezy on 12/17/14.
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
    std::multimap<string, string> authors{
        { "alan", "DMA" },
        { "pezy", "LeetCode" },
        { "alan", "CLRS" },
        { "wang", "FTP" },
        { "pezy", "CP5" },
        { "wang", "CPP-Concurrency" }
    };
    // want to delete an element that author is [Alan], work is [112].
    string author = "pezy";
    string work = "CP5";
    
    auto found = authors.find(author);
    auto count = authors.count(author);
    while (count) {
        if (found->second == work) {
            authors.erase(found);
            break;   
        }
        ++found;
        --count;
    }
    
    for (const auto &author : authors)
        std::cout << author.first << " " << author.second << std::endl;
}
