/**
 * @brief QueryResult use tuple
 * 
 * @file query_result_tuple.h
 * @author huipengly
 * @date 2018-09-22
 */
#ifndef _QUERY_RESULT_H_
#define _QUERY_RESULT_H_

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <tuple>

typedef std::tuple<std::string, std::shared_ptr<std::set<std::vector<int>::size_type>>, std::shared_ptr<std::vector<std::string>>> QueryResult;

std::string makr_plural(size_t ctr, const std::string &word, const std::string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

std::ostream& print(std::ostream &os, const QueryResult &qr)
{
    os << std::get<0>(qr) << " occurs " << std::get<1>(qr)->size() << " " << makr_plural(std::get<1>(qr)->size(), "time", "s") << std::endl;
    for (auto num : *(std::get<1>(qr)))
    {
        os << "\t(line " << num + 1 << ") " << *(std::get<2>(qr)->begin() + num) << std::endl;
    }
    return os;
}

#endif