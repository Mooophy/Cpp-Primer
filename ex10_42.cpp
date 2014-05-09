//! @Alan
//!
//! Exercise 10.42:
//! Reimplement the program that eliminated duplicate words that
//! we wrote in § 10.2.3 (p. 383) to use a list instead of a vector.
//!

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <list>


int main()
{
    std::list<std::string> l = {"aa","aa","aa","aa","aasss","aa"};
    l.unique();

    for(auto e : l)
        std::cout << e << " ";

    return 0;
}
