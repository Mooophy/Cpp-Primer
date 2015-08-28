/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       21  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 15.7:
// Define a class that implements a limited discount strategy, which applies
// a discount to books purchased up to a given limit. If the number of copies
// exceeds that limit, the normal price applies to those purchased beyond the
// limit.
//

#include <iostream>
#include <string>

#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"

double print_total (std::ostream& os, const Quote& item, size_t n);
int main()
{
    // ex15.6
    Quote q("textbook", 10.60);
    Bulk_quote bq("textbook", 10.60, 10, 0.3);
    Limit_quote lq("Bible", 10.60, 10 , 0.3);

    print_total(std::cout, q, 5);
    print_total(std::cout, bq, 5);
    print_total(std::cout , lq, 5);

    return 0;
}

double print_total(std::ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);

    os << "ISBN:" << item.isbn()
       << "# sold: " << n << " total due: " << ret << std::endl;

    return ret;
}
