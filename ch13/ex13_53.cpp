#include "ex13_53.h"
#include <iostream>

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "call swap" << std::endl;
}

HasPtr::HasPtr(const std::string &s) : ps(new std::string(s)), i(0)
{
    std::cout << "call constructor" << std::endl;
}

HasPtr::HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i)
{
    std::cout << "call copy constructor" << std::endl;
}

HasPtr::HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i)
{
    p.ps = 0;
    std::cout << "call move constructor" << std::endl;
}

HasPtr& HasPtr::operator=(HasPtr rhs)
{
    swap(*this, rhs);
    return *this;
}

HasPtr::~HasPtr()
{
    std::cout << "call destructor" << std::endl;
    delete ps;
}

int main()
{
    return 0;
}
