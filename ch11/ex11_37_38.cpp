/***************************************************************************
 *  @file       Thes code is for the exercises in C++ Primmer 5th Edition
 *  @author     Alan.W
 *  @date       21  DEC 2013
 *  @remark
 ***************************************************************************/
//!
//! Exercise 11.37
//! What are the advantages of an unordered container as compared to the ordered version of that
//! container? What are the advantages of the ordered version?
//  An unordered container is most useful when we have a key type for which there is no obvious
//  ordering relationship among the elements. These containers are also useful for applications
//  in which the cost of maintaining the elements in order is prohibitive.
//!
//! Exercise 11.38:
//! Rewrite the word-counting (§ 11.1, p. 421) and word-transformation (§ 11.3.6, p. 440) programs
//! to use an unordered_map.
//  So far as used in the two programme, the usage of unodered_map is the same as map's.
//!


#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

void
word_count(std::unordered_map<std::string, int> &m);

void
wy_word_transformation(const std::string &rulesFileName, const std::string &inputFileName);

int main()
{
    /**
     * @brief test for word-counting    using unordered_map
     */
    std::unordered_map<std::string, int> m;
    word_count(m);



    /**
     * @brief wy_word_transformation    using unordered_map
     */
    wy_word_transformation("rules.txt", "original.txt");

    return 0;
}

/**
 * @brief word_count
 *
 *  Using unordered_map instead of map.
 */
void word_count(std::unordered_map<std::string, int> &m)
{
    std::string word;
    while(std::cin >> word && word != "@q")
        ++m[word];

    for(const auto &e : m)
        std::cout << e.first << " : " << e.second << "\n";

}

/**
 * @brief wy_word_transformation
 *
 *  Using unordered_map instead of map.
 */
void wy_word_transformation(const std::string &rulesFileName, const std::string &inputFileName)
{
    /**
     * @brief   Build rules map Using unordered_map
     */
    std::ifstream fin(rulesFileName);
    std::string line;
    std::unordered_map<std::string, std::string> rules_map;
    //!  ^^^^^^^^^^^^^

    while(std::getline(fin,line))
    {
        std::string key, value;
        key     =   line.substr(0, line.find(' '));
        value   =   line.substr(line.find(' ') + 1);
        rules_map[key] = value;
    }
    fin.close();

    /**
     * @brief   Read the input file, transform it and print.
     */
    fin.open(inputFileName);
    std::string text;

    while(std::getline(fin, text))
    {
        std::istringstream stream(text);
        std::string word;
        while(stream >> word)
        {
            //! obtain the iterator using the key given
            std::unordered_map<std::string, std::string>::const_iterator
                    it = rules_map.find(word);

            //! check if the give key is found in the map
            std::cout << (it == rules_map.end() ? word +" " : it->second + " ");
            //! @note:   ^                                                    ^
        }
        std::cout <<"\n";
    }

}
