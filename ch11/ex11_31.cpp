//! @Alan
//!
//! Exercise 11.31:
//! Write a program that defines a multimap of authors and their works.
//! Use find to find an element in the multimap and erase that element.
//      ^^^^         ^^^^^^^^^^
//! Be sure your program works correctly if the element you look for is
//! not in the map.
//!

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

//!
//! \brief remove_works     for ex 11.31
//! \param s                the key value to be removed
//! \param m                the multi map to be operated on
//!
//! this funciton just erase the first matching element.
void
remove_works(const std::string &s, std::multimap<std::string, std::string> &m);

int main()
{
    //! define the multimap
    std::multimap<std::string, std::string> m = {{"Alan","111"},{"Alan","112"},{"Alan","113"},{"Wang","222"}};

    //! print the content
    for(const auto &e : m)
        std::cout << e.first << " " << e.second <<"\n";

    std::cout <<"====================\n";

    //! call the function to do as required.
    remove_works("Alan",m);

    //! print the content
    for(const auto &e : m)
        std::cout << e.first << " " << e.second <<"\n";

    return 0;
}


void
remove_works(const std::string &s, std::multimap<std::string, std::string> &m)
{
    std::multimap<std::string, std::string>::iterator it = m.find(s);
//!                                                          ^^^^
//!If successful the function returns an iterator pointing to the sought after %pair.
//!If unsuccessful it returns the past-the-end ( @c end() ) iterator.

    if(it != m.end())   m.erase(it);
    //!                         ^^
    //! @param  __position  An iterator pointing to the element to be erased.
}
