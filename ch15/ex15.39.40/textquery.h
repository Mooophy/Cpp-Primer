/***************************************************************************
 *  @file       textquery.h
 *  @author     Alan.W
 *  @date       30  DEC 2013
 *  @remark     The TextQuery class using StrBlob
 ***************************************************************************/

//
// Exercise 12.32:
// Rewrite the TextQuery and QueryResult classes to use a StrBlob instead of a
// vector<string> to hold the input file.
//  Relevant post on Stack Overflow:
//  http://stackoverflow.com/questions/20823225/what-will-happen-if-a-user-defined-constructor-omits-ininitialization-for-data-m
//


#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include "StrBlob.h"
#include <map>
#include <set>
#include <string>
#include <memory>
#include <fstream>

class QueryResult;

/**
 * @brief The TextQuery class using StrBlob
 */
class TextQuery
{
public:
    typedef StrBlob::size_type line_no;

    // constructor
    TextQuery(std::ifstream& fin);

    // query operation
    QueryResult query(const std::string&) const;

private:
    // data members
    StrBlob file;

    std::map<std::string,
             std::shared_ptr<std::set<line_no>>> wordMap;

};

/**
 * @brief Query Result
 */
class QueryResult
{
    friend std::ostream& operator<<(std::ostream&, const QueryResult&);

public:
    // constructor
    QueryResult(std::string s,
                std::shared_ptr<std::set<TextQuery::line_no>> sp_l,
                StrBlob f) :
        sought(s), sp_lines(sp_l), file(f) { }

    // added for ex12.33
    // ? Think about wether the "const"s here are expected.
    const StrBlob& get_file() const{ return file; }

    std::set<TextQuery::line_no>::iterator
    begin() { return sp_lines->begin(); }

    std::set<TextQuery::line_no>::iterator
    end()   { return sp_lines->end();   }



private:
    // three data members
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> sp_lines;
    StrBlob file;

};

/**
 * @brief print the result to the output stream specified.
 */
std::ostream&
print(std::ostream&, const QueryResult &);
#endif // TEXTQUERY_H
