/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       14  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 14.18:
//! Define relational operators for your StrBlob, StrBlobPtr, StrVec, and
//! String classes.
//      StrBlob:    compare the std::vector<std::string> it points directly, using
//                  the relational operators defined fro std::vector in std.
//
//      StrBlobptr: since there are two data members to be considered, no relational
//                  operators should be implemented.
//
//      StrVec:     A lexicographical comparison is the kind of comparison generally
//                  used to sort words alphabetically in dictionaries; It involves
//                  comparing sequentially the elements that have the same position
//                  in both ranges against each other until one element is not
//                  equivalent to the other. The result of comparing these first
//                  non-matching elements is the result of the lexicographical
//                  comparison.
//
//                               --which was used  implmenting the relational operators
//                  as used in stl for std::vector.
//
//      String:     the same design as done in StrVec.
//!
//! Exercise 14.19:
//! Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define
//! the relational operators? If so, implement them. If not, explain why not.
//!
#include <iostream>
#include <vector>

#include "Sales_data.h"
#include "block.h"
#include "StrBlob.h"
#include "strvec.h"
#include "string.h"
#include <algorithm>

int main()
{
    String lhs(" "), rhs("   ");

    std::cout << (lhs < rhs) << "\n";


    return 0;
}







