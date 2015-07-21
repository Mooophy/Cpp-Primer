//
//  ex13_31.h
//  Exercise 13.31 
//
//  Created by pezy on 1/23/15.
//
//  Give your class a < operator and define a vector of HasPtrs. 
//  Give that vector some elements and then sort the vector. 
//  Note when swap is called.
//
//  Refactored by Yue Wang Jul 2015
//

#ifndef CP5_ex13_11_h
#define CP5_ex13_11_h

#include <string>
#include <iostream>

class HasPtr 
{
public:
    friend void swap(HasPtr&, HasPtr&);
    friend bool operator<(const HasPtr &lhs, const HasPtr &rhs);

    HasPtr(const std::string &s = std::string()) 
        : ps(new std::string(s)), i(0) 
    { }

    HasPtr(const HasPtr &hp) 
        : ps(new std::string(*hp.ps)), i(hp.i) 
    { }

    HasPtr& operator=(HasPtr tmp) 
    {
        this->swap(tmp);
        return *this;
    }

    ~HasPtr() 
    {
        delete ps;
    }

    void swap(HasPtr &rhs) 
    {
        using std::swap;
        swap(ps, rhs.ps);
        swap(i, rhs.i);
        std::cout << "call swap(HasPtr &rhs)" << std::endl;
    }

    void show() const
    { 
        std::cout << *ps << std::endl; 
    }
private:
    std::string *ps;
    int i;
};

void swap(HasPtr& lhs, HasPtr& rhs)
{
    lhs.swap(rhs);
}

bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
    return *lhs.ps < *rhs.ps;
}

#endif
