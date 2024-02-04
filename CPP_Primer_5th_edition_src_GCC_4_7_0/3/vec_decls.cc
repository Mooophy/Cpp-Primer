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

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Sales_item.h"

int main()
{
	// list initialization, articles has 3 elements
	vector<string> articles = {"a", "an", "the"};

	vector<string> svec; // default initialization; svec has no elements
	vector<int> ivec;             // ivec holds objects of type int
	vector<Sales_item> Sales_vec; // holds Sales_items
	
	vector<vector<string>> file;  // vector whose elements are vectors
	vector<vector<int>> vecOfvec; // each element is itself a vector
	
	// all five vectors have size 0
	cout << svec.size() << " " << ivec.size() << " "
	     << Sales_vec.size() << " "
	     << file.size() << " " << vecOfvec.size() << endl;
	
	vector<int> ivec2(10);     // ten elements, each initialized to 0
	vector<int> ivec3(10, -1); // ten int elements, each initialized to -1
	vector<string> svec2(10);  // ten elements, each an empty string
	vector<string> svec3(10, "hi!"); // ten strings; each element is "hi!"
	cout << ivec2.size() << " " << ivec3.size() << " "
	     << svec2.size() << " " << svec3.size() << endl;
	
	// 10 is not a string, so cannot be list initialization
	vector<string> v1(10); // construct v1 with ten value-initialized elements
	vector<string> v2{10}; // ten elements value-initialized elements
	vector<string> v3(10, "hi");  // ten elements with value "hi"
	// again list initialization is not viable, so ordinary construction
	vector<string> v4{10, "hi"};  // ten elements with values "hi"
	
	// all four vectors have size ten
	cout << v1.size() << " " << v2.size() 
	     << " " << v3.size() << " " << v4.size() << endl;
	
	vector<string> vs1{"hi"}; // list initialization: vs1 has 1 element 
	vector<string> vs2{10};   // ten default-initialized elements
	vector<string> vs3{10, "hi"}; // has ten elements with value "hi"
	cout << vs1.size() << " " << vs2.size() << " " << vs3.size() << endl;
	
	vector<int> v5(10, 1);  // ten elements with value 1
	vector<int> v6{10, 1};  // two elements with values 10 and 1
	cout << v5.size() << " " << v6.size() << endl;
	
	// intention is clearer
	vector<int> alt_v3 = {10};    // one element with value 10
	vector<int> alt_v4 = {10, 1}; // two elements with values 10 and 1
	cout << alt_v3.size() << " " << alt_v4.size() << endl;

	return 0;
}
