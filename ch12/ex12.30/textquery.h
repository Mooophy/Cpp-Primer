/***************************************************************************
 *  @file       textqueryr.h
 *  @author     Alan.W
 *  @date       29  DEC 2013
 *  @remark
 ***************************************************************************/

#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <map>
#include <set>

class QueryResult;

class TextQuery
{

public:
    typedef std::vector<std::string>::size_type index_Tp;

    //! constructor
    TextQuery(std::ifstream&);

    //! member function for query operation
    QueryResult
    query(const std::string&) const;

private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string,
             std::shared_ptr<std::set<index_Tp>>> wm;
};

#endif // TEXTQUERY_H
