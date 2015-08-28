/***************************************************************************
 *  @file       wy_textquery.h
 *  @author     Alan.W
 *  @date       27  DEC 2013
 *  @remark
 ***************************************************************************/

//
// Exercise 12.27:
// The TextQuery and QueryResult classes use only capabilities that we have
// already covered. Without looking ahead, write your own versions of these
// classes.
//

#ifndef WY_TEXTQUERY_H
#define WY_TEXTQUERY_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>

class wy_queryResult;

class wy_textQuery
{
public:
    typedef std::shared_ptr<std::vector<std::string>> sp_file_Tp;
    typedef std::shared_ptr<std::map<std::string, std::set<int>>> sp_Qmap_Tp;

    // constructors
    wy_textQuery() = default;
    wy_textQuery(std::ifstream &fin);

    // query operation
    wy_queryResult
    query(const std::string &qWord) const;

private:
    // smart pointer to a vector to be storing a file.
    sp_file_Tp sp_fileData = nullptr;

    // smart pointer to a map to be storing results of querries.
    sp_Qmap_Tp sp_queryMap = nullptr;
};

#endif // WY_TEXTQUERY_H
