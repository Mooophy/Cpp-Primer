//
//  ex8_13.cpp
//  Exercise 8.13
//
//  Created by pezy on 11/29/14.
//
//  @Brief  Rewrite the phone number program from this section to read from
//          a named file rather than from cin.
//  @See    ex8_11.cpp

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using std::vector; using std::string; using std::cin; using std::istringstream;
using std::ostringstream; using std::ifstream; using std::cerr; using std::cout; using std::endl;
using std::isdigit;

struct PersonInfo {
    string name;
    vector<string> phones;
};

bool valid(const string& str)
{
    return isdigit(str[0]);
}

string format(const string& str)
{
    return str.substr(0,3) + "-" + str.substr(3,3) + "-" + str.substr(6);
}

int main()
{
    ifstream ifs("../data/phonenumbers.txt");
    if (!ifs)
    {
        cerr << "no phone numbers?" << endl;
        return -1;
    }

    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while (getline(ifs, line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }

    for (const auto &entry : people)
    {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones)
            if (!valid(nums)) badNums << " " << nums;
            else formatted << " " << format(nums);
        if (badNums.str().empty())
            cout << entry.name << " " << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name
                 << " invalid number(s) " << badNums.str() << endl;
    }

    return 0;
}
