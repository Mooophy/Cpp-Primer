/***************************************************************************
 *  @file       wy_StrBlobPtr.cpp
 *  @author     Alan.W
 *  @date       25  DEC 2013
 *  @remark
 ***************************************************************************/
#include "wy_strblobptr.h"

/**
 *  Return a shared_ptr,if the vector still available and the index within
 *  the range [first, last)
 */
std::shared_ptr<wy_StrBlobPtr::tp>
wy_StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    std::shared_ptr<tp>
            result = wp.lock();

    if(!result)
        throw   std::runtime_error("unbound.");

    if(i >= result->size())
        throw   std::out_of_range(msg);

    return result;
}



/**
 * return the string of the current index.
 */
std::string&
wy_StrBlobPtr::dereference() const
{
    std::shared_ptr<tp>
            sp = check(curr, "the index is out of range");

    return (*sp)[curr];
}



/**
 * increment the current index.
 */
wy_StrBlobPtr&
wy_StrBlobPtr::incr()
{
    check(curr, "out of range");
    ++curr;

    return *this;
}













