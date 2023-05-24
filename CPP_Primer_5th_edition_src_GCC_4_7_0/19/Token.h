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

#ifndef TOKEN_H
#define TOKEN_H

#include <string>
using std::string;

#include <iostream>

#include "Token.h"

class Token {
friend std::ostream &operator<<(std::ostream&, const Token&);
public:
	// copy control needed because our class has a union with a string member
	// defining the move constructor and move-assignment operator is left as an exercise
	Token(): tok(INT), ival{0} { }
	Token(const Token &t): tok(t.tok) { copyUnion(t); }
	Token &operator=(const Token&);
	// if the  union holds a string, we must destroy it; see XREF(expldtor)
	~Token() { if (tok == STR) sval.~string(); }
	// assignment operators to set the differing members of the union
	Token &operator=(const std::string&);
	Token &operator=(char);
	Token &operator=(int);
	Token &operator=(double);
private:
    enum {INT, CHAR, DBL, STR} tok; // discriminant
    union {                         // anonymous union 
        char   cval;
        int    ival;
        double dval;
		std::string sval;
    }; // each Token object has an unnamed member of this unnamed union type
	// check the discriminant and copy the union member as appropriate
	void copyUnion(const Token&);  
};

inline
void Token::copyUnion(const Token &t)
{
	switch (t.tok) {
		case Token::INT: ival = t.ival; break;
		case Token::CHAR: cval = t.cval; break;
		case Token::DBL: dval = t.dval; break;
		// to copy a string, construct it using placement new; see (XREF(placenew)) 
		case Token::STR: new(&sval) std::string(t.sval); break;
	}
}

inline
std::ostream &operator<<(std::ostream &os, const Token &t)
{
	switch (t.tok) {
		case Token::INT: return os << t.ival;
		case Token::CHAR: return os << t.cval;
		case Token::DBL: return os << t.dval;
		case Token::STR: return os << t.sval;
	}
}

inline
Token &Token::operator=(double d)
{
	if (tok == STR) sval.~string();  // if we have a string, free it
	dval = d;
	tok = DBL;
	return *this;
}

inline
Token &Token::operator=(char c)
{
	if (tok == STR) sval.~string();  // if we have a string, free it
	cval = c;
	tok = CHAR;
	return *this;
}

inline
Token &Token::operator=(int i)
{
	if (tok == STR) sval.~string();  // if we have a string, free it
	ival = i;                        // assign to the appropriate member
	tok = INT;                       // update the discriminant
	return *this;
}

inline
Token &Token::operator=(const std::string &s)
{
	if (tok == STR)  // if we already hold a string, just do an assignment
		sval = s;
	else
		new(&sval) std::string(s);  // otherwise construct a string
	tok = STR;                 // update the discriminant
	return *this;
}

inline
Token &Token::operator=(const Token &t)
{
	// if this object holds a string and t doesn't, we have to free the old string
	if (tok == STR && t.tok != STR) sval.~string();
	if (tok == STR && t.tok == STR)
		sval = t.sval;  // no need to construct a new string
	else
		copyUnion(t);   // will construct a string if t.tok is STR
	tok = t.tok;
	return *this;
}
#endif
