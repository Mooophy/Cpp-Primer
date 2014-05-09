/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       01  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 15.39:
//! Implement the Query and Query_base classes. Test your application by
//! evaluating and printing a query such as the one in Figure 15.3 (p. 638).
//!
//! Exercise 15.40:
//! In the OrQuery eval function what would happen if its rhs member returned
//! an empty set? What if its lhs member did so? What if both rhs and lhs
//! returned empty sets?
//  Nothing special will happen.  The codes as following:
//          std::shared_ptr<std::set<line_no>> ret_lines =
//                  std::make_shared<std::set<line_no>>(left.begin(), left.end());
//!                 ^^^^^^^^^^^^^^^^
//  Since std::make_shared will allocate dynamically a new std::set, nothing will
//  be added into this std::set if any set is empty.The codes in main function
//  proves this.
//!

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include "queryresult.h"
#include "textquery.h"
#include "query_base.h"
#include "query.h"
#include "andquery.h"
#include "orquery.h"
#include "notquery.h"

int main()
{
    std::ifstream file("test.txt");

    TextQuery tQuery(file);

    Query q = Query("fieryzzz")  | Query("wind");

    std::cout << q.eval(tQuery);

    return 0;
}

