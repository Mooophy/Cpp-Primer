#ifndef BLOBPTR_H
#define BLOBPTR_H

#include "Blob.h"
#include <memory>
#include <vector>

template <typename> class BlobPtr;

template <typename T>
bool operator ==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

template <typename T>
bool operator < (const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);


template<typename T> class BlobPtr
{
    friend bool operator ==<T>
    (const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

    friend bool operator < <T>
    (const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

public:
    BlobPtr() : curr(0) { }
    BlobPtr(Blob<T>& a, std::size_t sz = 0) :
        wptr(a.data), curr(sz) { }

    T& operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    //! prefix
    BlobPtr& operator++();
    BlobPtr& operator--();

    //! postfix
    BlobPtr operator ++(int);
    BlobPtr operator --(int);

private:
    //! returns  a shared_ptr to the vector if the check succeeds
    std::shared_ptr<std::vector<T>>
         check(std::size_t, const std::string&) const;

    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;

};

//! prefix ++
template<typename T>
BlobPtr<T>& BlobPtr<T>::operator ++()
{
    //! if curr already points past the end of the container, can't increment it
    check(curr,"increment past end of StrBlob");
    ++curr;
    return *this;
}

//! prefix --
template<typename T>
BlobPtr<T>& BlobPtr<T>::operator --()
{
    -- curr;
    check(curr,"decrement past begin of BlobPtr");

    return *this;
}


//! postfix ++
template<typename T>
BlobPtr<T> BlobPtr<T>::operator ++(int)
{
    BlobPtr ret = *this;
    ++*this;

    return ret;
}

//! postfix --
template<typename T>
BlobPtr<T> BlobPtr<T>::operator --(int)
{
    BlobPtr ret = *this;
    --*this;

    return ret;
}

#endif // BLOBPTR_H
