/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       01  JAN 2014
 *  @remark
 ***************************************************************************/
//!
//! Exercise 13.25:
//! Assume we want to define a version of StrBlob that acts like a value. Also
//! assume that we want to continue to use a shared_ptr so that our StrBlobPtr
//! class can still use a weak_ptr to the vector. Your revised class will need
//! a copy constructor and copy-assignment operator but will not need a destructor.
//! Explain what the copy constructor and copy-assignment operators must do.
//! Explain why the class does not need a destructor.
//!
//  Copy constructor and copy-assignment operator should dynamicly allocate memory
//  for its own , rather than share the object with the right hand operand.
//
//  StrBlob is using smart pointers which can be managed with synthesized destructor
//  If an object of StrBlob is out of scope, the desstructor for std::shared_ptr
//  will be called automaticaly to free the memory dynamicly allocated when the
//  use count goes to 0.
//!
//! Exercise 13.26:
//! Write your own version of the StrBlob class described in the previous exercise.
//!

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <StrBlob.h>

//! for ex13.22
//! value like.
class HasPtr
{
public:
    //! default constructor.
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }

    //! copy constructor.
    HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) { }

    //! ex13.22 value like version copy assignment operator
    HasPtr&
    operator = (const HasPtr& hp);

    //! destructor.
    ~HasPtr()
    {
        delete ps;
    }

private:
    std::string *ps;
    int    i;
};



int main()
{
    StrBlob sb1({"111","222","333"});
    StrBlob sb2(sb1) , sb3;

    sb3 = sb2;

    return 0;
}


HasPtr&
HasPtr::operator = (const HasPtr &hp)
{
    delete ps;
    ps = new std::string(*hp.ps);

    i   =   hp.i;

    return *this;
}
