//
//  ex7_09.h
//  Exercise 7.9
//
//  Created by pezy on 11/8/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//

#ifndef CP5_ex7_09_h
#define CP5_ex7_09_h

#include <string>

class Person {
    std::string name;
    std::string address;
    
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
};

std::istream &read(std::istream &is, const Person &person)
{
    is >> person.name >> person.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &person)
{
    os << name << " " << address;
    return os;
}

#endif
