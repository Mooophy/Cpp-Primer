//
//  ex8_02.cpp
//  Exercise 8.2
//
//  Created by pezy on 11/27/14.
//
//  @Brief  Test your function by calling it, passing cin as an argument

#include <iostream>
using std::istream;

istream& func(istream &is)
{
    std::string buf;
    while (is >> buf)
        std::cout << buf << std::endl;
    is.clear();
    return is;
}

int main()
{
    istream& is = func(std::cin);
    std::cout << is.rdstate() << std::endl;
    return 0;
}
