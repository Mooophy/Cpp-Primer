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
using std::set; using std::multiset;

#include <string>
using std::string;

#include <vector>
using std::vector; 

#include <iostream>
using std::cout; using std::endl; 

int main() 
{
	// define a vector with 20 elements, 
	// holding two copies of each number from 0 to 9
	vector<int> ivec;
	for (vector<int>::size_type i = 0; i != 10; ++i) {
	    ivec.push_back(i);
	    ivec.push_back(i);  // duplicate copies of each number
	}
	
	// iset holds unique elements from ivec; miset holds all 20 elements
	set<int> iset(ivec.cbegin(), ivec.cend());
	multiset<int> miset(ivec.cbegin(), ivec.cend());
	
	cout << ivec.size() << endl;    // prints 20
	cout << iset.size() << endl;    // prints 10
	cout << miset.size() << endl;   // prints 20
	
	// returns an iterator that refers to the element with key == 1
	iset.find(1);   
	iset.find(11);  // returns the iterator == iset.end()
	iset.count(1);  // returns 1
	iset.count(11); // returns 0

	// returns an iterator to the first element with key == 1
	iset.find(1);   
	iset.find(11);   // returns the iterator == iset.end()
	miset.count(1);  // returns 2
	miset.count(11); // returns 0
	
	set<string> set1;    // empty set
	set1.insert("the");  // set1 now has one element
	set1.insert("and");  // set1 now has two elements
	
	ivec = {2,4,6,8,2,4,6,8}; // ivec now has eight elements
	set<int> set2;            // empty set
	set2.insert(ivec.cbegin(), ivec.cend()); // set2 has four elements
	set2.insert({1,3,5,7,1,3,5,7});      // set2 now has eight elements

	return 0;
}
