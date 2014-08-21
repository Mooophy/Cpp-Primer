/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       17  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 14.26:
//! Define subscript operators for your StrVec, String, StrBlob, and StrBlobPtr classes.
//!
//! Exercise 14.27:
//! Add increment and decrement operators to your StrBlobPtr class.
//!
//! Exercise 14.28:
//! Define addition and subtraction for StrBlobPtr so that these operators
//! implement pointer arithmetic (§ 3.5.3, p. 119).
//!
//! Exercise 14.29:
//! We did not define a const version of the increment and decrement operators. Why not?
//  Because ++ and -- change the state of the object. Hence ,it's meaningless to do so.
//!
#include <iostream>
#include <vector>
#include <algorithm>

#include "Sales_data.h"
#include "date.h"
#include "StrBlob.h"
#include "strvec.h"
#include "string.h"


int main()
{
    StrBlob sb({"111","111","111","111"});

    StrBlobPtr wp(sb, 2);

    wp.decr();



    return 0;
}







