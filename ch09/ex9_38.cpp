//! @Alan
//!
//! Exercise 9.38:
//! Write a program to explore how vectors grow in the library you use.
//!



#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>




int main()
{
    std::vector<std::string> v;
    std::string word;

    while(std::cin>>word)
    {
        v.push_back(word);
        std::cout << v.capacity() << "\n";
    }



    return 0;
}

