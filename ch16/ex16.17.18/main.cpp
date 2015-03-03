/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       02  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 16.17:
//! What, if any, are the differences between a type parameter that is declared
//! as a typename and one that is declared as a class? When must typename be used?
//!
//  There is no difference. typename and class are interchangeable in the
//  declaration of a type template parameter.
//  You do, however, have to use class (and not typename) when declaring a
//  template template parameter.
//
//  When we want to inform the compiler that a name represents a type, we must use
//  the keyword typename, not class
//!
//! Exercise 16.18:
//! Explain each of the following function template declarations and identify
//! whether any are illegal. Correct each error that you find.
//!

#include <vector>
#include <iostream>

template <typename T, typename U, typename V> void f1(T, U, V);
//!                   ^^^^^^^^ added to fix the error

template <typename T> T f2(T&);
//!                        ^^

template <typename T> inline T foo(T, unsigned int*);
//!                   ^^^^^^ inline must be after template

template <typename T> T f4(T, T);
//!                   ^ -- return type should be provided

typedef char C;
//!          ^
//!the template declatation below hides this typedef
    template <typename Ctype> Ctype f5(Ctype a);

int main()
{


    return 0;
}
