/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       17  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 14.30:
//! Add dereference and arrow operators to your StrBlobPtr class and to the
//! ConstStrBlobPtr class that you defined in exercise 12.22 from § 12.1.6
//! (p. 476). Note that the operators in constStrBlobPtr must return const
//! references because the data member in constStrBlobPtr points to a const
//! vector.
//!
//! Exercise 14.31:
//! Our StrBlobPtr class does not define the copy constructor, assignment
//! operator, or a destructor. Why is that okay?
//  Applying the Rule of 3/5:
//  There is no dynamic allocation to deal with , so the synthesized destructor
//  is enough.Morever, no unique is needed . Hence, the synthesized ones can handle
//  all the corresponding operations.
//!
//! Exercise 14.32:
//! Define a class that holds a pointer to a StrBlobPtr. Define the overloaded
//! arrow operator for that class.
//!
#include <iostream>
#include <vector>
#include <algorithm>

#include "Sales_data.h"
#include "date.h"
#include "StrBlob.h"
#include "strvec.h"
#include "string.h"
#include "wy_conststrblobptr.h"
#include "strblobptr_pointer.h"


int main()
{
    StrBlob sb({"a","b","a"});
    StrBlobPtr sbp(sb);

    StrBlobPtr_pointer p(&sbp);


    return 0;
}







