//! @Alan
//! Exercise 10.26:
//! Explain the differences among the three kinds of insert iterators.
//  back_inserter creates an iterator that uses push_back.
//
//  front_inserter creates an iterator that uses push_front.
//
//  inserter creates an iterator that uses insert. This function takes
//  a second argument, which must be an iterator into the given container.
//  Elements are inserted ahead of the element denoted by the given iterator.
//!
//! Exercise 10.27:
//! In addition to unique (§ 10.2.3, p. 384), the library defines function
//! named unique_copy that takes a third iterator denoting a destination
//! into which to copy the unique elements. Write a program that uses unique_copy
//! to copy the unique elements from a vector into an initially empty list.
//!
//! Exercise 10.28:
//! Copy a vector that holds the values from 1 to 9 inclusive, into three
//! other containers. Use an inserter, a back_inserter, and a front_inserter,
//! respectivly to add elements to these containers.
//! Predict how the output sequence varies by the kind of inserter and verify
//! your predictions by running your programs.
//!


#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

//! Exercise 10.27
void
ex10_27(const std::vector<std::string> &v, std::list<std::string> &l);

//! Exercise 10.28
//  1 2 3 4 5
void
inserter_ex(const std::vector<int> &v, std::list<int> &l);

//  1 2 3 4 5
void
backInserter_ex(const std::vector<int> &v, std::list<int> &l);

//  5 4 3 2 1
void
frontInserter_ex(const std::vector<int> &v, std::list<int> &l);



int main()
{
    //! test for Exercise 10.27
    std::vector<std::string> v = {"aa","aa","aa","aa","aaa"};
    std::list<std::string> l;
    ex10_27(v, l);

    for(auto e : l)
        std::cout << e <<" ";
    std::cout << "\n============END==========\n";

    //! test for Exercise 10.28
    std::vector<int> vi = {1,2,3,4,5};


    std::list<int> l_inserter;
    inserter_ex(vi,l_inserter);
    for(auto e : l_inserter)
        std::cout << e <<" ";
    std::cout << "\n============END==========\n";

    std::list<int> l_b_inserter;
    backInserter_ex(vi,l_b_inserter);
        for(auto e : l_b_inserter)
        std::cout << e <<" ";
    std::cout << "\n============END==========\n";

    std::list<int> l_f_inserter;
    frontInserter_ex(vi,l_f_inserter);
        for(auto e : l_f_inserter)
        std::cout << e <<" ";
    std::cout << "\n============END==========\n";


    return 0;
}


inline void
ex10_27(const std::vector<std::string> &v, std::list<std::string> &l)
{
    std::unique_copy(v.cbegin(), v.cend(), std::back_inserter(l));
}


inline void
inserter_ex(const std::vector<int> &v, std::list<int> &l)
{
    std::copy(v.cbegin(), v.cend(), std::inserter(l,l.begin()));
}

inline void
backInserter_ex(const std::vector<int> &v, std::list<int> &l)
{
    std::copy(v.cbegin(), v.cend(), std::back_inserter(l));
}


inline void
frontInserter_ex(const std::vector<int> &v, std::list<int> &l)
{
    std::copy(v.cbegin(), v.cend(),std::front_inserter(l));
}
