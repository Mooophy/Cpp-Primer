//! @Alan
//! Exercise 10.11:
//! Write a program that uses stable_sort and isShorter to sort a vector passed
//! to your version of elimDups.
//! Print the vector to verify that your program is correct.
//!

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <list>

//! Exercise 10.11
//! @note   Predicate for this exercise.
inline bool
isShorter(const std::string &s1, const std::string &s2);

//! Exercise 10.9
void
wy_elimdups(std::vector<std::string> &vs);

int main()
{
    //! Exercise 10.9
    std::vector<std::string> vs = {"asss","v","ass","s","aaaa","aa","aa"};
    wy_elimdups(vs);

    //! Exercise 10.9
    std::stable_sort(vs.begin(), vs.end(), isShorter);

    for (auto element : vs)
        std::cout << element
                  <<" ";
    std::cout <<"\n";

    return 0;
}


//! Exercise 10.9
void wy_elimdups(std::vector<std::string> &vs)
{
    for (auto element : vs)
        std::cout << element
                  <<" ";
    std::cout <<"\n";


    //! sort alphabetically
    std::sort(vs.begin(), vs.end());
    for (auto element : vs)
        std::cout << element
                  <<" ";
    std::cout <<"\n";


    //! put all duplicates at the end of the vector
    //! and get the iterator pointing to the one past
    //! the last unique element.
    auto unique_iterator = std::unique(vs.begin(),vs.end());
    for (auto element : vs)
        std::cout << element
                  <<" ";
    std::cout <<"\n";


    vs.erase(unique_iterator, vs.end());
    for (auto element : vs)
        std::cout << element
                  <<" ";
    std::cout <<"\n";
}

//! Exercise 10.9
inline bool
isShorter(const std::string &s1, const std::string &s2)
{
    return  s1.size() < s2.size();
}
