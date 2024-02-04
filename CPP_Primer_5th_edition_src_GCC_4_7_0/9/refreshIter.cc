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

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::endl;

void printVec(const vector<int> &vi)
{
	// print the vector's elements
	auto iter = vi.begin();
	while (iter != vi.end())
		cout << *iter++ << endl;
}

int main()
{
	// silly loop to remove even-valued elements 
	// and insert a duplicate of odd-valued elements
	vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
	printVec(vi);

	// we call begin, not cbegin because we're changing vi
	auto iter = vi.begin(); 
	while (iter != vi.end()) {
		if (*iter % 2) {    // if the element is odd
			iter = vi.insert(iter, *iter);  // duplicate  it
			iter += 2; // advance past this element and the new one 
		} else 
			iter = vi.erase(iter);          // remove even elements
			// don't advance the iterator; 
			// iter denotes the element after the one we erased
	}
	printVec(vi);

	return 0;
}
	
