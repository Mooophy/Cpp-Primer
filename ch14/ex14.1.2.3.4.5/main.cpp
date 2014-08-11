/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       10  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 14.1:
//! In what ways does an overloaded operator differ from a built-in operator?
//  1   An overloaded function must either be a member of class or have at least
//      one parameter of class type.
//  2   A few operators guarantee the order in which operands are evaluated.
//      These guarantees do not apply to overloaded operators. In particualr,
//      the operand-evaluation guarantees of the logical AND, OR, and comma
//      operators are not preserved.
//! In what ways are overloaded operators the same as the built-in operators?
//  1   An overloaded operator has the same precedence and associativity as the
//      corresponding built-in operator,like
//          x ==  y + z ;
//      is always equivalent to
//          x == (y + z);
//!
//! Exercise 14.2:
//! Write declarations for the overloaded input, output, addition, and compound
//! -assignment operators for Sales_data.
//!
//! Exercise 14.3:
//! Both string and vector define an overloaded == that can be used to compare
//! objects of those types. Assuming svec1 and svec2 are vectors that hold
//! strings, identify which version of == is applied in each of the following
//! expressions:
/*
            (a) "cobble" == "stone"     //  by string's
            (b) svec1[0] == svec2[0]    //  by string's
            (c) svec1 == svec2          //  by vector's
            (d) svec1[0] == "stone"     //  by string's
*/
//!
//! Exercise 14.4:
//! Explain how to decide whether the following should be class members:
/*
        (a) %       --  symmetric operator. Hence, non-member
        (b) %=      --  changing state of objects. Hence, member
        (c) ++      --  changing state of objects. Hence, member
        (d) ->      --  = [] () -> must be member
        (e) <<      --  non-member
        (f) &&      --  symetric , non-member
        (g) ==      --  symetric , non-member
        (h) ()      --  = [] () -> must be member
*/
//!
//! Exercise 14.5:
//! In exercise 7.40 from § 7.5.1 (p. 291) you wrote a sketch of one of the
//! following classes. Decide what, if any, overloaded operators your class
//! should provide.
//!
/*
        (a) Book        <<  >>  ==  !=  []
        (b) Date        <<  >>  ==  !=  []  >   <   >=  <=  +=  -=  ++  --  -
        (c) Employee    <<  >>  ==  !=  []
        (d) Vehicle     <<  >>  ==  !=
        (e) Object      <<  >>  ==  !=
        (f) Tree        <<  >>  ==  !=  []
*/
#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>
#include <Alan.h>


int main()
{
    alan("main() is returned\n");

    return 0;
}











