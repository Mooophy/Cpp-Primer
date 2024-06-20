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

#ifndef QUERY_H
#define QUERY_H
#include "TextQuery.h"
#include <string>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

// abstract class acts as a base class for concrete query types; all members are private
class Query_base {
    friend class Query;  
protected:
    using line_no = TextQuery::line_no; // used in the eval functions
    virtual ~Query_base() = default;
private:
    // eval returns the QueryResult that matches this Query
    virtual QueryResult eval(const TextQuery&) const = 0; 
    // rep is a string representation of the query
	virtual std::string rep() const = 0;
};

// interface class to manage the Query_base inheritance hierarchy
class Query {
    // these operators need access to the shared_ptr constructor
    friend Query operator~(const Query &);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const std::string&);  // builds a new WordQuery

    // interface functions: call the corresponding Query_base operations
    QueryResult eval(const TextQuery &t) const 
                            { return q->eval(t); }
	std::string rep() const { return q->rep(); }
private:
    Query(std::shared_ptr<Query_base> query): q(query) { }
    std::shared_ptr<Query_base> q;
};
inline 
std::ostream &
operator<<(std::ostream &os, const Query &query) 
{
	// Query::rep makes a virtual call through its Query_base pointer to rep() 
	return os << query.rep(); 
}

class WordQuery: public Query_base {
    friend class Query; // Query uses the WordQuery constructor
    WordQuery(const std::string &s): query_word(s) { }

    // concrete class: WordQuery defines all inherited pure virtual functions
    QueryResult eval(const TextQuery &t) const
                     { return t.query(query_word); }
	std::string rep() const { return query_word; }
    std::string query_word;   // word for which to search 
};

inline
Query::Query(const std::string &s): q(new WordQuery(s)) { }

class NotQuery: public Query_base {
    friend Query operator~(const Query &);
    NotQuery(const Query &q): query(q) { }

    // concrete class: NotQuery defines all inherited pure virtual functions
	std::string rep() const {return "~(" + query.rep() + ")";}
    QueryResult eval(const TextQuery&) const;
    Query query;
};

class BinaryQuery: public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s): 
          lhs(l), rhs(r), opSym(s) { }

    // abstract class: BinaryQuery doesn't define eval 
	std::string rep() const { return "(" + lhs.rep() + " " 
	                                     + opSym + " " 
		                                 + rhs.rep() + ")"; }

    Query lhs, rhs;    // right- and left-hand operands
    std::string opSym; // name of the operator
};
    
class AndQuery: public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right): 
                        BinaryQuery(left, right, "&") { }

    // concrete class: AndQuery inherits rep and defines the remaining pure virtual
    QueryResult eval(const TextQuery&) const;
};

class OrQuery: public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right): 
                BinaryQuery(left, right, "|") { }

    QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

inline Query operator~(const Query &operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

std::ifstream& open_file(std::ifstream&, const std::string&);
TextQuery get_file(int, char**);
bool get_word(std::string&);
bool get_words(std::string&, std::string&);
std::ostream &print(std::ostream&, const QueryResult&);

#endif
