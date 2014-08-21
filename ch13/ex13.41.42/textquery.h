/***************************************************************************
 *  @file       textquery.h
 *  @author     Alan.W
 *  @date       06  JAN 2014
 *  @remark     using StrVec rather than std::vector
 ***************************************************************************/


#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <map>
#include <set>
#include "strvec.h"

class QueryResult;

class TextQuery
{

public:
  //typedef std::vector<std::string>::size_type index_Tp; //!@@
    typedef std::size_t                         index_Tp; //!06  JAN 2014


    //! constructor
    TextQuery(std::ifstream&);

    //! member function for query operation
    QueryResult
    query(const std::string&) const;

private:
  //std::shared_ptr<std::vector<std::string>> file;//!@@
    std::shared_ptr<StrVec> file;                  //!06  JAN 2014
    std::map<std::string,
             std::shared_ptr<std::set<index_Tp>>> wm;
};

#endif // TEXTQUERY_H
