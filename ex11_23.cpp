//! @Alan
//!
//! Exercise 11.23:
//! Rewrite the map that stored vectors of children’s names with a key that is
//! the family last name for the exercises in § 11.2.1 (p. 424) to use a multimap.
//  note that multimap has no [] operator defined.
//! 	
//! Exercise 11.7:
//! Define a map for which the key is the family’s last name and
//! the value is a vector of the children’s names. Write code to
//! add new families and to add new children to an existing family.
//  Discussion on Stack Overflow:
//  http://stackoverflow.com/questions/20608365/is-it-possible-to-code-this-waywhilelambda
//!

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
    std::multimap<std::string, std::vector<std::string>> faml;

    std::string lastName, childName;
    std::vector<std::string> v_chidrenName;

    //! read the last name
    while(std::cin >> lastName && lastName != "@q")
    {
        std::cout << "please input all children's names.Enter @q when input is done\n";

        //! read the children's names
        while(std::cin >> childName && childName != "@q")
            v_chidrenName.push_back(childName);


        //! using {} to create a pair and inert it into the multimap
        faml.insert({lastName,v_chidrenName});

        std::cout << "enter another last name:\n";
    }

    //! print the content of the multimap
    for(const auto &e : faml)
    {
        std::cout << e.first << ":\n";

        for(const auto &l : e.second)
            std::cout << l << " ";

        std::cout << "\n";
    }

    return 0;
}
