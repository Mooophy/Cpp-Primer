/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       01  JAN 2014
 *  @remark
 ***************************************************************************/
//!
//! Exercise 13.20:
//! Explain what happens when we copy, assign, or destroy objects of our TextQuery
//! and QueryResult classes from § 12.3 (p. 484).
//
//!
//! Exercise 13.21:
//! Do you think the TextQuery and QueryResult classes need to define their own
//! versions of the copy-control members? If so, why? If not, why not? Implement
//! whichever copy-control operations you think these classes require.
//!
//  No copy-control members needed.
//  Because, all these classes are using smart poitners to manage dynamic memory which
//  can be freed automatically by calling synthesized destructors. The objects of these
//  classes should share the same dynamic memory.Hence no user-defined version needed
//  as well.
//!
//! Exercise 13.22:
//! Assume that we want HasPtr to behave like a value. That is, each object should
//! have its own copy of the string to which the objects point. We’ll show the
//! definitions of the copy-control members in the next section. However, you already
//! know everything you need to know to implement these members. Write the HasPtr copy
//! constructor and copy-assignment operator before reading on.
//  Discussing on SO:
//  http://stackoverflow.com/questions/20864892/is-it-a-good-practice-to-point-to-a-new-address-on-free-store-when-dynamicly-all
//!

#include <string>
#include <iostream>
#include <vector>
#include <memory>

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

    HasPtr h1("111"), h2("222");

    h1 = h2;




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
