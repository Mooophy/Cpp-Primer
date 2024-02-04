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

#include <list>
using std::list;

#include <vector>
using std::vector;

#include <tuple>
using std::tuple; using std::get; 
using std::tuple_size; using std::tuple_element;
using std::make_tuple;

#include <string>
using std::string; 

#include <iostream>
using std::cout; using std::endl; 

int main()
{
	// tuple that represents a bookstore transaction: 
	// ISBN, count, price per book
	auto item = make_tuple("0-999-78345-X", 3, 20.00);
	auto book = get<0>(item);      // returns the first member of item
	auto cnt = get<1>(item);       // returns the second member of item
	auto price = get<2>(item)/cnt; // returns the last member of item
	get<2>(item) *= 0.8;           // apply 20% discount
	
	cout << book << " " << cnt << " " << price << endl;

	typedef decltype(item) trans; // trans is the type of item 
	
	// returns the number of members in object's of type trans
	size_t sz = tuple_size<trans>::value;  // returns 3

	// cnt has the same type as the second member in item
	tuple_element<1, trans>::type cnt2 = get<1>(item); // cnt is an int
	tuple_element<0, trans>::type book2 = get<0>(item);
	tuple_element<2, trans>::type price2 = get<2>(item);
	cout << tuple_size<trans>::value << endl;
	
	cout << book2 << " " << cnt2 << " " << price2 << endl;
	
	tuple<size_t, size_t, size_t> threeD;  // all three members set to 0
	tuple<string, vector<double>, int, list<int>>
	    someVal("constants", {3.14, 2.718}, 42, {0,1,2,3,4,5});
	
	return 0;
}
