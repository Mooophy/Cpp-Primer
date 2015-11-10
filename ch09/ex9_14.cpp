// @Yue Wang @pezy
//
// Exercise 9.14:
// Write a program to assign the elements from a list of char* pointers
// to C-style character strings
//

#include <iostream>
#include <string>
#include <vector>
#include <list>

int main()
{
    std::list<const char*> l{ "Mooophy", "pezy", "Queeuqueg" };
    std::vector<std::string> v;
    v.assign(l.cbegin(), l.cend());
    for (auto ptr : v)
        std::cout << ptr << std::endl;

    return 0;
}
