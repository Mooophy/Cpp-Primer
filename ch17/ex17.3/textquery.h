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
    typedef std::tuple <std::string, std::shared_ptr<std::set<index_Tp>>, std::shared_ptr<std::vector<std::string>>>  result_tuple;

    // constructor
    TextQuery(std::ifstream&);

    // query operation returns QueryResult
    QueryResult
    query(const std::string&) const;

    // query operation returns tuple
    result_tuple query_return_tuple(const std::string& sought);
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<index_Tp>>> wm;
};

#endif // TEXTQUERY_H
