/***************************************************************************
 *  @file       wy_StrBlob.cpp
 *  @author     Alan.W
 *  @date       25  DEC 2013
 *  @remark
 ***************************************************************************/

#include "wy_strblob.h"
#include "wy_strblobptr.h"


/**
 * @brief uility function that checks if the index is valid
 * @param i index
 * @param msg   message to be thown
 */
void wy_StrBlob::check(wy_StrBlob::size_type i, const std::string &msg) const
{
    if(i >= data->size())
        throw   std::out_of_range(msg);
}


/**
 * @brief return write/read reference to the first element
 */
std::string &
wy_StrBlob::front()
{
    check(0,"front on empty wy_StrBlob");
    return  data->front();
}


/**
 * @brief return a read-only (const) reference to the first element
 */
const std::string &
wy_StrBlob::front() const
{
    check(0, "front on empty wy_StrBlob");
    return  data->front();
}

/**
 * @brief return write/read reference to the last element
 */
std::string &
wy_StrBlob::back()
{
    check(0,"back on empty wy_StrBlob");
    return  data->back();
}


/**
 * @brief return a read-only (const) reference to the last element
 */
const std::string &
wy_StrBlob::back() const
{
    check(0, "back on empty wy_StrBlob");
    return data->back();
}

/**
 * @brief Return wy_StrBlobPtr to the first element of the vector
 */
wy_StrBlobPtr
wy_StrBlob::begin()
{
    return wy_StrBlobPtr(*this);
}

/**
 * @brief Return the one past last elment of the vecor.
 */
wy_StrBlobPtr wy_StrBlob::end()
{
    return wy_StrBlobPtr(*this, data->size());
}


/**
 * @brief Remove last element
 */
void wy_StrBlob::pop_back()
{
    check(0, "pop_back on empty wy_StrBlob");
    data->pop_back();
}
