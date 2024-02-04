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

#ifndef DEBUG_REP_H
#define DEBUG_REP_H
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/* this file uses two preprocessor variables to control whether
 * we use nontemplate functions or specializations for string
 * data and to control whether we define versions of debug_rep
 * that handle character pointers.
 *
 * SPECIALIZED is defined, then we define specializations
 *             for string, char*, and const char* and do not
 *             define nontemplate functions taking these types
 *
 * OVERCHAR only matters if SPECIALIZED is not defined.  In this case
 *          if OVERCHAR is defined, we define one nontemplate function
 *          that takes a string; if OVERCHAR is not defined 
 *          we also define nontemplate functions taking char* and
 *          const char*
*/
#ifndef SPECIALIZED
std::string debug_rep(const std::string &s);
#ifndef OVERCHAR
std::string debug_rep(char *p);
std::string debug_rep(const char *cp);
#endif
#endif
// overloaded, not specialized, function templates
template <typename T> std::string debug_rep(const T &t);
template <typename T> std::string debug_rep(T *p);
template <typename T> std::string debug_rep(T b, T e);
template <typename T> std::string debug_rep(const std::vector<T> &v);

#ifdef SPECIALIZED
// specialized versions to handle strings and character pointers
// declarations for specializations should follow declarations for all overloaded templates
template <> std::string debug_rep(const std::string&); 
template <> std::string debug_rep(const char*);
template <> std::string debug_rep(char*);
#endif

// print any type we don't otherwise handle
template <typename T> std::string debug_rep(const T &t)
{
#ifdef DEBUG
	std::cout << "const T&" << "\t";
#endif
	std::ostringstream ret; 
	ret << t; // uses T's output operator to print a representation of t
	return ret.str();  // return a copy of the string to which ret is bound
}

// print pointers as their pointer value 
// followed by the object to which the pointer points
// NB: this function will not work properly with char*
template <typename T> std::string debug_rep(T *p)
{
#ifdef DEBUG
	std::cout << "T*" << "\t";
#endif
	std::ostringstream ret;
	ret << "pointer: " << p;         // print the pointer's own value
	if (p)
		ret << " " << debug_rep(*p); // print the value to which p points
	else
		ret << " null pointer";      // or indicate that the p is null
	return ret.str(); // return a copy of the string to which ret is bound
}
#ifndef SPECIALIZED
// print strings inside double quotes 
std::string debug_rep(const std::string &s)
#else
template <> std::string debug_rep(const std::string &s)
#endif
{
#ifdef DEBUG
	std::cout << "const string &" << "\t";
#endif
	return '"' + s + '"';
}


#ifndef OVERCHAR
// convert the character pointers to string and call the string version of debug_rep
std::string debug_rep(char *p) 
{
	return debug_rep(std::string(p));
}
std::string debug_rep(const char *p) 
{
	return debug_rep(std::string(p));
}
#endif
#ifdef SPECIALIZED
template<> std::string debug_rep(char *p)
	{ return debug_rep(std::string(p)); }
template <> std::string debug_rep(const char *cp)
	{ return debug_rep(std::string(cp)); }
#endif

template <typename T> std::string debug_rep(T b, T e)
{
	std::ostringstream ret;
	for (T it = b; it != e; ++it) {
		if (it != b)
			ret << ",";            // put comma before all but the first element
		ret << debug_rep(*it);     // print the element
	}
	return ret.str();
}

template <typename T> std::string debug_rep(const std::vector<T> &v)
{
	std::ostringstream ret;
	ret << "vector: [";
	ret << debug_rep(v.begin(), v.end());
	ret << "]";
	return ret.str();
}
#endif
