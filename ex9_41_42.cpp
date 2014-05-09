//! @Alan
//!
//! Exercise 9.41:
//! Write a program that initializes a string from a vector<char>.
//!
//! Exercise 9.42:
//! Given that you want to read a character at a time into a string,
//! and you know that you need to read at least 100 characters,
//! how might you improve the performance of your program?
//  Use member reserve(120) to allocate enough space for this string.
//!

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

//! Exercise 9.41
void str_from_vectorChar(const std::vector<char>&,   std::string&);
int main()
{
    //! test for str_from_vectorChar():
    std::string s;
    std::vector<char> v = {'a','a','a','a','c'};

    str_from_vectorChar(v,s);

    std::cout<< s;


    return 0;
}


void str_from_vectorChar(const std::vector<char> &v, std::string &s)
{
    for(auto it = v.begin(); it != v.end(); ++it)
    {
        s.push_back(*it);
    }
}
