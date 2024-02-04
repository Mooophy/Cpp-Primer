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

#include "Quote.h"

#include <algorithm>
using std::min;

#include <cstddef>
using std::size_t;

#include <iostream>
using std::ostream; using std::endl; 
using std::cout;

// calculate and print the price for the given number of copies, applying any discounts 
double print_total(ostream &os, 
                   const Quote &item, size_t n)
{
	// depending on the type of the object bound to the item parameter
	// calls either Quote::net_price or Bulk_quote::net_price
	double ret = item.net_price(n); 
    os << "ISBN: " << item.isbn() // calls Quote::isbn
       << " # sold: " << n << " total due: " << ret << endl;
 	return ret;
}

// if the specified number of items are purchased, use the discounted price 
double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= quantity)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

// use discounted price for up to a specified number of items
// additional items priced at normal, undiscounted price
double Lim_quote::net_price(size_t cnt) const
{
    size_t discounted = min(cnt, quantity);
    size_t undiscounted = cnt - discounted;
    return discounted * (1 - discount) * price 
           + undiscounted * price;
}

