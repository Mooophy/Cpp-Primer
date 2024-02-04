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

#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <utility>

class TextQuery {
public:
	class QueryResult;  // nested class to be defined later
	// other members as in XREF(TextQueryClass)
	typedef std::vector<std::string>::size_type line_no;
	TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const; 
    void display_map();        // debugging aid: print the map
private:
    std::shared_ptr<std::vector<std::string>> file; // input file
    // map of each word to the set of the lines in which that word appears
    std::map<std::string, 
	         std::shared_ptr<std::set<line_no>>> wm;  
    // characters that constitute whitespace
    static std::string whitespace_chars;     
	// canonicalizes text: removes punctuation and makes everything lower case
    static std::string cleanup_str(const std::string&);
};

//we're defining the QueryResult class that is a member of class TextQuery
class TextQuery::QueryResult {
	// in class scope, we don't have to qualify the name of the QueryResult parameters
	friend std::ostream&
	       print(std::ostream&, const QueryResult&);
public:
	// no need to define QueryResult::line_no; a nested class can use a member 
	// of its enclosing class without needing to qualify the member's name
	QueryResult(std::string, 
	            std::shared_ptr<std::set<line_no>>,  
	            std::shared_ptr<std::vector<std::string>>);
    // other members as in XREF(TextQueryClass)
	typedef std::set<line_no>::const_iterator line_it;
	std::set<line_no>::size_type size() const  { return lines->size(); }
	line_it begin() const { return lines->cbegin(); }
	line_it end() const   { return lines->cend(); }
	std::shared_ptr<std::vector<std::string>> get_file() { return file; }
private:
	std::string sought;  // word this query represents
	std::shared_ptr<std::set<line_no>> lines; // lines it's on
	std::shared_ptr<std::vector<std::string>> file;  //input file
	static int static_mem;
};
std::ostream &print(std::ostream&, const TextQuery::QueryResult&);

using std::shared_ptr; using std::string; using std::set;
using std::vector;

inline
// defining the member named QueryResult for the class named QueryResult
// that is nested inside the class TextQuery
TextQuery::QueryResult::QueryResult(string s, 
	            shared_ptr<set<line_no>> p,  
	            shared_ptr<vector<string>> f):
		sought(s), lines(p), file(f) { }
#endif
