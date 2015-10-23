//
//  ex11_23.cpp
//  Exercise 11.23
//
//  Created by pezy on 12/16/14.
//
//  Rewrite the map that stored vectors of children’s names with a key that is the family last name for the exercises
//  in 11.2.1 (p. 424) to use a multimap.

#include <map>
#include <string>
#include <iostream>

using std::string;
using std::multimap;
using std::cin;
using std::endl;

int main()
{
    multimap<string, string> families;
    for (string lname, cname; cin >> cname >> lname; families.emplace(lname, cname));
    for (auto const& family : families)
        std::cout << family.second << " " << family.first << endl;
}
