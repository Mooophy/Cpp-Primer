/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       10  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 13.56: What would happen if we defined sorted as:
/*
        Foo Foo::sorted() const &
            {
                Foo ret(*this);
                return ret.sorted();
            }
*///    recursion and stack overflow?   -- correct!
//!
//! Exercise 13.57: What if we defined sorted as:

//          Foo Foo::sorted() const &
//              { return Foo(*this).sorted(); }
//! This version works, as it will call the move verion which can return control
//! to the caller.
//!
//! Exercise 13.58: Write versions of class Foo with print statements in their
//! sorted functions to test your answers to the previous two exercises.
//!
#include <iostream>
#include <vector>
#include <algorithm>

class Foo
{
public:
    Foo sorted() &&;         // may run on modifiable rvalues
    Foo sorted() const &;    // may run on any kind of Foo
private:
    std::vector<int> data;
};

//! infinit recursion
/*
Foo Foo::sorted() const &
{
    Foo ret(*this);
    return ret.sorted();
}
*/

Foo Foo::sorted() &&
{
    std::sort(data.begin(), data.end());
    std::cout << "Rvalue version\n";
    return *this;
}
Foo Foo::sorted() const &
{
    std::cout << "Lvalue version\n";
    return Foo(*this).sorted();
}

int main()
{
    Foo foo;
    foo.sorted();
    std::cout << "exit\n";
    return 0;
}
