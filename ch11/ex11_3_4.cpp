//! @Alan
//!
//! Exercise 11.3:
//! Write your own version of the word-counting program.
//!
//! Exercise 11.4:
//! Extend your program to ignore case and punctuation.
//! For example, “example.” “example,” and “Example” should
//! all increment the same counter.
//!

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>

//! Exercise 11.4
void word_count_pro(std::map<std::string, int> &m)
{
    std::string word;
    while(std::cin >> word)
    {
        for(auto& ch : word)
            ch = tolower(ch);
        //! According to the erase-remove idiom.
        //! For more information about the erase-remove idiom, please refer to
        //! http://en.wikipedia.org/wiki/Erase-remove_idiom
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        ++m[word];
    }
    for (const auto &e : m)
        std::cout << e.first << " : " << e.second <<"\n";
}

//! Exercise 11.3
void ex11_3()
{
    std::map<std::string, std::size_t> word_count;
    std::string word;
    while(std::cin >> word)
        ++word_count[word];

    for (const auto &elem : word_count)
        std::cout << elem.first << " : " << elem.second <<"\n";
}

int main()
{
    std::map<std::string, int> m;
    word_count_pro(m);

    return 0;
}
