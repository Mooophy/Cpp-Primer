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
using std::cerr;
using std::ostream; using std::cout; using std::endl;

#include <string>
using std::string;

#include <map>
using std::map;

#include <cstddef>
using std::size_t;

#include "Sales_data.h"
#include "debug_rep.h"

// function to end the recursion and print the last element
template<typename T>
ostream &print(ostream &os, const T &t)
{
    return os << t; // no separator after the last element in the pack
}

template <typename T, typename... Args>                 
ostream &
print(ostream &os, const T &t, const Args&... rest)//expand Args
{
    os << t << ", ";
    return print(os, rest...);                     //expand rest
}

// call debug_rep on each argument in the call to print
template <typename... Args> 
ostream &errorMsg(ostream &os, const Args&... rest)
{
	// print(os, debug_rep(a1), debug_rep(a2), ..., debug_rep(an)
	return print(os, debug_rep(rest)...); 
}


struct ErrorCode {
	ErrorCode(size_t n = 0): e(n) { }
	size_t e;
	size_t num() const { return e; }
	string lookup() const { return errors[e]; }
	static map<size_t, string> errors;
};

map<size_t, string>
ErrorCode::errors = { {42, "some error"}, { 1024, "another error"} };

int main()
{
	Sales_data item("978-0590353403", 25, 15.99);
	string fcnName("itemProcess");
	ErrorCode code(42);
	string otherData("invalid ISBN");

	errorMsg(cerr, fcnName, code.num(), otherData, "other", item);
	cerr << endl;

	print(cerr, debug_rep(fcnName), debug_rep(code.num()), 
	            debug_rep(otherData), debug_rep("otherData"), 
	            debug_rep(item));
	cerr << endl;
	
	return 0;
}

