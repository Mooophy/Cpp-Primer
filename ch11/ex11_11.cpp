//
//  ex11_11.cpp
//  Exercise 11.11
//
//  Created by pezy on 12/15/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Redefine bookstore without using decltype.

#include "../ch07/ex7_26.h"
#include <set>

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

int main()
{
    using compareType = bool (*)(const Sales_data &lhs, const Sales_data &rhs);
    //typedef bool(*compareType)(const Sales_data &lhs, const Sales_data &rhs);
    std::multiset<Sales_data, compareType> bookstore(compareIsbn);
}