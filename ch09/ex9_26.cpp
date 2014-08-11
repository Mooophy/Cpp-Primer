//! @Alan
//!
//! Exercise 9.26:
//! Using the following definition of ia, copy ia into a vector and into a list.
//! Use the single-iterator form of erase to remove the elements with odd values from your
//! list and the even values from your vector.
//  note the subtle difference between list and vector.
//!
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>


int main()
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

    //! cal the lenth of the array.
    int size = sizeof(ia)/sizeof(int);

    std::vector<int> v;
    std::list<int> l;

    // copy in to v and l
    for (auto *p = ia; p != ia + size ; ++p)
    {
        v.push_back(*p);
        l.push_back(*p);
    }

    // ease even value element from v
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if((*it)%2 == 0)
        {
            v.erase(it);
        }
    }
    //print content of v
    for(auto it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it <<" ";
    }

    std::cout << "\n";


    //ease odd value element from l
    for(auto it = l.begin(); it != l.end(); ++it)
    {
        if((*it)%2 == 1)
        {
            l.erase(it);

            //! @note without this statement it does not work
            --it;
        }
    }
    //print l
    for (auto it = l.begin(); it != l.end(); ++it)
    {
        std::cout << *it << " ";
    }





    return 0;
}
