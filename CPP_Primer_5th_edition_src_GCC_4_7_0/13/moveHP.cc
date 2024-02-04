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
#include <string>
#include <utility>
// for swap but we do not provide a using declaration for swap

// HasPtr with added move constructor
class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
public:
	// default constructor and constructor that takes a string
    HasPtr(const std::string &s = std::string()): 
		ps(new std::string(s)), i(0) { }

	// copy constructor
    HasPtr(const HasPtr &p): 
		ps(new std::string(*p.ps)), i(p.i) { }

	// move constructor
	HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) {p.ps = 0;}

	// assignment operator is both the move- and copy-assignment operator
	HasPtr& operator=(HasPtr rhs) 
	               { swap(*this, rhs); return *this; }

	// destructor
	~HasPtr() { delete ps; }
private:
    std::string *ps;
    int    i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
	swap(lhs.i, rhs.i);   // swap the int members
}

int main()
{
	HasPtr hp("hi mom");
	HasPtr hp2(hp);
	
	hp = hp2; // hp2 is an lvalue; copy constructor used to copy hp2 
	hp = std::move(hp2); // move constructor moves hp2
}
