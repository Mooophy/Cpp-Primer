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

#include <algorithm>
using std::find; using std::find_if; using std::for_each;
using std::remove_copy_if; using std::reverse_copy;
using std::reverse; 

#include <iterator>
using std::back_inserter;

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::endl;

int main()
{
	vector<int> v1 = {0,1,2,3,4,5,6,7,8,9};
	vector<int> v2;
	vector<int> v3 = v1;

	find(v1.begin(), v1.end(), 42);  // find first element equal to 42 
	find_if(v1.begin(), v1.end(),    // find first odd element
	        [](int i) { return i % 2; });

	// puts elements in v1 into reverse order
	reverse(v1.begin(), v1.end());  
	v1 = v3;  // restore original data

	// copies elements from v1 into v2 in reverse order; v1 is unchanged
	reverse_copy(v1.begin(), v1.end(), back_inserter(v2));

	for (auto i : v1) 
		cout << i << " ";   // prints 0 1 2 . . . 8 9
	cout << endl;
	for (auto i : v2) 
		cout << i << " ";   // prints 9 8 7 . . . 1 0
	cout << endl;

	// removes the odd elements from v1
	auto it = remove_if(v1.begin(), v1.end(), 
	                    [](int i) { return i % 2; });
	// prints 0 2 4 6 8
	for_each(v1.begin(), it, [](int i) { cout << i << " "; });
	cout << endl;

	v1 = v3;    // restore original data
	v2.clear(); // make v2 empty again

	// copies only the even elements from v1 into v2; v1 is unchanged
	remove_copy_if(v1.begin(), v1.end(), back_inserter(v2),
	               [](int i) { return i % 2; });
	for (auto i : v2) 
		cout << i << " ";  // prints 0 2 4 6 8
	cout << endl;
	for (auto i : v1)      // prints 0 1 2 . . . 8 9
		cout << i << " ";
	cout << endl;

	return 0;
}
