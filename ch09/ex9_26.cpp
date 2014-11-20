//!
//! @author @huangjuncmj @Alan
//! @date   19.11.2014
//!
//! Exercise 9.26:
//! Using the following definition of ia, copy ia into a vector and into a list.
//! Use the single-iterator form of erase to remove the elements with odd values from your
//! list and the even values from your vector.
//!
#include <iostream>
#include <vector>
#include <list>


int main()
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

    //! init
    std::vector<int> vec;
    std::vector<int> lst;
    for(auto i : ia)
    {
        vec.push_back(i);
        lst.push_back(i);
    }

    //! remove odd value
    for(auto it = lst.begin();  it != lst.end();    )
        if(*it & 0x1)       it = lst.erase(it);     else    ++it;

    //! remove even value
    for(auto it = vec.begin();  it != vec.end();    )
        if(!(*it & 0x1))    it = vec.erase(it);     else    ++it;

    //! print
    std::cout << "list : ";
    for(auto i : lst)   std::cout << i << " ";
    std::cout << "\nvector : ";
    for(auto i : vec)   std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
