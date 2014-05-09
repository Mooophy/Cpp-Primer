/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       31  DEC 2013
 *  @remark
 ***************************************************************************/
//! Exercise 13.14:
//! Assume that numbered is a class with a default constructor that generates
//! a unique serial number for each object, which is stored in a data member
//! named mysn. Assuming numbered uses the synthesized copy-control members and
//! given the following function:
//!
//      void f (numbered s) { cout << s.mysn << endl; }
//! what output does the following code produce?
//      numbered a, b = a, c = b;
//      f(a); f(b); f(c);
//!  x
//!  x
//!  x
//!      i.e.three identical numbers. --correct!
//!
//! Exercise 13.15:
//! Assume numbered has a copy constructor that generates a new serial number.
//! Does that change the output of the calls in the previous exercise?
//! If so, why? What output gets generated?
//! Yes. the ouput will change.
//! 102
//! 103
//! 104
//!                         --correct!
//!
//! Exercise 13.16:
//! What if the parameter in f were const numbered&? Does that change the
//! output? If so, why? What output gets generated?
//!
//! Yes. Because ,if so, no copy operation any more.The function f just print
//! the object of Numbered directly whose mySn is unique. But if without the newly
//! defined copy constructor , it will still be :
//! 1
//! 1
//! 1.

#include <string>
#include <iostream>
#include <vector>
#include <memory>

struct Numbered
{
    //! for ex13.14
    Numbered()
    {
        static unsigned i = 0;
        ++i;
        mySn = i;
    }

    //! for ex13.15
    /*
    Numbered(const Numbered& num)
    {
        static unsigned j = 99;
        ++j;
        mySn = j;
    }
    */

    unsigned mySn;
};

//void f (Numbered s)

//!
void f(Numbered& s)
{
    std::cout << s.mySn << std::endl;
}
int main()
{
    Numbered a, b = a, c = b;

    f(a); f(b); f(c);

    return 0;
}

