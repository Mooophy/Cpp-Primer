/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       06  JAN 2014
 *  @remark
 ***************************************************************************/
//!
//! Exercise 13.45:
//! Distinguish between an rvalue reference and an lvalue reference.
//  Lvalues Persist; Rvalues Are Ephemeral
//  Looking at the list of lvalue and rvalue expressions, it should be clear
//  that lvalues and rvalues differ from each other in an important manner:
//  Lvalues have persistent state, whereas rvalues are either literals or
//  temporary objects created in the course of evaluating expressions.
//  Because rvalue references can only be bound to temporaries, we know that
//  • The referred-to object is about to be destroyed
//  • There can be no other users of that object
//! Exercise 13.46:
//! Which kind of reference can be bound to the following initializers?



#include <vector>


int f(){}

int main()
{

    std::vector<int> vi(100);

    int&& r1 = f();
    int& r2 = vi[0];
    int& r3 = r1;
    int&&r4 = vi[0] * f();

    return 0;
}
