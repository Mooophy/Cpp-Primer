/***************************************************************************
 *  @file       wy_StrBlobPtr.h
 *  @author     Alan.W
 *  @date       25  DEC 2013
 *  @remark
 ***************************************************************************/

//!
//! Exercise 12.19:
//! Define your own version of StrBlobPtr and update your StrBlob class with
//! the appropriate friend declaration and begin and end members.
//  Discussion on Stack Overflow:
//  http://stackoverflow.com/questions/20768083/using-qt-creator-why-cant-my-class-header-compile
//!

#ifndef WY_STRBLOBPTR_H
#define WY_STRBLOBPTR_H

#include <vector>
#include <memory>
#include <string>
#include <wy_strblob.h>

/**
 * @brief essentially a weak_ptr to a vector .
 */
class wy_StrBlobPtr
{
public:
    typedef std::vector<std::string> tp;

    //! constructors
    wy_StrBlobPtr() : curr(0){}
    wy_StrBlobPtr(wy_StrBlob &sb, std::size_t sz = 0):
        wp(sb.data), curr(sz){}


    std::string& dereference() const;
    wy_StrBlobPtr& incr();

private:
    std::shared_ptr<tp>
    check(std::size_t, const std::string&) const;


    std::weak_ptr<tp> wp;
    std::size_t curr;
};

#endif // WY_STRBLOBPTR_H
