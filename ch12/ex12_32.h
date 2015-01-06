//
//  ex12_32.h
//  Exercise 12.32
//
//  Created by pezy on 1/1/15.
//  Copyright (c) 2015 pezy. All rights reserved.
//
//  Rewrite the TextQuery and QueryResult classes to use a StrBlob
//  instead of a vector<string> to hold the input file.

#ifndef CP5_ex12_32_h
#define CP5_ex12_32_h

#include "ex12_22.h"
using std::shared_ptr;

#include <iostream>
#include <fstream>
#include <map>
#include <set>

class QueryResult;
class TextQuery {
public:
    TextQuery(std::ifstream &);
    QueryResult query(const string&) const;
private:
    shared_ptr<StrBlob> input;
    std::map<string, shared_ptr<std::set<StrBlob::size_type>>> result;
};

class QueryResult {
public:
    friend std::ostream& print(std::ostream &, const QueryResult&);
public:
    QueryResult(const string &s, shared_ptr<std::set<StrBlob::size_type>> set, shared_ptr<StrBlob> v) : word(s), nos(set), input(v) {}
private:
    string word;
    shared_ptr<std::set<StrBlob::size_type>> nos;
    shared_ptr<StrBlob> input;
};

std::ostream& print(std::ostream &, const QueryResult&);

#endif
