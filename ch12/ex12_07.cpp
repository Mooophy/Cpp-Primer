/***************************************************************************
*  @file       The code is for the exercises in C++ Primmer 5th Edition
*  @author     Yue Wang
*  @date       22  DEC 2013
*                  Oct 2015
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
// Exercise 12.7:
// Redo the previous exercise, this time using shared_ptr.
//

#include <iostream>
#include <vector>
#include <memory>

using Sptr = std::shared_ptr < std::vector<int> > ;

auto make_with_shared_ptr()
{
    return std::make_shared<std::vector<int>>();
}

auto populate(Sptr vec)
{
    for (int i; std::cout << "Pls Enter:\n", std::cin >> i; vec->push_back(i));
    return vec;
}

auto print(Sptr vec) -> std::ostream&
{
    for (auto i : *vec) std::cout << i << " ";
    return std::cout;
}

int main()
{
    auto vec = populate(make_with_shared_ptr());
    print(vec) << std::endl;

    return 0;
}
