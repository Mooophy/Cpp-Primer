#ifndef ALAN_H
#define ALAN_H

#include <string>
#include <iostream>

void alan(const std::string &s = "")
{
    std::cout << "\033[1;32m@Alan:"
              << s
              << "\033[0m"
              << std::endl;
}

#endif // ALAN_H
