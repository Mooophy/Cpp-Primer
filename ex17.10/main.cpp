/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       6  Mar 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 17.10:
//! Using the sequence 1, 2, 3, 5, 8, 13, 21, initialize a bitset that has a
//! 1 bit in each position corresponding to a number in this sequence. Default
//! initialize another bitset and write a small program to turn on each of the
//! appropriate bits.
//!



#include <iostream>
#include <bitset>
#include <vector>

int main()
{
    std::vector<int> v = {1,2,3,5,8,13,21};
    std::bitset<32> bset;

    for (auto i : v)    bset.set(i);

    std::bitset<32> bset2;
    for (unsigned i = 0; i != 32; ++i)
        bset2[i] = bset[i];

    std::cout <<bset <<std::endl;
    std::cout <<bset2<<std::endl;
}
