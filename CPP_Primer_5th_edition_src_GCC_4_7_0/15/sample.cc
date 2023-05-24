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

#include <iostream>
#include <cstddef>
using std::size_t;

using std::cout; 
using std::endl;
#include "Quote.h"

int main()
{
	Quote basic("0-201-54848-8", 45);
	Bulk_quote bulk("0-201-82470-1", 45, 3, .15);

	// basic has type Quote; bulk has type Bulk_quote
	print_total(cout, basic, 20); // calls Quote version of net_price 
	print_total(cout, bulk, 20);  // calls Bulk_quote version of net_price 
	Quote base("0-201-82470-1", 50);
	Bulk_quote derived("0-201-82470-1", 50, 5, .19);
	cout << derived.net_price(20); // calls Bulk_quote::net_price
	cout << endl;

	base = derived;        // copies the Quote part of derived into base
	cout << base.net_price(20);    // calls Quote::net_price
	cout << endl;

	Quote &item = derived; // dynamic and static types of item differ
	cout << item.net_price(20);    // calls Bulk_quote::net_price

	item.isbn();           // isbn is not virtual, calls Bulk::isbn
	cout << endl;

	return 0;
}


