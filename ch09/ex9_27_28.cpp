//! @Alan
//!
//! Exercise 9.27:
//! Write a program to find and remove the odd-valued elements in a forward_list<int>.
//!
//! Exercise 9.28:
//! Write a function that takes a forward_list<string> and two additional string arguments.
//! The function should find the first string and insert the second immediately following the first.
//! If the first string is not found, then insert the second string at the end of the list.
//!
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

void ex927(void);

//! Exercise 9.28
std::forward_list<std::string>&
find_insert(std::forward_list<std::string>&, const std::string&, const std::string& );

int main()
{
    //! function test :
    std::forward_list<std::string> flst = {"11","22","33","44"};
    find_insert(flst,"22","zz");

    for(auto it = flst.begin(); it != flst.end(); ++it)
    {
        std::cout << *it << " ";
    }

    return 0;
}


void ex927()
{
    std::forward_list<int> fl={1,2,3,4,5,6,77,99,111};

    auto prev = fl.before_begin();
    auto curr = fl.begin();

    //! remove odd value elements.
    while(curr != fl.end())
    {
        if(*curr %2)    // if odd
        {
            curr = fl.erase_after(prev);
        }
        else
        {
            prev = curr;
            ++curr;
        }
    }

    //! print the changed forwad_list
    for (auto it = fl.begin(); it != fl.end(); ++it)
    {
        std::cout << *it << " ";
    }
}

//! Exercise 9.28
std::forward_list<std::string> &
find_insert(std::forward_list<std::string> & flst, const std::string &s_find, const std::string &s_insert)
{
    auto curr = flst.begin();
    auto prev = flst.before_begin();

    while(curr != flst.end())
    {
        if(!s_find.compare(*curr))
        {
            flst.insert_after(curr, s_insert);
            return flst;
        }
        ++curr;
        ++prev;
    }

    if(flst.begin() != flst.end())
    {
        flst.insert_after(prev, s_insert);
    }

    return flst;

}
