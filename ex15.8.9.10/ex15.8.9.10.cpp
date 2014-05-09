/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       21  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 15.8:
//! Define static type and dynamic type.
//  The static type of an expression is always known at compile time.
//  The dynamic type is the type of the object in memory that the variable or
//  expression reprensents. The dynamic type may not be known until run time.
//!
//! Exercise 15.9:
//! When is it possible for an expression’s static type to differ from its
//! dynamic type? Give three examples in which the static and dynamic type differ.
//  The static type of a pointer or reference to a base class may differ from
//  its dynamic type. Anying like this can be an example
//!
//! Exercise 15.10:
//! Recalling the discussion from §8.1 (p. 311), explain how the program on
//! page 317 that passed an ifstream to the Sales_data read function works.
//  the function takes a std::istream from which std::ifstream is derived.
//  Hence the ifstream object "is a" istream ,which is why it works.
//!

#include <iostream>
#include <string>
#include <istream>
#include <fstream>

#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"

double print_total (std::ostream& os, const Quote& item, size_t n);
int main()
{
    return 0;
}

double print_total(std::ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);

    os << "ISBN:" << item.isbn()
       << "# sold: " << n << " total due: " << ret << std::endl;

    return ret;
}






