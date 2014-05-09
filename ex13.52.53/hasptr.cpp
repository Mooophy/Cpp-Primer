#include "hasptr.h"

//! specific swap.
inline void
swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
    swap(lhs.i, rhs.i);   // swap the int members

    std::cout <<"swapping!\n";
}

//! operator = using specific swap
HasPtr&
HasPtr::operator = (HasPtr rhs)
{
    swap(*this,rhs);
    return *this;
}

//! operator < overloading
inline bool
operator <(const HasPtr& lhs, const HasPtr& rhs)
{
    std::cout << "<ing\n";
    return *lhs.ps < *rhs.ps;
}
