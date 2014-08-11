/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       03  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 16.19:
//! Write a function that takes a reference to a container and prints the
//! elements in that container. Use the container’s size_type and size members
//! to control the loop that prints the elements.
//!
//! Exercise 16.20:
//! Rewrite the function from the previous exercise to use iterators returned
//! from begin and end to control the loop.
//!

#include <iostream>
#include <vector>
#include <list>

//! ex16.19
template<typename Container>
std::ostream& print(Container& c);

//! ex16.20
template<typename Container>
std::ostream& print2(Container& c);

int main()
{
    std::vector<int> v = {1,23,6,4,5,7,4};
    std::list<std::string> l = {"ss","sszz","saaas","s333s","ss2","sss"};
    print2(v);
    print2(l);




    return 0;
}

//! ex16.19 using size() to control the loop
template<typename Container>
std::ostream & print(Container &c)
{
    typedef typename Container::size_type size_type;

    auto it = c.begin();
    for(size_type i = 0; i!= c.size(); ++i)
        std::cout << *it++ << "\n";

    return std::cout;
}

//! ex16.20 using iterator to control the loop
template<typename Container>
std::ostream& print2(Container& c)
{
    for (auto it = c.begin(); it != c.end(); ++it)
        std::cout << *it << "\n";

    return std::cout;
}
