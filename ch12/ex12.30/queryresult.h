/***************************************************************************
 *  @file       queryresult.h
 *  @author     Alan.W
 *  @date       29  DEC 2013
 *  @remark
 ***************************************************************************/
#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include <string>
#include "textquery.h"


class QueryResult
{
    friend std::ostream& print(std::ostream&, const QueryResult&);

public:
    //! constructor
    QueryResult(std::string s,
                std::shared_ptr<std::set<TextQuery::index_Tp>> sp_l,
                std::shared_ptr<std::vector<std::string>> sp_f) :
        sought(s), sp_lines(sp_l), sp_file(sp_f)
    { }


private:
    //! three data members
    std::string sought;
    std::shared_ptr<std::set<TextQuery::index_Tp>> sp_lines;
    std::shared_ptr<std::vector<std::string>> sp_file;
};

/**
 * @brief print the result to the output stream specified.
 */
std::ostream&
print(std::ostream&, const QueryResult&);
#endif // QUERYRESULT_H
