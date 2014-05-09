//! @Alan
//!
//! Exercise 11.19:
//! Define a variable that you initialize by calling begin() on the multiset
//! named bookstore from § 11.2.2 (p. 425). Write the variable’s type without
//! using auto or decltype.
//!

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <iterator>
class A
{
    int lenth;
public:
    int getLenth() const {return lenth;}
};

bool compareA(const A &a1, const A &a2)
{
    return a1.getLenth() < a2.getLenth();
}
int main()
{
    bool (*fp) (const A &a1, const A &a2) = compareA;

    std::multiset<A, bool (*) (const A &, const A &)> m1(fp);

    //! Exercise 11.19
    std::multiset<A, bool(*) (const A &, const A &)>::iterator
            begin = m1.begin();

    return 0;
}
