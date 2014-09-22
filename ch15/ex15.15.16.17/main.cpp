/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       23  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 15.15:
//! Define your own versions of Disc_quote and Bulk_quote.
//!
//! Exercise 15.16:
//! Rewrite the class representing a limited discount strategy, which you wrote
//! for the exercises in § 15.2.2 (p. 601), to inherit from Disc_quote.
//!
//! Exercise 15.17:
//! Try to define an object of type Disc_quote and see what errors you get from
//! the compiler.
//  error: cannot declare variable 'd' to be of abstract type 'Disc_quote'
//!           Disc_quote d;
//!                      ^
//  note:  because the following virtual functions are pure within 'Disc_quote':
//!  class Disc_quote : public Quote
//!        ^
//  note: 	virtual double Disc_quote::net_price(std::size_t) const
//!  virtual double net_price(std::size_t n) const override = 0;
//!                 ^


#include <iostream>
#include <string>

#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"
#include "disc_quote.h"



int main()
{
	/*
	error C2259 : 'Disc_quote' : cannot instantiate abstract class
	1>          due to following members :
	1>          'double Disc_quote::net_price(size_t) const' : is abstract
	*/
    Disc_quote d;

    return 0;
}
