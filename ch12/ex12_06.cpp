/***************************************************************************
*  @file       The code is for the exercises in C++ Primmer 5th Edition
*  @author     Yue Wang
*  @date       22  DEC 2013
*              Jun 2015
*              Oct 2015
*  @remark
***************************************************************************/
//
// Exercise 12.6:
// Write a function that returns a dynamically allocated vector of ints.
// Pass that vector to another function that reads the standard input to
// give values to the elements. Pass the vector to another function to print
// the values that were read.
// Remember to delete the vector at the appropriate time.
//

#include <iostream>
#include <vector>

using Ptr = std::vector<int>*;

auto make_dynamically()
{
    return new std::vector < int > { };
}

auto populate(Ptr vec)
{
    for (int i; std::cout << "Pls Enter:\n", std::cin >> i; vec->push_back(i));
    return vec;
}

auto print(Ptr vec) -> std::ostream&
{
    for (auto i : *vec) std::cout << i << " ";
    return std::cout;
}

int main()
{
    auto vec = populate(make_dynamically());
    print(vec) << std::endl;
    delete vec;

    return 0;
}
