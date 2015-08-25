/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       21  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 15.1:
// What is a virtual member?
//  A virtual member in a base class expects its derived class define its own version.
//  In particular base classes ordinarily should define a virtual destructor, even if
//  it does no work.
//
// Exercise 15.2:
// How does the protected access specifier differ from private?
//      private members     :   base class itself and friend can access
//      protected members   :   base class itself, friend and derived classes can access
// Exercise 15.3:
// Define your own versions of the Quote class and the print_total function.
//
//
#include <iostream>
#include <string>
#include <map>
#include <functional>

#include "quote.h"

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
