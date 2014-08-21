//! @Alan
//! Exercise 11.11:
//! Redefine bookstore without using decltype.
//  discussion on stack overflow:
//  http://stackoverflow.com/questions/20608365/is-it-possible-to-code-this-waywhilelambda
//!
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <list>
#include <set>



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
    //! more approaches can be found on the post of SO.
    bool (*fp) (const A &a1, const A &a2) = compareA;

    std::multiset<A, bool (*) (const A &, const A &)> m1(fp);

    return 0;
}


