/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Alan.W
 *  @date       25  DEC 2013
 *  @remark
 ***************************************************************************/
//!
//! Exercise 12.22:
//! What changes would need to be made to StrBlobPtr to create a class that can
//! be used with a const StrBlob? Define a class named ConstStrBlobPtr that can
//! point to a const StrBlob.
//!


#ifndef WY_CONSTSTRBLOBPTR_H
#define WY_CONSTSTRBLOBPTR_H

#include <wy_strblob.h>

class wy_ConstStrBlobPtr
{
public:
    typedef std::vector<std::string> tp;

    wy_ConstStrBlobPtr() : curr(0) {}
    wy_ConstStrBlobPtr(const wy_StrBlob &sb, std::size_t sz = 0) :
        wp(sb.data), curr(sz){}

    const std::string& dereference() const;
    wy_ConstStrBlobPtr& incr();

private:
    std::shared_ptr<tp>
    check(std::size_t i, const std::string &msg) const;

    std::weak_ptr<tp> wp;
    std::size_t curr;
};



#endif // WY_CONSTSTRBLOBPTR_H
