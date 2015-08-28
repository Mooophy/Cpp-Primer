/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       27  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 15.26:
// Define the Quote and Bulk_quote copy-control members to do the same job
// as the synthesized versions. Give them and the other constructors print
// statements that identify which function is running. Write programs using
// these classes and predict what objects will be created and destroyed.
// Compare your predictions with the output and continue experimenting
// until your predictions are reliably correct.
//


#include <iostream>
#include <string>

#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"
#include "disc_quote.h"


int main()
{
    Bulk_quote bq1;
    Bulk_quote bq2("ss", 2.05, 12, 0.3);
    bq2 = std::move(bq2);


    return 0;
}
