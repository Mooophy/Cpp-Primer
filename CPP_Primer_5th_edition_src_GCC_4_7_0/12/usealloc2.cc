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

#include <cstddef>
using std::size_t;

#include <string>
using std::string; 

#include <vector>
using std::vector; 

#include <memory>
using std::uninitialized_copy;
using std::allocator; using std::uninitialized_fill_n;

#include <iostream>
using std::cout; using std::endl;

int main()
{
	vector<int> vi{1,2,3,4,5,6,7,8,9};

	allocator<int> alloc;
	// allocate twice as many elements as vi holds
	auto p = alloc.allocate(vi.size() * 2);

	// construct elements starting at p as copies of elements in vi
	auto q = uninitialized_copy(vi.begin(), vi.end(), p); 

	// initialize the remaining elements to 42
	uninitialized_fill_n(q, vi.size(), 42);

	for (size_t i = 0; i != vi.size(); ++i)
		cout << *(p + i) << " ";
	cout << endl;

	for (size_t i = 0; i != vi.size(); ++i)
		cout << *(q + i) << " ";
	cout << endl;

	alloc.deallocate(p, vi.size());
}
