/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       02  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 16.5:
//! Write a template version of the print function from § 6.2.4 (p. 217) that
//! takes a reference to an array and can handle arrays of any size and any
//! element type.
//!

#include <iostream>
#include <vector>
#include <list>
#include <string>

/** @note
 *  1   any array is essentially a pointer, so the &ref here is a reference to pointer.
 *  2   size must be captured here to manage the loop.
 */
template<typename T, unsigned size>
void print(const T(&ref)[size])
{
    if (ref)
    {
        auto p = ref;
        for (unsigned i = 0; i != size; ++i)
            std::cout << *p++ << std::endl;
    }
}

int main()
{
    std::string p[] = {"ssss","aaa","ssssss"};
    char c[] = {'a','b','c','d'};
    int  i[] = {1,2,3,4,5};
    print(i);
    print(c);
    print(p);

    return 0;
}

