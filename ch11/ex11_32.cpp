//! @Alan
//!
//!
//! Exercise 11.32:
//! Using the multimap from the previous exercise, write a program to
//! print the list of authors and their works alphabetically.
//!

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>



int main()
{
    //! define and initialize the multimap
    std::multimap<std::string, std::string> m = {{"lan","z111"},{"alan","a112"},{"Alan","a113"},{"cWang","g222"}};

    //! print the map without sorting
    for(const auto &e : m)
        std::cout << e.first << " " << e.second << "\n";
    std::cout << "\n";



    return 0;
}

