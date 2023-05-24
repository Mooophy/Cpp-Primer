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

#include <set>
using std::multiset;

#include <map>
using std::map;

#include <string>
using std::string;

#include <utility>
using std::pair;

#include <iostream>
using std::cout; using std::endl;

#include "Sales_data.h"      
#include "make_plural.h"

// SDComp points to a function that compares two Sales_data objects
typedef bool(*SDComp)(const Sales_data&, const Sales_data&);

// bookstore can have several transactions with the same ISBN
// elements in bookstore will be in ISBN order
multiset<Sales_data, decltype(compareIsbn)*> 
	bookstore(compareIsbn);

// alternative way to declare bookstore using a lambda
multiset<Sales_data, SDComp> 
	bookstore2([](const Sales_data &l, const Sales_data &r)
                 { return l.isbn() < r.isbn(); });

int main() 
{
	map <string, size_t> word_count; // empty map
	
	// insert a value-initialized element with key Anna; 
	// assign 1 to the value of that element
	word_count["Anna"] = 1;  

	// fetch the element indexed by Anna; prints 1
	cout << word_count["Anna"] << endl;  
	
	++word_count["Anna"];        // fetch the element and add 1 to it
	cout << word_count["Anna"] << endl; // prints 2
	
	// various ways to add word to word_count 
	string word; 
	word_count.insert({word, 1});
	word_count.insert(make_pair(word, 1));
	word_count.insert(pair<string, size_t>(word, 1));
	word_count.insert(map<string, size_t>::value_type(word, 1));
	
	typedef map<string,size_t>::value_type valType;
	word_count.insert(valType(word, 1));
	
	// use value returned by insert
	pair<map<string, size_t>::iterator, bool> insert_ret;

	// if Anna not already in word_count, insert it with value 1
	insert_ret = word_count.insert({"Anna", 1});
	
	if (insert_ret.second == false)    // Anna was already in the map
	    insert_ret.first->second++;    // increment current value
	cout << word_count["Anna"] << endl;

	// get an iterator to an element in word_count
	auto map_it = word_count.begin();
	
	// *map_it is a reference to a pair<const string, size_t> object
	cout << map_it->first;         // prints the key for this element
	cout << " " << map_it->second; // prints the value of the element
	++map_it->second;     // ok: we can change the value through an iterator
	return 0;
}
