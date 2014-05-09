/***************************************************************************
 *  @file       queryresult.h
 *  @author     Alan.W
 *  @date       30  DEC 2013
 *  @remark     using class StrBlob
 ***************************************************************************/
#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include <string>
#include "textquery.h"

/**
 * @brief Query Result
 */
class QueryResult
{
    friend std::ostream& print(std::ostream&, const QueryResult&);

public:
    //! constructor
    QueryResult(std::string s,
                std::shared_ptr<std::set<TextQuery::line_no>> sp_l,
                StrBlob f) :
        sought(s), sp_lines(sp_l), file(f) { }


private:
    //! three data members
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> sp_lines;
    StrBlob file;

};

/**
 * @brief print the result to the output stream specified.
 */
std::ostream&
print(std::ostream&, const QueryResult &);
#endif // QUERYRESULT_H
