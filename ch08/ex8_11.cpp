//
//  ex8_11.cpp
//  Exercise 8.11
//
//  Created by pezy on 11/29/14.
//
//  @Brief  The program in this section defined its istringstream object inside the outer while loop.
//          What changes would you need to make if record were defined outside that loop?
//          Rewrite the program, moving the definition of record outside the while, and see whether you thought of all the changes that are needed.

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::vector; using std::string; using std::cin; using std::istringstream;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main()
{
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while (getline(cin, line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    
    for (auto &p : people)
    {
        std::cout << p.name << " ";
        for (auto &s : p.phones)
            std::cout << s << " ";
        std::cout << std::endl;
    }
    
    return 0;
}
