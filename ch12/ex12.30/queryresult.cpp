/***************************************************************************
 *  @file       queryresult.cpp
 *  @author     Alan.W
 *  @date       29  DEC 2013
 *  @remark
 ***************************************************************************/

#include "queryresult.h"

/**
 * @brief   print the result to the output stream specified.
 * @note    class QueryResult's friend
 */
std::ostream&
print(std::ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs "
       << qr.sp_lines->size() << " "
       << "times"   <<  "\n";

    //! print each line in which the word appears
    for (const auto &index: *qr.sp_lines)
        os << "\t(line " << index + 1 << ")"
           << *(qr.sp_file->begin() + index) << "\n";
    return os;

}
