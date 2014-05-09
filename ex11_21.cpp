//! @Alan
//!
//! Exercise 11.21:
//! Assuming word_count is a map from string to size_t and word is a string,
//! explain the following loop:
//!     while (cin >> word)
//!     ++word_count.insert({word, 0}).first->second;
//!

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <iterator>

int main()
{
    std::map<std::string, size_t> word_count;
    std::string word;

    while(std::cin >> word)
    {
        /*
        //! insert the pair {word,0} into the map and get the iterator.
        auto it = word_count.insert({word,0});

        //! check if the pair is inserted
        //! if not, increment the value of the key-value of the pair
        if(!it.second)
            ++it.first->second;
        */
        ++word_count.insert({word, 0}).first->second;
//!     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//!     similiar to the codes above it, but more accurate and efficient
//!     the increment operator "++" is excuted as ++ (word_count.insert({word, 0}).first->second)
        //! print the content of the map.
        for(auto e : word_count)
            std::cout << e.first << " "
                      << e.second << "\n";
    }

    return 0;
}
