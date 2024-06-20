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

#include <memory>
using std::shared_ptr; using std::make_shared;
#include "Basket.h"
#include <iostream>
using std::cout; using std::endl;

int main()
{
	Basket sale;
	sale.add_item(shared_ptr<Quote>(new Quote("123", 45)));
	sale.add_item(shared_ptr<Quote>(new Quote("123", 45)));
	sale.add_item(shared_ptr<Quote>(new Quote("123", 45)));
	sale.add_item(make_shared<Bulk_quote>("345", 45, 3, .15));
	sale.add_item(shared_ptr<Quote>(new Bulk_quote("345", 45, 3, .15)));
	sale.add_item(shared_ptr<Quote>(new Bulk_quote("345", 45, 3, .15)));
	sale.add_item(shared_ptr<Quote>(new Bulk_quote("345", 45, 3, .15)));
	sale.add_item(shared_ptr<Quote>(new Bulk_quote("345", 45, 3, .15)));
	sale.add_item(shared_ptr<Quote>(new Bulk_quote("345", 45, 3, .15)));
	sale.add_item(shared_ptr<Quote>(new Bulk_quote("345", 45, 3, .15)));
	sale.add_item(shared_ptr<Quote>(new Bulk_quote("345", 45, 3, .15)));
	sale.add_item(shared_ptr<Quote>(new Bulk_quote("678", 55, 5, .25)));
	sale.add_item(shared_ptr<Quote>(new Bulk_quote("678", 55, 5, .25)));
	sale.add_item(shared_ptr<Quote>(new Bulk_quote("678", 55, 5, .25)));
	sale.add_item(shared_ptr<Quote>(new Bulk_quote("678", 55, 5, .25)));
	sale.add_item(shared_ptr<Quote>(new Bulk_quote("678", 55, 5, .25)));
	sale.add_item(shared_ptr<Quote>(new Bulk_quote("678", 55, 5, .25)));
	sale.add_item(shared_ptr<Quote>(new Bulk_quote("678", 55, 5, .25)));
	sale.add_item(shared_ptr<Quote>(new Bulk_quote("678", 55, 5, .25)));
	sale.add_item(shared_ptr<Quote>(new Lim_quote("abc", 35, 2, .10)));
	sale.add_item(shared_ptr<Quote>(new Lim_quote("abc", 35, 2, .10)));
	sale.add_item(shared_ptr<Quote>(new Lim_quote("abc", 35, 2, .10)));
	sale.add_item(shared_ptr<Quote>(new Lim_quote("abc", 35, 2, .10)));
	sale.add_item(shared_ptr<Quote>(new Lim_quote("abc", 35, 2, .10)));
	sale.add_item(shared_ptr<Quote>(new Lim_quote("abc", 35, 2, .10)));
	sale.add_item(shared_ptr<Quote>(new Quote("def", 35)));
	sale.add_item(shared_ptr<Quote>(new Quote("def", 35)));

	sale.total_receipt(cout);

	Basket bsk;
	// arguments are the ISBN, price, minimum quantity, and discount
	bsk.add_item(shared_ptr<Quote>(new Bulk_quote("0-201-82470-1", 50, 5, .19)));
	bsk.add_item(shared_ptr<Quote>(new Bulk_quote("0-201-82470-1", 50, 5, .19)));
	bsk.add_item(shared_ptr<Quote>(new Bulk_quote("0-201-82470-1", 50, 5, .19)));
	bsk.add_item(shared_ptr<Quote>(new Bulk_quote("0-201-82470-1", 50, 5, .19)));
	bsk.add_item(shared_ptr<Quote>(new Bulk_quote("0-201-82470-1", 50, 5, .19)));
	bsk.add_item(shared_ptr<Quote>(new Lim_quote("0-201-54848-8", 35, 2, .10)));
	bsk.add_item(shared_ptr<Quote>(new Lim_quote("0-201-54848-8", 35, 2, .10)));
	bsk.add_item(shared_ptr<Quote>(new Lim_quote("0-201-54848-8", 35, 2, .10)));
	bsk.total_receipt(cout);
}
