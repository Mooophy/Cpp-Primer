/***************************************************************************
 *  @file       StrBlobPtr_pointer.h
 *  @author     Alan.W
 *  @date       19  JAN 2014
 *  @remark     a class that holds a pointer to a StrBlobPtr.
 ***************************************************************************/

#ifndef STRBLOBPTR_POINTER_H
#define STRBLOBPTR_POINTER_H

class StrBlobPtr;

/**
 * @brief a class that holds a pointer to a StrBlobPtr.
 */
class StrBlobPtr_pointer
{
public:
    StrBlobPtr_pointer() = default;
    StrBlobPtr_pointer(StrBlobPtr* p) : pointer(p) { }

    StrBlobPtr& operator *() const;
    StrBlobPtr* operator->() const;

private:
    StrBlobPtr* pointer = nullptr;
};

#endif // STRBLOBPTR_POINTER_H
