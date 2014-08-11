/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       01  JAN 2014
 *  @remark
 ***************************************************************************/
//!
//! Exercise 13.27:
//! Define your own reference-counted version of HasPtr.
//!

#include <string>
#include <iostream>



//! for ex13.27
class HasPtr
{
public:
    //! default constructor.
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0), useCounter(new std::size_t(1)) { }

    //! copy constructor.
    HasPtr(const HasPtr& rhs) : ps(rhs.ps), i(rhs.i), useCounter(rhs.useCounter)
    {
        ++*useCounter;
    }


    HasPtr&
    operator = (const HasPtr& rhs);


    ~HasPtr()
    {
        if(--*useCounter == 0)
        {
            delete ps;
            delete useCounter;
        }
    }

private:
    std::string* ps;
    int    i;
    std::size_t* useCounter;
};



int main()
{
    HasPtr hp("aaaaaa"), hp2;
    HasPtr hp1(hp);

    hp2 = hp1;

    return 0;
}


inline HasPtr&
HasPtr::operator =(const HasPtr &rhs)
{
    ++*rhs.useCounter;
    if(--*useCounter == 0)
    {
        delete  useCounter;
        delete  ps;
    }

    ps = rhs.ps;
    useCounter = rhs.useCounter;
    i = rhs.i;

    return *this;

}

