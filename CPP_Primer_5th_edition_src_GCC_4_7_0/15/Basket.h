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

#ifndef BASKET_H
#define BASKET_H

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <cstddef>
#include <stdexcept>
#include <memory>
#include "Quote.h"

// holds items being purchased
class Basket {
public:
	// Basket uses synthesized default constructor and copy-control members
	void add_item(const std::shared_ptr<Quote> &sale)  
        { items.insert(sale); }

	void add_item(const Quote& sale) // copy the given object
      { items.insert(std::shared_ptr<Quote>(sale.clone())); }

	void add_item(Quote&& sale)      // move the given object
      { items.insert(
	      std::shared_ptr<Quote>(std::move(sale).clone())); }

    // prints the total price for each book 
	// and the overall total for all items in the basket
    double total_receipt(std::ostream&) const;

	// for debugging purposes, prints contents of the basket
	void display (std::ostream&) const;
private:
	// function to compare shared_ptrs needed by the multiset member
	static bool compare(const std::shared_ptr<Quote> &lhs,
	                    const std::shared_ptr<Quote> &rhs)
		{ return lhs->isbn() < rhs->isbn(); }

	// multiset to hold multiple quotes, ordered by the compare member
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> 
	              items{compare}; 
};

#endif
