/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       9  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 13.52:
//! Explain in detail what happens in the assignments of the HasPtr objects on
//! page 541. In particular, describe step by step what happens to values of hp,
//! hp2, and of the rhs parameter in the HasPtr assignment operator.
//!
//! Exercise 13.53:
//! As a matter of low-level efficiency, the HasPtr assignment operator is not
//! ideal. Explain why. Implement a copy-assignment and move-assignment operator
//! for HasPtr and compare the operations executed in your new move-assignment
//! operator versus the copy-and-swap version.
//  Discussing on SO:
//  http://stackoverflow.com/questions/21010371/why-is-it-not-efficient-to-use-a-single-assignment-operator-handling-both-copy-a
//!

#include "hasptr.h"
#include <utility>
#include <vector>

int main()
{
    //! default constructors are called to construct object hp and hp2
    HasPtr hp("This is hp!\n");
    HasPtr hp2("This is hp2\n");



    hp = std::move(hp2);
    /**
     *  1   call std::move to convert hp2 to a rvalue.
     *  2   Both copy and move constructors are viable, but move constructor a better
     *      match.Hence move constructor is called constructing the parameter rhs.
     *                  ^^^^~~~~~~~~~~~~                        ~~~~~~~~~~~~~~^^^
     *  3   assignment operator =() is called
     *  4   the specific swap is called
     *  5   inside the specific swap(), the std::string* ps and int i are swaped.
     *  6   after swapping, the new *this is returned from the function
     *          HasPtr& HasPtr::operator = (HasPtr rhs)
     *  7   At the end, desructor is called to destroy all object.
     */


    return 0;
}


