//
//  ex13_08.h
//  CP5
//
//  Created by pezy on 1/12/15.
//
//  Write the assignment operator for the HasPtr class from exercise 13.5 in 13.1.1 (p. 499).
//  As with the copy constructor, your assignment operator should copy the object to which ps points.
//
//  See ex13_05.h 

#ifndef CP5_ex13_08_h
#define CP5_ex13_08_h

#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) { }
    HasPtr& operator=(const HasPtr &hp) {
        std::string *new_ps = new std::string(*hp.ps);
        delete ps;
        ps = new_ps;
        i = hp.i;
        return *this;
    }
private:
    std::string *ps;
    int i;
};

#endif
