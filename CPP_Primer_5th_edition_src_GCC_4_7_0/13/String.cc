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

#include <cstring>
using std::strlen;

#include <algorithm>
using std::copy; 

#include <cstddef>
using std::size_t; 

#include <iostream>
using std::ostream; 

#include <utility>
using std::swap;

#include <initializer_list>
using std::initializer_list;

#include <memory>
using std::uninitialized_copy;

#include "String.h"

// define the static allocator member
std::allocator<char> String::a;

// copy-assignment operator
String & String::operator=(const String &rhs)
{
	// copying the right-hand operand before deleting the left handles self-assignment
    auto newp = a.allocate(rhs.sz); // copy the underlying string from rhs
	uninitialized_copy(rhs.p, rhs.p + rhs.sz, newp);

	if (p)
		a.deallocate(p, sz); // free the memory used by the left-hand operand
	p = newp;    // p now points to the newly allocated string
	sz = rhs.sz; // update the size

    return *this;     
}

// move assignment operator
String & String::operator=(String &&rhs) noexcept
{
	// explicit check for self-assignment
	if (this != &rhs) {
		if (p)
			a.deallocate(p, sz);  // do the work of the destructor
		p = rhs.p;    // take over the old memory
		sz = rhs.sz;
		rhs.p = 0;    // deleting rhs.p is safe
		rhs.sz = 0;
	}
    return *this; 
}

String& String::operator=(const char *cp)
{
	if (p) a.deallocate(p, sz);
	p = a.allocate(sz = strlen(cp));
	uninitialized_copy(cp, cp + sz, p);
	return *this;
}

String& String::operator=(char c)
{
	if(p) a.deallocate(p, sz);
	p = a.allocate(sz = 1);
	*p = c;
	return *this;
}

String& String::operator=(initializer_list<char> il)
{
	// no need to check for self-assignment
	if (p)
		a.deallocate(p, sz);        // do the work of the destructor
	p = a.allocate(sz = il.size()); // do the work of the copy constructor
	uninitialized_copy(il.begin(), il.end(), p);
	return *this;
}
// named functions for operators
ostream &print(ostream &os, const String &s)
{
	auto p = s.begin();
	while (p != s.end())
		os << *p++ ;
	return os;
}

String add(const String &lhs, const String &rhs) 
{
	String ret;
	ret.sz = rhs.size() + lhs.size();   // size of the combined String
	ret.p = String::a.allocate(ret.sz); // allocate new space
	uninitialized_copy(lhs.begin(), lhs.end(), ret.p); // copy the operands
	uninitialized_copy(rhs.begin(), rhs.end(), ret.p + lhs.sz);
	return ret;  // return a copy of the newly created String
}
	
// return plural version of word if ctr isn't 1
String make_plural(size_t ctr, const String &word,
                               const String &ending)
{
        return (ctr != 1) ?  add(word, ending) : word;
}

// chapter 14 will explain overloaded operators
ostream &operator<<(ostream &os, const String &s)
{
	return print(os, s);
}

String operator+(const String &lhs, const String &rhs) 
{
	return add(lhs, rhs);
}

