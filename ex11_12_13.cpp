//! @Alan
//! Exercise 11.12:
//! Write a program to read a sequence of strings and ints, storing
//! each into a pair. Store the pairs in a vector.
//!
//! Exercise 11.13:
//! There are at least three ways to create the pairs in the program
//! for the previous exercise. Write three versions of that program,
//! creating the pairs in each way. Explain which form you think is
//! easiest to write and understand, and why.
//!
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <list>
#include <set>
#include <utility>


int main()
{
    int i;
    std::string word;

    std::pair<std::string, int> pair;
    std::vector<std::pair<std::string, int>> v;

    while([&]()
    {
          std::cout << "enter a word:\n";
          std::cin >> word;
          std::cout << "enter an int:\n";
          std::cin >> i;

          return word != "@q";
}())
    {
        //! way 1:
        //pair = {word, i};
     //!^^^^^^^^^^^^^^^^^^^
        //! way one is the easiest to write and understand.
        //! way 2:
        //pair = std::make_pair(word,i);
        //! way 3:
        pair = std::pair<std::string, int>(word,i);

        v.push_back(pair);
        for(auto e : v)
            std::cout << e.first << " "
                      << e.second << " ";
        std::cout << "\n";
    }
    return 0;
}


