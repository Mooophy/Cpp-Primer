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

#include "Blob.h"
#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::endl;

int main()
{
	vector<int> v1(3, 43), v2(10);
	Blob<int> a1(v1.begin(), v1.end()),
	          a2 = {0,1,2,3,4,5,6,7,8,9},
	          a3(v2.begin(), v2.end());
	
	cout << a1 << "\n\n" << a2 << "\n\n" << a3 << endl;
	
	cout << "\ncopy" << "\n\n";
	Blob<int> a5(a1); 
	cout << a5 << endl;
	
	cout << "\nassignment" << "\n\n";
	
	a1 = a3;
	cout << a1 << "\n\n" << a2 << "\n\n" << a3 << endl;
	
	cout << "\nelement assignment" << "\n\n";
	a1[0] = 42;
	a1[a1.size() - 1] = 15;
	cout << a1 << "\n\n" << a3 << endl;
	
	Blob<string> s1 = {"hi", "bye", "now"};
	BlobPtr<string> p(s1);    // p points to the vector inside s1
	*p = "okay";                 // assigns to the first element in s1
	cout << p->size() << endl;   // prints 4, the size of the first element in s1
	cout << (*p).size() << endl; // equivalent to p->size()
	
	Blob<string> s2{"one", "two", "three"};
	// run the string empty function in the first element in s2
	if (s2[0].empty())   
	    s2[0] = "empty"; // assign a new value to the first string in s2
	
	cout << a1 << endl;
	cout << a2 << endl;
	a2.swap(a1);
	cout << a1 << endl;
	cout << a2 << endl;

	return 0;
}
	
