/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       07  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 16.47:
//! Write your own version of the flip function
//! and test it by calling functions that have lvalue and rvalue reference parameters.
//!

#include <iostream>
#include <memory>

void func_lvalue(std::string& lhs, std::string& rhs)
{
    lhs = "Wang\n";
    rhs = "Alan\n";
}

void func_rvalue(int&& lhs, int&& rhs)
{
    //! allocate enough space
    std::allocator<int> alloc;
    int* data(alloc.allocate(3));

    //! move into the spaced newly allocated
    alloc.construct(data    , lhs);
    alloc.construct(data +1 , 0);
    alloc.construct(data +2 , rhs);

    //! print
    for (auto p = data; p != data + 3;  ++p)
        std::cout << *p << "\n";

    //! destroy and deallocation
    for (auto p = data +3; p != data;    )
        alloc.destroy(--p);
    alloc.deallocate(data,3);
}

template<typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2)
{
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

int main()
{
    //! test for lvalue reference
    /*
    std::string s1, s2;
    flip(func_lvalue, s1, s2);
    std::cout << s1 << s2;
    */

    //! test for rvalue reference
    flip(func_rvalue, 99,88);


}
