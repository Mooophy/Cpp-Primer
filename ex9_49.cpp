//! @Alan
//!
//! Exercise 9.49:
//! A letter has an ascender if, as with d or f, part of the
//! letter extends above the middle of the line. A letter has
//! a descender if, as with p or g, part of the letter extends
//! below the line.
//! Write a program that reads a file containing words and reports
//! the longest word that contains neither ascenders nor descenders.
//!

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

//! Exercise 9.47
std::string
ex949(const std::string &fileName);

int main()
{
    std::cout << ex949("test.txt");
    return 0;
}


std::string
ex949(const std::string &fileName)
{
    std::string word;
    std::ifstream fin(fileName);

    //! store into a vector
    std::vector<std::string> v;
    while (fin >> word)
    {
        if(word.find_first_not_of("aceimnorsuvwxz") == std::string::npos)
        {
            v.push_back(word);
        }
    }

    //! move the longest into the string result
    std::string result;
    if(v.size() != 0)
    {
        for(auto it = v.begin(); it != v.end(); ++it)
        {
            if((*it).size() > result.size())    result = *it;
        }
    }

    return result;
}
