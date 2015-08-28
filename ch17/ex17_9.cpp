/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       3  Mar 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 17.9: Explain the bit pattern each of the following bitset objects contains:
//     (a) bitset<64> bitvec(32);
//          0000000000000000000000000000000000000000000000000000000000100000
//                                      //                           ^
//     (b) bitset<32> bv(1010101);
//          00000000000011110110100110110101
//          // note that the argument here is decemal
//     (c) string bstr; cin >> bstr; bitset<8>bv(bstr);
//          depends on what has been input.
//



#include <iostream>
#include <bitset>

//#include "Sales_data.h"


int main()
{
    std::bitset<32> bv(1010101);

    std::cout << bv << std::endl;
}
