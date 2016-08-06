/***************************************************************************
 *  @file       main.cpp
 *  @author     Hoesel Markus
 *  @date       11  Apr 2016
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 15.9:
// When is it possible for an expression’s static type to differ from its 
// dynamic type? Give three examples in which the static and dynamic type differ.
//

#include <iostream>
#include <string>

#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"

int main()
{
    Bulk_quote bulk_quote("bulk_quote_1", 10.10, 10, 0.5);

    // The pointer is of static type Quote, but it's dynamic type is Bulk Quote
    // Because of polymorphism the Bulk Quote implementation of the net_price()
    // method gets called.
    Quote *quote_pointer = &bulk_quote;
    quote_pointer->net_price(5);

    // The reference is of static type Quote, but it's dynamic type is Bulk Quote
    // Like with the pointer, the Bulk Quote implementation of the net_price()
    // method gets called.
    Quote &quote_reference = bulk_quote;
    quote_reference.net_price(5);

    // The static type of this variable is Quote. Here the Bulk Quote object
    // gets upcasted. The Quote part of bulk_quote gets copied into quote, but
    // the rest is not handled. Because of the cast the Quote implementation of
    // the net_price() method gets called.
    Quote quote = bulk_quote;
    quote.net_price(5);

    return 0;
}
