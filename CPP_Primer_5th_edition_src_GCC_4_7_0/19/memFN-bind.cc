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

#include <string>
using std::string; 

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::endl; 

#include <algorithm>
using std::find_if;

#include <functional>
using std::bind;
using std::placeholders::_1; 

int main()
{
    vector<string> svec = {"hi", "bye"};
    // bind each string in the range to the implicit first argument to empty
    auto it = find_if(svec.begin(), svec.end(), 
	                  bind(&string::empty, _1));
    if (it == svec.end()) 
		cout << "worked" << endl; 
	else 
		cout << "failed"  << endl;
	auto f =  bind(&string::empty, _1);
	f(*svec.begin()); // ok: argument is a string f will use .* to call empty
	f(&svec[0]); // ok: argument is a pointer to string f will use .-> to call empty
}


