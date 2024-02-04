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
using std::cout; using std::endl;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr; using std::make_shared;

#include "Quote.h"

int main ()
{
	Quote base("0-201-82470-1", 50);  
	Bulk_quote bulk("0-201-54848-8", 50, 10, .25); 

	// ok: but probably not what is wanted---
	//     the objects in basket have no derived members
	vector<Quote> basket;
	basket.push_back(Quote("0-201-82470-1", 50));

	// ok, but copies only the Quote part of the object into basket
	basket.push_back(Bulk_quote("0-201-54848-8", 50, 10, .25));  
	
	// calls version defined by Quote, prints 750, i.e., 15 * $50
	cout << basket.back().net_price(15) << endl;  
	
	// better approach---store shared_ptrs
	vector<shared_ptr<Quote>> basket2;
	
	basket2.push_back(make_shared<Quote>("0-201-82470-1", 50));  
	basket2.push_back(
		make_shared<Bulk_quote>("0-201-54848-8", 50, 10, .25));  
	
	// calls the version defined by Quote; 
	// prints 562.5, i.e., 15 * $50 less the discount
	cout << basket2.back()->net_price(15) << endl; 

	return 0;
}
