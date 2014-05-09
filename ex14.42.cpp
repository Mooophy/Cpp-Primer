/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       20  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 14.42: Using library function objects and adaptors, define an expression to
//!     (a) Count the number of values that are greater than 1024
//!     (b) Find the first string that is not equal to pooh
//!     (c) Multiply all values by 2
//!

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <stack>


int main()
{
    //! (c)
    std::deque<std::size_t> deq = {1,1111,1234,5678,88888,999999};
    std::stack<std::size_t> stk(deq);

    std::multiplies<std::size_t> multi;

    while(! stk.empty())
    {
        std::cout << multi(stk.top(), 2) << "\n";
        stk.pop();
    }

    //! (b)
    /*
    std::deque<std::string>
            deq = {"pooh","pooh","pooh","pooh","pooh","alan","pooh","pooh","pooh"};
    std::stack<std::string> stk(deq);

    std::not_equal_to<std::string> nEqual;

    while(! stk.empty())
    {
        if(nEqual(stk.top(),"pooh"))    std::cout << stk.top() << "\n";
        stk.pop();
    }
    */

    //! (a)
    /*
    std::deque<std::size_t> deq = {1,1111,1234,5678,88888,999999};
    std::stack<std::size_t> stk(deq);

    std::greater<std::size_t> gtr;
    std::size_t number = 0;

    while(! stk.empty())
    {
        if(gtr(stk.top(), 1024))    ++number;
        stk.pop();
    }

    std::cout << number << "\n";
    */



    return 0;
}







