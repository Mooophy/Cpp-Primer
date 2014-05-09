/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       21  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 14.45:
//! Write conversion operators to convert a Sales_data to string and to double.
//! What values do you think these operators should return?
//!
//! Exercise 14.46:
//! Explain whether defining these Sales_data conversion operators is a good
//! idea and whether they should be explicit.
//  It's a bad idea to do so, because these conversion is misleading.
//  "explicit" should be added to prevent implicit conversion.
//!
//! Exercise 14.47:
//! Explain the difference between these two conversion operators:
//!	
//! Exercise 14.48:
//! Determine whether the class you used in exercise 7.40 from § 7.5.1 (p. 291)
//! should have a conversion to bool. If so, explain why, and explain whether
//! the operator should be explicit. If not, explain why not.
//!
//! Exercise 14.49:
//! Regardless of whether it is a good idea to do so, define a conversion to
//! bool for the class from the previous exercise.
//!		

struct Integral
{
    operator const int();   //  meaningles, it will be ignored by compiler.
    operator int() const;   // promising that this operator will not change the state of the obj
};

//!
//! Exercise 14.48:
//! Determine whether the class you used in exercise 7.40 from § 7.5.1 (p. 291)
//! should have a conversion to bool. If so, explain why, and explain whether the
//! operator should be explicit. If not, explain why not.
//!
//  A conversion to bool can be useful for the class Date. But it must be an explicit one
//  to prevent any automatic conversion.
//!
//! Exercise 14.49:
//! Regardless of whether it is a good idea to do so, define a conversion to bool
//! for the class from the previous exercise.
//!


#include <iostream>
#include <string>
#include <map>
#include <functional>

int main()
{

    return 0;
}







