//! @Alan
//!
//! Exercise 11.20:
//! Rewrite the word-counting program from § 11.1 (p. 421) to use insert instead
//! of subscripting. Which program do you think is easier to write and read?
//! Explain your reasoning.
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
        //! insert the pair {word,0} into the map and get the iterator.
        auto it = word_count.insert({word,0});

        //! check if the pair is inserted
        //! if not, increment the value of the key-value of the pair
        if(!it.second)
            ++it.first->second;

        //! print the content of the map.
        for(auto e : word_count)
            std::cout << e.first << " "
                      << e.second << "\n";
    }


    return 0;
}
