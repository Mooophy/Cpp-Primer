#ifndef _QUERYRESULT_H
#define _QUERYRESULT_H

#include <iostream>
using std::ostream;

#include <memory>
using std::shared_ptr;

#include <set>
using std::set;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "textquery.h"


class QueryResult
{
    friend ostream& print(ostream&, const QueryResult&);
	friend ostream& print(ostream&, const QueryResult&, 
		size_t, size_t);
public:
	QueryResult(string s,
		shared_ptr<set<TextQuery::line_no>> l,
		shared_ptr<vector<string>> f) :
		sought(s), lines(l), file(f){ }

	set<TextQuery::line_no>::iterator begin(){ return lines->begin(); }
	set<TextQuery::line_no>::iterator end(){ return lines->end(); }
	shared_ptr<vector<string>> get_file(){ return file; }

private:
    string sought;
    shared_ptr<set<TextQuery::line_no>> lines;
    shared_ptr<vector<string>> file;

	TextQuery::line_no line_no() const { return lines->size(); }
};

ostream&
print(ostream&, const QueryResult&);

ostream&
print(ostream&, const QueryResult&, size_t, size_t);
#endif 
