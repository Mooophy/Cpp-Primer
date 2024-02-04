/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/ 

#include "Query.h"
#include "TextQuery.h"

#include <memory>
using std::shared_ptr; using std::make_shared;

#include <set>
using std::set;

#include <algorithm>
using std::set_intersection;

#include <iostream>
using std::ostream;

#include <cstddef>
using std::size_t;

#include <iterator>
using std::inserter; 

// returns the lines not in its operand's result set
QueryResult
NotQuery::eval(const TextQuery& text) const
{
    // virtual call to eval through the Query operand 
    auto result = query.eval(text);

	// start out with an empty result set
    auto ret_lines = make_shared<set<line_no>>();

	// we have to iterate through the lines on which our operand appears
	auto beg = result.begin(), end = result.end();

    // for each line in the input file, if that line is not in result,
    // add that line number to ret_lines
	auto sz = result.get_file()->size();
    for (size_t n = 0; n != sz; ++n) {
		// if we haven't processed all the lines in result
		// check whether this line is present
		if (beg == end || *beg != n) 
			ret_lines->insert(n);  // if not in result, add this line 
		else if (beg != end) 
			++beg; // otherwise get the next line number in result if there is one
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}

// returns the intersection of its operands' result sets
QueryResult
AndQuery::eval(const TextQuery& text) const
{
    // virtual calls through the Query operands to get result sets for the operands
    auto left = lhs.eval(text), right = rhs.eval(text);

	// set to hold the intersection of left and right
    auto ret_lines = make_shared<set<line_no>>();  

    // writes the intersection of two ranges to a destination iterator
    // destination iterator in this call adds elements to ret
    set_intersection(left.begin(), left.end(), 
                   right.begin(), right.end(),
                   inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

// returns the union of its operands' result sets
QueryResult
OrQuery::eval(const TextQuery& text) const
{
    // virtual calls through the Query members, lhs and rhs 
	// the calls to eval return the QueryResult for each operand
    auto right = rhs.eval(text), left = lhs.eval(text);  

	// copy the line numbers from the left-hand operand into the result set
	auto ret_lines = 
	     make_shared<set<line_no>>(left.begin(), left.end());

	// insert lines from the right-hand operand
	ret_lines->insert(right.begin(), right.end());
	// return the new QueryResult representing the union of lhs and rhs
    return QueryResult(rep(), ret_lines, left.get_file());
}

