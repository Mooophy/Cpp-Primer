/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       28  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 15.27:
//! Redefine your Bulk_quote class to inherit its constructors.
//  rules:  1. only inherit from the direct base class.
//          2. default,copy and move constructors can not inherit.
//          3. any data members of its own are default initialized.
//          4. the rest details are in the section section 15.7.4.
//!


#include <iostream>
#include <string>

#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"
#include "disc_quote.h"


int main()
{
    Bulk_quote bq("sss",20.0,2,0.3);
    return 0;
}
