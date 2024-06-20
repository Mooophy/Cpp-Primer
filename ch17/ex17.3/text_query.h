/**
 * @brief   TextQuery
 * 
 * @file    text_query.h
 * @author  huipengly
 * @date    2018-09-08
 */
#ifndef _TEXT_QUERY_H_
#define _TEXT_QUERY_H_

#include "query_result_tuple.h"
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>

class TextQuery
{
public:
    typedef std::vector<int>::size_type line_no;
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

TextQuery::TextQuery(std::ifstream &is): 
        file(std::make_shared<std::vector<std::string>>())
{
    std::string text;
    // 按行读取文件流
    while(getline(is, text))
    {
        file->push_back(text);
        int n = file->size() - 1;               // get line_no
        std::istringstream line(text);
        std::string word;
        while (line >> word)
        {
            auto &lines = wm[word];
            if (!lines)
            {
                lines.reset(new std::set<line_no>);
            }
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string& sought) const
{
    static std::shared_ptr<std::set<line_no>> nodata(std::make_shared<std::set<line_no>>());
    auto loc = wm.find(sought);
    if (loc != wm.end())
    {
        return std::make_tuple(sought, loc->second, file);
    }
    else
    {
        return std::make_tuple(sought, nodata, file);
    }
}

#endif