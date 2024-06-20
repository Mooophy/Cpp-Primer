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
using std::map;

#include <string>
using std::string;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main() 
{
    map<string, size_t> word_count;  // empty map from string to size_t
    string word;
    while (cin >> word)
      ++word_count[word];

	string removal_word = "the";
	
	// two ways to remove an entry from a map
	// 1. by key
	// erase on a key returns the number of elements removed
	if (word_count.erase(removal_word))
	     cout << "ok: " << removal_word << " removed\n";
	else cout << "oops: " << removal_word << " not found!\n";
	
	// 2. by removing an iterator to the element we want removed
	removal_word = "The";  // strings are case sensitive
	map<string,size_t>::iterator where;
	where = word_count.find(removal_word);  // should be gone
	
	if (where == word_count.end())
	     cout << "oops: " << removal_word << " not found!\n";
	else {
	     word_count.erase(where);   // erase iterator returns void
	     cout << "ok: " << removal_word << " removed!\n";
	}
	    return 0;
}
