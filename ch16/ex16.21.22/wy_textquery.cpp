/***************************************************************************
 *  @file       wy_textquery.cpp
 *  @author     Alan.W
 *  @date       27  DEC 2013
 *  @remark     03  FEB 2014    deleter added
 ***************************************************************************/

//
// Exercise 12.27:
// The TextQuery and QueryResult classes use only capabilities that we have
// already covered. Without looking ahead, write your own versions of these
// classes.
//

#include "wy_textquery.h"
#include "wy_queryresult.h"
#include "DebugDelete.h"
#include <sstream>
#include <algorithm>

/**
 *  Constructor
 *  read each line into the dynamicly allocated vector.
 */
wy_textQuery::wy_textQuery(std::ifstream &fin) :
    // @oldcode
    // custom deleter may not use with std::make_shared, as it has an internal
    // deleter which may not be replaced. As a result, keyword new is the only
    // option to use with DebugDelete.
    /*
    sp_fileData(std::make_shared<std::vector<std::string>>() ),
    sp_queryMap(std::make_shared<std::map<std::string, std::set<int>>>() )
    */
    sp_fileData(new std::vector<std::string>(), DebugDelete() ),
    sp_queryMap(new std::map<std::string, std::set<int>>(), DebugDelete())
{
    std::string line;
    while(std::getline(fin, line))
        sp_fileData->push_back(line);

}

/**
 * @brief return a wy_queryResult object for the search result.
 * @param qWord
 */
wy_queryResult
wy_textQuery::query(const std::string &qWord) const
{
    // storing the amount of occurrence
    std::size_t counter = 0;

    // loop through each line
    for(std::size_t i=0; i != sp_fileData->size(); ++i)
    {
        // break into each word
        std::stringstream lineStream((*sp_fileData)[i]);
        std::string word;
        while(lineStream >> word)
        {
            if(!word.compare(qWord))
            {
                ++counter;

                // add the index of the line into the result map
                (*sp_queryMap)[qWord].insert(i);
            }
        }
    }

    // creare a object holding the result .
    wy_queryResult qResult(counter, qWord, sp_fileData, sp_queryMap);

    return qResult;
}
