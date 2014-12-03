//! @Alan
//!
//! Exercise 9.38:
//! Write a program to explore how vectors grow in the library you use.
//!

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> v;
    std::string word;

    while (std::cin >> word)
    {
        v.push_back(word);
        std::cout << v.capacity() << "\n";
    }

    return 0;
}

