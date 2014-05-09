/***************************************************************************
 *  @file       queryresult.h
 *  @author     Alan.W
 *  @date       06  JAN 2014
 *  @remark     using StrVec rather than std::vector
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
            //  std::shared_ptr<std::vector<std::string>> sp_f) ://!@@
                std::shared_ptr<StrVec>                   sp_f) ://!
        sought(s), sp_lines(sp_l), sp_file(sp_f) { }


private:
    //! three data members
    std::string sought;
    std::shared_ptr<std::set<TextQuery::index_Tp>> sp_lines;
  //std::shared_ptr<std::vector<std::string>> sp_file;//!@@
    std::shared_ptr<StrVec                  > sp_file;//!

};

/**
 * @brief print the result to the output stream specified.
 */
std::ostream&
print(std::ostream&, const QueryResult&);
#endif // QUERYRESULT_H
