/***************************************************************************
 *  @file       wy_queryresult.h
 *  @author     Alan.W
 *  @date       27  DEC 2013
 *  @remark
 ***************************************************************************/

//!
//! Exercise 12.27:
//! The TextQuery and QueryResult classes use only capabilities that we have
//! already covered. Without looking ahead, write your own versions of these
//! classes.
//!


#ifndef WY_QUERYRESULT_H
#define WY_QUERYRESULT_H
#include <wy_textquery.h>

class wy_queryResult
{
public:
    //! default constructor
    wy_queryResult() = default;

    //! copy constructor
    wy_queryResult(const wy_queryResult &qr);

    wy_queryResult(std::size_t c, const std::string &str,
                   const wy_textQuery::sp_file_Tp &sp_f,
                   const wy_textQuery::sp_Qmap_Tp &sp_m);

    std::size_t
    getCounter() const { return counter; }

    std::string
    getQueryWord() const { return queryWord; }

    wy_textQuery::sp_file_Tp
    getSp_file() const { return sp_file; }

    wy_textQuery::sp_Qmap_Tp
    getSp_Qmap() const { return sp_Qmap; }

private:

    //! number of occurrence
    std::size_t counter = 0;

    //! the word being searched
    std::string queryWord = "";

    //! smart pointer to a vector to be storing a file.
    wy_textQuery::sp_file_Tp sp_file = nullptr;

    //! smart pointer to a map to be storing results of querries.
    wy_textQuery::sp_Qmap_Tp sp_Qmap = nullptr;
};

//! print the result of searching
void print(std::ostream &os, const wy_queryResult &qr);

#endif // WY_QUERYRESULT_H
