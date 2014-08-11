/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       30  DEC 2013
 *  @remark
 ***************************************************************************/
//!
//! Exercise 13.5:
//! Given the following sketch of a class, write a copy constructor that copies
//! all the members. Your constructor should dynamically allocate a new string
//! (§ 12.1.2, p. 458) and copy the object to which ps points, rather than copying
//! ps itself.
//!

#include <string>
#include <iostream>


class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }

    /**
     * ex13.5, this exercise asks for a deep copy.
     * Hence new dynamic memory must be allocated .
     */
    HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) { }
    //!                           ^^^^^^^^^^^^^^^
private:
    std::string *ps;
    int    i;
};

int main()
{


    return 0;
}

