//! @Alan
//!
//! Exercise 9.14:
//! Write a program to assign the elements from a list of char* pointers
//! to C-style character strings
//  not done
//! to a vector of strings.
//!
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>


int main()
{
    std::list<char*> l(10);
    std::vector<std::string> v;
    v.assign(l.cbegin(), l.cend());

    return 0;
}
