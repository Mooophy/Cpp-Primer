/***************************************************************************
 *  @file       hasptr.h
 *  @author     Alan.W
 *  @date       05  JAN 2014
 *  @remark     move constructor added 09 Jan 2014
 ***************************************************************************/

#ifndef HASPTR_H
#define HASPTR_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

//! revised for ex13.31

//! a class holding a std::string*
class HasPtr
{
    friend void swap(HasPtr&, HasPtr&);
    friend bool operator <(const HasPtr& lhs, const HasPtr& rhs);
public:
    //! default constructor.
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0)
    { }

    //! copy constructor.
    HasPtr(const HasPtr& hp) :
        ps(new std::string(*hp.ps)), i(hp.i)
    { }

    //! move constructor.
    HasPtr(HasPtr&& hp) noexcept :
        ps(hp.ps), i(hp.i)
    { hp.ps = nullptr; }


    HasPtr&
    operator = (HasPtr rhs);
    //!        ^^ no const here

    //! destructor.
    ~HasPtr()
    {
        delete ps;
    }

private:
    std::string *ps;
    int    i;
};
#endif // HASPTR_H
