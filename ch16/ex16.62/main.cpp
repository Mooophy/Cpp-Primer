/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       2  Mar 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 16.62:
// Define your own version of hash<Sales_data> and define an unordered_multiset of Sales_data
// objects. Put several transactions into the container and print its contents.
//
//  keep all template codes in the header.
//

#include <iostream>
#include <memory>
#include <unordered_set>
#include "Sales_data.h"

int main()
{
    // test for ex16.62
    std::unordered_multiset<Sales_data> mset;
    Sales_data sd("Bible", 10, 0.98);

    mset.emplace(sd);
    mset.emplace("C++ Primer", 5, 9.99);

    for(const auto &item : mset)
        std::cout << "the hash code of " << item.isbn()
                  <<":\n0x" << std::hex << std::hash<Sales_data>()(item)
                  << "\n";

    return 0;
}
