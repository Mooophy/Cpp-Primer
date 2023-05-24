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

#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

#include <cstddef>
using std::size_t;

#include <new>
using std::nothrow;

size_t get_size() { return 42; }

int main() 
{
	// if allocation fails, new returns a null pointer
	int *p1 = new int; // if allocation fails, new throws std::bad_alloc
	int *p2 = new (nothrow) int; // if allocation fails, new returns a null pointer
	
	int i0;                  // named, uninitialized int variable

	int *p0 = new int;       // pi points to a dynamically allocated, 
	                         // unnamed, uninitialized int 
	delete p0;  // frees the memory to which pi points

	// named initialized variables
	int i(1024);             // value of i is 1024
	string s(10, '9');       // value of s is "9999999999"
	vector<int> v = {0,1,2,3,4,5,6,7,8,9};

	// unnamed, initialized dynamically allocated objects
	int *pi = new int(1024); // object to which pi points has value 1024
	string *ps = new string(10, '9');   // *ps is "9999999999"
	// vector with ten elements with values from 0 to 9
	vector<int> *pv = new vector<int>{0,1,2,3,4,5,6,7,8,9};
	
	cout << "*pi: " << *pi
	     << "\ti: " << i << endl
	     << "*ps: " << *ps
	     << "\ts: " << s << endl;
	
	for (auto b = pv->begin(); b != pv->end(); ++b)
		cout << *b << " ";
	cout << endl;

	// when we're done using the memory must delete the pointers
	delete pi;  // frees the memory to which pi points
	delete ps;  // frees the string to which ps points
	            // the string destructor frees the space used by its data
	delete pv;  // frees the memory for the vector
	            // which also destroys the elements in that vector
	
	// call get_size to determine how many ints to allocate
	int *pia = new int[get_size()]; // pia points to the first of these ints
	delete [] pia; // brackets used to delete pointer to element in an array
	typedef int arrT[42];  // arrT names the type array of 42 ints
	int *p = new arrT;     // allocates an array of 42 ints; p points to the first one
	delete [] p;           // brackets are necessary because we allocated an array 

	return 0;
}
