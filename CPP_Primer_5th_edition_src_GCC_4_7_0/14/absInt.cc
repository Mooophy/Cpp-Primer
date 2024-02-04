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

#include <iterator>
using std::inserter;

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <algorithm>
using std::transform;

struct absInt {
    int operator()(int val) const {
        return val < 0 ? -val : val;
    }
};

int main() {
    int i = -42;
    absInt absObj;           // object that has a function-call operator
    unsigned ui = absObj(i); // passes i to absObj.operator()
    cout << i << " " << ui << endl;

	// store collection of positive and negative integers in vi
	vector<int> vi;
	while (cin >> i)
		vi.push_back(i);

	// call absInt to store the absolute value of those ints in vu
	vector<unsigned> vu;
	transform(vi.begin(), vi.end(), back_inserter(vu), absInt());

	// print contents of vu using a lambda
	for_each(vu.begin(), vu.end(), [](unsigned i) { cout << i << " "; });
	cout << endl;

	vector<unsigned> vu2;
	// similar transformation but using a lambda
	transform(vi.begin(), vi.end(), back_inserter(vu2),
	          [](int i) { return i < 0 ? -i : i; });
	if (vu == vu2)
		cout << "as expected" << endl;
	else {
		cout << "something's wrong, vectors differ" << endl;
		for_each(vu.begin(), vu.end(), [](unsigned i) { cout << i << " "; });
	}
	cout << endl;

    return 0;
}
