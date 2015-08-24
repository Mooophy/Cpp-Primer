//
//  ex8_09.cpp
//  Exercise 8.9
//
//  Created by pezy on 11/29/14.
//
//  @Brief  Use the function you wrote for the first exercise in § 8.1.2 (p.314) to print the contents of an istringstream object.
//  @See    Exercise 8.1

#include <iostream>
#include <sstream>
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
    std::istringstream iss("hello");
    func(iss);
    return 0;
}
