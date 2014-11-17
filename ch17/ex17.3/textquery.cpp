/***************************************************************************
 *  @file       textqueryr.cpp
 *  @author     Alan.W
 *  @date       29  DEC 2013
 *  @remark
 ***************************************************************************/

#include "textquery.h"
#include "queryresult.h"
#include <iterator>
#include <algorithm>
#include <sstream>

//! Constructor
TextQuery::TextQuery(std::ifstream & is) : file(new std::vector<std::string>)
{
    //! each line
    std::string line;
    while(std::getline(is,line))
    {
        file->push_back(line);
        //! current line index
        int index = file->size() - 1;

        //! for each word
        std::stringstream lineSteam(line);
        std::string word;
        while(lineSteam >> word)
        {
            //! fetch the smart pointer which is null when the word first time seen
            std::shared_ptr<
                    std::set<index_Tp>>& sp_lineIndex = wm[word];

            //! if null, allcate a new set to contain line indices
            if(!sp_lineIndex)
                sp_lineIndex.reset(new std::set<index_Tp>);

            //! insert
            sp_lineIndex->insert(index);
        }
    }

    //!     =debugging=
    std::cout << "@alan : the size of wm is " << wm.size() <<"\n";

    for(const auto &line : *file)
        std::cout<<"@alan : \t" << line << "\n";

    /*
    for(const auto &e : wm)
    {
        std::cout << e.first << " :\n";
        for (const auto &index : *(e.second))
        {
            std::cout << index << " ";
        }
        std::cout << "\n";
    }
    */
    //!      =end=
}

/**
 * @brief do a query opertion and return QueryResult object.
 */
QueryResult
TextQuery::query(const std::string &sought) const
{
    //! dynamicaly allocated set used for the word does not appear.
    static std::shared_ptr<std::set<index_Tp>> noData(new std::set<index_Tp>);

    //! fetch the iterator to the matching element in the map<word, lines>.
    //std::map<std::string, std::shared_ptr<std::set<index_Tp>>>::const_iterator
    auto iter = wm.find(sought);
    if(iter == wm.end())
        return QueryResult(sought, noData, file);
    else
        return QueryResult(sought, iter->second, file);
}

/**
 * @brief do a query opertion and return tuple.
 */
result_tuple TextQuery::query_return_tuple(const std::string &sought)
{
    //! dynamicaly allocated set used for the word does not appear.
    static std::shared_ptr<std::set<index_Tp>> noData(new std::set<index_Tp>);

    //! fetch the iterator to the matching element in the map<word, lines>.
    //std::map<std::string, std::shared_ptr<std::set<index_Tp>>>::const_iterator
    auto iter = wm.find(sought);
    if(iter == wm.end())
        return result_tuple(sought, noData, file);
    else
        return result_tuple(sought, iter->second, file);
}

