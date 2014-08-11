/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       07  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 16.49:
//! Explain what happens in each of the following calls:
//!
//! Exercise 16.50:
//! Define the functions from the previous exercise so that they print an
//! identifying message. Run the code from that exercise. If the calls behave
//! differently from what you expected, make sure you understand why.
//!

#include <iostream>
#include <memory>
#include <sstream>

template <typename T> void f(T)
{
    std::cout << "f(T)\n";
}

template <typename T> void f(const T*)
{
    std::cout << "f(const T*)\n";
}
template <typename T> void g(T)
{
    std::cout << "template <typename T> void g(T)\n";
}
template <typename T> void g(T*)
{
    std::cout << "template <typename T> void g(T*)\n";
}



int main()
{
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;

    //g(42);    //template <typename T> void g(T ); --is called
    //g(p);     //template <typename T> void g(T*); --is called
    //g(ci);      //template <typename T> void g(T)   --is called
    //g(p2);      //template <typename T> void g(T*)    --is called
    //f(42);    //f(T)
    //f(p);     //f(T)
    //f(ci);    //f(T)
    f(p2);      //f(const T*)



}
