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
    
    // using function equal_range to get range itertors
    auto a = authors.equal_range(author);
    while(a.first != a.second)
    {
        if(a.first->second == work) // if it is required element,
            a.first == authors.erase(a.first);  // delete element and move iterator to the next element.
        else // in another case,
            ++a.first; // or just move iterator to the next element.
    }
    
    
    for (const auto &author : authors)
        std::cout << author.first << " " << author.second << std::endl;
}
