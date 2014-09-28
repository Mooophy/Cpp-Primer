#ifndef _TEXTQUERY_H
#define _TEXTQUERY_H

#include <fstream>
using std::ifstream;

#include <memory>
using std::shared_ptr;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <map>
using std::map;

#include <set>
using std::set;

class QueryResult;

class TextQuery
{

public:
    typedef vector<string>::size_type line_no;

    TextQuery(ifstream&);
    QueryResult query(const string&) const;

private:
    shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;

	shared_ptr<vector<string>> handlePunct(const string&);
};

#endif
