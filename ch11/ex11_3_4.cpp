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
#include <string.h>
#include <set>
#include <algorithm>

//! Exercise 11.4:
void
w_count_pro(std::map<std::string, int> &m);

void
ex11_3(void);

int main()
{
    std::map<std::string, int> m;
    w_count_pro(m);

    return 0;
}



void ex11_3()
{
    std::map<std::string, std::size_t> word_count;
    std::string word;
    while(std::cin >> word && word != "@q")
    {
        ++word_count[word];
        for (const auto &e : word_count)
            std::cout << e.first << " : " << e.second <<"\n";
    }

}

//! Exercise 11.4:
//! Extend your program to ignore case and punctuation.
//! For example, “example.” “example,” and “Example” should
//! all increment the same counter.
void
w_count_pro(std::map<std::string, int> &m)
{
    std::string word;

    while(std::cin >> word && word != "@q")
    {
        //! convert to lowercase
        for(std::size_t i=0; i != word.size(); ++i)
        {
            word[i] = ::tolower(word[i]);
        }


        //! delete ',' or '.'
        auto punc_iter = std::find_if(word.begin(), word.end(),[] (const char c)
        {
            return c == '.' || c == ',';
        });

        if(punc_iter != word.end())
            word.erase(punc_iter);

        //! read into the map m
        ++m[word];

        //! print contents of m
        for (const auto &e : m)
            std::cout << e.first << " : " << e.second <<"\n";
    }
}
