//! @Alan
//!
//!
//! Exercise 11.33:
//! Implement your own version of the word-transformation program.
//  I used one function to for this exercise. It proved that
//  less functions are harder to debug. Besides, the comment style shoud be polished.
//!

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

//!
//! \brief wy_word_transformation for ex 11.33
//! \param rulesFileName    const   string&
//! \param inputFileName    const   string&
//!
void
wy_word_transformation(const std::string &rulesFileName, const std::string &inputFileName);
int main()
{
    wy_word_transformation("rules.txt","original.txt");
    return 0;
}


void
wy_word_transformation(const std::string &rulesFileName, const std::string &inputFileName)
{
    //! Build rules map
    std::ifstream fin(rulesFileName);
    std::string line;
    std::map<std::string, std::string> rules_map;

    while(std::getline(fin,line))
    {
        std::string key, value;
        key     =   line.substr(0, line.find(' '));
        //!                             ^^^^^^^^^
        //! @note
        //! Suppose the line is
        //          where r u
        //!              ^
        //!         012345
        //! the statement becomes
        //          line.substr(0,5)
        //!                       ^
        //! which means returnning a new string using 5 characters starting at 0.

        value   =   line.substr(line.find(' ') + 1);
        //! @note                              ^^^
        //! the + 1 here increment the index so from the space to next character.
        //! size_t n is the second parameter whose defualt value is npos. If leave
        //! it as default, it means "until the end of the string"

        //! add the key-value pair into the map.
        rules_map[key] = value;
    }
    fin.close();


    //! Read the input file ,transform it and print
    fin.open(inputFileName);
    std::string text;

    while(std::getline(fin, text))
    {
        std::istringstream stream(text);
//!     ^^^^^^^^^^^^^^^^^^

        std::string word;
        while(stream >> word)
//!           ^^^^^^^^^^^^^^
//! @attention
//! std::istringstream is quite a handy way to handle spaces in a string, far more convinient
//! than generic algorithm or search a space manually.

        {
            //! obtain the iterator using the key given
            std::map<std::string, std::string>::const_iterator
                    it = rules_map.find(word);

            //! check if the give key is found in the map
            std::cout << (it == rules_map.end() ? word +" " : it->second + " ");
            //!          ^                                                    ^
            //! @attention  the parentheses are necessay here.
        }
        std::cout <<"\n";
    }
}
