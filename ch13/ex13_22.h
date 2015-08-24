//
//  ex13_22.h
//  Exercise 13.22
//
//  Created by pezy on 1/13/15.
//
//  Assume that we want HasPtr to behave like a value. 
//  That is, each object should have its own copy of the string to which the objects point. 
//  We¡¯ll show the definitions of the copy-control members in the next section. 
//  However, you already know everything you need to know to implement these members. 
//  Write the HasPtr copy constructor and copyassignment operator before reading on. 
//
//  See ex13_11.h 

#ifndef CP5_ex13_11_h
#define CP5_ex13_11_h

#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) { }
    HasPtr& operator=(const HasPtr &hp) {
        auto new_p = new std::string(*hp.ps);
        delete ps;
        ps = new_p;
        i = hp.i;
        return *this;
    }
    ~HasPtr() {
        delete ps;
    } 
private:
    std::string *ps;
    int i;
};

#endif
