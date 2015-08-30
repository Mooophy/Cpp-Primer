/***************************************************************************
*  @file       ex14_44.cpp
*  @author     Yue Wang
*  @date       21  Jan 2014
*              17  Jun 2015  
*  @remark     This code is for the exercises from C++ Primer 5th Edition
*  @note
***************************************************************************/
//
// Exercise 14.44:
// Write your own version of a simple desk calculator that can handle binary operations.
//

#include <iostream>
#include <string>
#include <map> 
#include <functional> 

int add(int i, int j){ return i + j; }
auto mod = [](int i, int j){ return i % j; };
struct Div{ int operator ()(int i, int j) const { return i / j; } };

auto binops = std::map<std::string, std::function<int(int, int)>>
{
    { "+", add },                               // function pointer 
    { "-", std::minus<int>() },                 // library functor 
    { "/", Div() },                             // user-defined functor 
    { "*", [](int i, int j) { return i*j; } },  // unnamed lambda 
    { "%", mod }                                // named lambda object 
};


int main()
{
    while ( std::cout << "Pls enter as: num operator num :\n", true )
    {
        int lhs, rhs; std::string op;
        std::cin >> lhs >> op >> rhs;
        std::cout << binops[op](lhs, rhs) << std::endl;
    }

    return 0;
}
