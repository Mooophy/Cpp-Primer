/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       28  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 15.30:
// Write your own version of the Basket class and use it to compute prices
// for the same transactions as you used in the previous exercises.
//


#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"
#include "disc_quote.h"
#include "basket.h"


int main()
{
    Basket basket;

    for (unsigned i = 0; i != 10; ++i)
        basket.add_item(Bulk_quote("Bible", 20.6, 20, 0.3));

    for (unsigned i = 0; i != 10; ++i)
        basket.add_item(Bulk_quote("C++Primer", 30.9, 5, 0.4));

    for (unsigned i = 0; i != 10; ++i)
        basket.add_item(Quote("CLRS", 40.1));

    std::ofstream log("log.txt", std::ios_base::app|std::ios_base::out);

    basket.total_receipt(log);
    return 0;
}
