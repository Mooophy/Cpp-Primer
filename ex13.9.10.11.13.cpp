/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       31  DEC 2013
 *  @remark
 ***************************************************************************/
//!
//! Exercise 13.9:
//! What is a destructor? What does the synthesized destructor do? When is a destructor synthesized?
//  The destructor is a member function with the name of the class prefixed by a tilde (~).
//  It has no return value and takes no parameters:
class Foo
{
public:
    ~Foo();    // destructor
};
//
//  As with the copy constructor and the copy-assignment operator, for some classes,
//  the synthesized destructor is defined to disallow objects of the type from being
//  destroyed (§ 13.1.6, p. 508). Otherwise, the synthesized destructor has an empty
//  function body.
//
//  When no user-defined destructor, the compiler will define a synthesized version.
//!
//! Exercise 13.10:
//! What happens when a StrBlob object is destroyed? What about a StrBlobPtr?
//! When a StrBlobPter object is destroyed the object dynamicaly allocated will not be
//! freed.
//! When a StrBlob object destroyed, the use count of the dynamic object will decrement.
//! It wiil be freed if no shared_ptr to that dynamic object.
//!
//! Exercise 13.11:
//! Add a destructor to your HasPtr class from the previous exercises.
//!
//! Exercise 13.13:
//! A good way to understand copy-control members and constructors is to define a simple
//! class with these members in which each member prints its name:
//!
//! Add the copy-assignment operator and destructor to X
//! and write a program using X
//! objects in various ways: Pass them as nonreference and reference parameters; dynamically
//! allocate them; put them in containers; and so forth. Study the output until you are
//! certain you understand when and why each copy-control member is used. As you read the output,
//! remember that the compiler can omit calls to the copy constructor.



#include <string>
#include <iostream>
#include <vector>
#include <memory>

/**
 * @brief ex13.13
 */
struct X
{
    X() {std::cout << "X()\n" << std::endl;}
    X(const X&) {std::cout << "X(const X&)\n" << std::endl;}

    X&
    operator = (const X& x)
    {
        std::cout << "operator = (const X&)\n";
        return *this;
    }


    ~X()
    {
        std::cout << "~X()\n";
    }
};


class HasPtr
{
public:
    //! default constructor.
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }

    //! copy constructor.
    HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) { }

    //! Copy-Assignment operator
    HasPtr&
    operator = (const HasPtr& hp)
    {
        *ps = *hp.ps;
        i   = hp.i;
        return *this;
    }

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
    X x,y;
    x = y;
    return 0;
}

