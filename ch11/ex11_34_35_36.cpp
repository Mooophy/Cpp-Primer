//! @Alan
//!
//! Exercise 11.34:
//! What would happen if we used the subscript operator instead of find in the transform function?
//  If the subscript operator was used instead, it would add the given key into the map when no element
//  with matching key was found.
//!
//! Exercise 11.35: In buildMap, what effect, if any, would there be from rewriting
//!         trans_map[key] = value.substr(1);
//!         as
//!         trans_map.insert({key, value.substr(1)})?
//  They should be the same thing.
//!
//! Exercise 11.36:
//! Our program does no checking on the validity of either input file. In particular, it assumes that
//! the rules in the transformation file are all sensible.
//! What would happen if a line in that file has a key, one space, and then the end of the line?
//! Predict the behavior and then check it against your version of the program.
//  As can be seen from the executing outcome, the programe will output an empty string instead.
//!
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

        value   =   line.substr(line.find(' ') + 1);
        rules_map[key] = value;
    }
    fin.close();


    //! Read the input file ,transform it and print
    fin.open(inputFileName);
    std::string text;

    while(std::getline(fin, text))
    {
        std::istringstream stream(text);

        std::string word;
        while(stream >> word)

        {
            //! obtain the iterator using the key given
            std::map<std::string, std::string>::const_iterator
                    it = rules_map.find(word);

            //! check if the give key is found in the map
            std::cout << (it == rules_map.end() ? word +" " : it->second + " ");
        }
        std::cout <<"\n";
    }
}
