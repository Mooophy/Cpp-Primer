/***************************************************************************
 *  @file       wy_queryresult.cpp
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


#include "wy_queryresult.h"

//! copy constructor
inline wy_queryResult::wy_queryResult(const wy_queryResult &qr):
    counter(qr.getCounter()), queryWord(qr.getQueryWord()),
    sp_file(qr.getSp_file()), sp_Qmap(qr.getSp_Qmap())
{
}

//! constructor
wy_queryResult::wy_queryResult(std::size_t c, const std::string &str,
                               const wy_textQuery::sp_file_Tp &sp_f,
                               const wy_textQuery::sp_Qmap_Tp &sp_m) :
    counter(c), queryWord(str), sp_file(sp_f), sp_Qmap(sp_m)
{
}

//! a non-member function printing the result of a query.
void print(std::ostream &os, const wy_queryResult &qr)
{
    //! fetch the word being queried.
    const std::string queryWord = qr.getQueryWord();

    //! print the word and occurrence times
    os << "The word ["
         <<queryWord
           <<"] occurs "
             <<qr.getCounter()
               <<" times :\n";

    //! fetch smart pointers to the map and the file
    auto sp_m = qr.getSp_Qmap();
    auto sp_f = qr.getSp_file();

    //! print each line in which it appears and the corresponding index.
    for(const auto &index : (*sp_m)[queryWord])
        std::cout << "\n(Line "
                    <<index
                       <<") "
                          << (*sp_f)[index]
                             << "\n\n";
}
