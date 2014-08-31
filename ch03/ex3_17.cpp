//!
//! @alan
//!
//! Exercise 3.17:
//!     Read a sequence of words from cin and store the values a vector.
//!     After you’ve read all the words, process the vector and change
//!     each word to uppercase. Print the transformed elements, eight words
//!     to a line.

#include <iostream>
#include <string>
#include <vector>

int main()
{
    //! prompt
    std::cout << "Pls enter , @q to quit.\n";

    //! input
    std::vector<std::string>  text{};
    for(std::string str{}; std::cin >> str   &&  str != "@q";/* */)
    {
        for(auto& c : str)
            c = std::toupper(c);
        text.push_back(str);
        std::cout << "next entry:\n";
    }

    //! output
    unsigned count = 0;
    for(const auto& word : text)
    {
	std::cout << word  << (count++ == 7?    "\n" :   " ");
        count %= 8;
    }

    return 0;
}

