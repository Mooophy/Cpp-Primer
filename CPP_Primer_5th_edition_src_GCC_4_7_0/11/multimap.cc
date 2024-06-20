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

#include <map>
using std::multimap;

#include <string>
using std::string;

#include <utility>
using std::pair;

#include <iostream>
using std::cout; using std::endl;

int main()
{
    // map from author to title; there can be multiple titles per author
    multimap<string, string> authors;
    // add data to authors
    authors.insert({"Alain de Botton", "On Love"});
    authors.insert({"Alain de Botton", "Status Anxiety"});
    authors.insert({"Alain de Botton", "Art of Travel"});
    authors.insert({"Alain de Botton", 
		                      "Architecture of Happiness"});

    string search_item("Alain de Botton"); // author we'll look for
    auto entries = authors.count(search_item); // number of elements
    auto iter = authors.find(search_item); // first entry for this author

    // loop through the number of entries there are for this author
    while(entries) {
		cout << iter->second << endl; // print each title
		++iter;     // advance to the next title
		--entries;  // keep track of how many we've printed
	}

    // definitions of authors and search_item as above
    // beg and end denote the range of elements for this author
    for (auto beg = authors.lower_bound(search_item),
              end = authors.upper_bound(search_item);
		 beg != end; ++beg)
        cout << beg->second << endl; // print each title

    // definitions of authors and search_item as above
    // pos holds iterators that denote the range of elements for this key
    for (auto pos = authors.equal_range(search_item);
         pos.first != pos.second; ++pos.first)
        cout << pos.first->second << endl; // print each title

	return 0;
}

