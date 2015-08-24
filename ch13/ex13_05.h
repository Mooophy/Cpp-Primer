//
//  ex13_05.h
//  CP5
//
//  Created by pezy on 1/5/15.
//
//  Given the following sketch of a class, write a copy constructor that copies all the members.
//  Your constructor should dynamically allocate a new string and copy the object to which ps points,
//  rather than copying ps itself.

#ifndef CP5_ex13_05_h
#define CP5_ex13_05_h

#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) { }
private:
    std::string *ps;
    int i;
};

#endif
