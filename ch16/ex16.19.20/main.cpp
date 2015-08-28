/***************************************************************************
 *  @file       main.cpp
 *  @author     Yue Wang
 *  @date       03  Feb 2014
 *              Aug 2015       
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 16.19:
// Write a function that takes a reference to a container and prints the
// elements in that container. Use the container’s size_type and size members
// to control the loop that prints the elements.
//
// Exercise 16.20:
// Rewrite the function from the previous exercise to use iterators returned
// from begin and end to control the loop.
//

#include <iostream>
#include <vector>
#include <list>

// ex16.19
template<typename Container>
std::ostream& print(Container const& container, std::ostream& os)
{
    for(typename Container::size_type i = 0; i != container.size(); ++ i)
        os << container[i] << " ";
    return os;
}

// ex16.20
template<typename Container>
std::ostream& print2(Container const& container, std::ostream &os)
{
    for(auto curr = container.cbegin(); curr != container.cend(); ++curr)
        os << *curr << " ";
    return os;
}


int main()
{
    std::vector<int> v = { 1, 23, 6, 4, 5, 7, 4 };
    std::list<std::string> l = { "ss", "sszz", "saaas", "s333s", "ss2"," sss" };
    print2(v, std::cout) << std::endl;
    print2(l, std::cout) << std::endl;

    return 0;
}
