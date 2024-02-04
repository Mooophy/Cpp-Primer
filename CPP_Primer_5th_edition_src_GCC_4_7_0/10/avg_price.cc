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

#include <iterator>
using std::istream_iterator; using std::ostream_iterator;

#include <iostream>
using std::cin; using std::cout;

#include "Sales_item.h"

int main() 
{
	// iterators that can read and write Sales_items
	istream_iterator<Sales_item> item_iter(cin), eof;
	ostream_iterator<Sales_item> out_iter(cout, "\n");

	// store the first transaction in sum and read the next record
	Sales_item sum = *item_iter++; 

	while (item_iter != eof) {
		// if the current transaction (which is in item_iter) 
		// has the same ISBN
	    if (item_iter->isbn() == sum.isbn())
	        sum += *item_iter++; // add it to sum 
		                         // and read the next transaction
	    else {
	        out_iter = sum;      // write the current sum
	        sum = *item_iter++;  // read the next transaction
	    }
	}
	out_iter = sum;  // remember to print the last set of records

	return 0;
}
