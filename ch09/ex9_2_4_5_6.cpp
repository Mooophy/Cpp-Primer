//! @Alan
//!
//! Exercise 9.2:
//! Define a list that holds elements that are deques that hold ints.
//!
//! Exercise 9.4:
//! Write a function that takes a pair of iterators to a vector<int> and an int value.
//! Look for that value in the range and return a bool indicating whether it was found.
//!
//! Exercise 9.5:
//! Rewrite the previous program to return an iterator to the requested element.
//! Note that the program must handle the case where the element is not found.
//!
//! Exercise 9.6:
//! What is wrong with the following program? How might you correct it?
//!
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>

//! Exercise 9.2
std::vector <std::deque<int>> vdi;

//! Exercise 9.4
bool find(const std::vector<int>::iterator &first,   const std::vector<int>::iterator &last, int val);

//! Exercise 9.5
std::vector<int>::iterator find2(const std::vector<int>::iterator &first,   const std::vector<int>::iterator &last, int val);
int main()
{
    //! Exercise 9.6
    std::list<int> lst1;
    std::list<int>::iterator iter1 = lst1.begin(),
                             iter2 = lst1.end();


    while (iter1 != iter2) /* ... */
    //!          ^^
    //!  < > can not be used for list.


    return 0;
}

bool find(const std::vector<int>::iterator &first, const std::vector<int>::iterator &last, int val)
{
    for (std::vector<int>::iterator  it = first; it!= last; ++it )
    {
        if (*it == val) return true;
    }

    return false;
}
std::vector<int>::iterator find2(const std::vector<int>::iterator &first, const std::vector<int>::iterator &last, int val)
{
    for (std::vector<int>::iterator  it = first; it!= last; ++it )
    {
        if (*it == val) return it;
    }


    //! when not found.
    return last + 1;
}
