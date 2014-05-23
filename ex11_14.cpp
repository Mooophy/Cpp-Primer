//! @Alan
//! Exercise 11.14:
//! Extend the map of children to their family name that you wrote for the
//! exercises in § 11.2.1 (p. 424) by having the vector store a pair that
//! holds a child’s name and birthday.
//!
//! @Alan
//!
//! Exercise 11.7:
//! Define a map for which the key is the family’s last name and
//! the value is a vector of the children’s names. Write code to
//! add new families and to add new children to an existing family.
//!

#include <iostream>
#include <map>
#include <string>
#include <algorithm>



int main()
{
    //! define a map as required.
    std::map<std::string, std::vector<std::pair<std::string,std::string>>>
            famlies_map;
    //! declare three strings to store the input
    std::string lastName, childName, birthday;

    while([&](){//!   a lambda to read lastName and check if should quit

          std::cout << "last name:\n";
          std::cin >> lastName;

          return lastName != "@q";
}())
    {
        while([&](){//!   a lambda to read child name and birthday and check if should quit
              std::cout << "child's name:\n";
              std::cin  >> childName;
              std::cout << "his birthday:\n";
              std::cin  >> birthday;

              return childName != "@q" && birthday != "@q";
    }())
        {
            famlies_map[lastName].push_back({childName, birthday});
            //!        ^^^^^^^^^^           ^^^^^^^^^^^^^^^^^^^^^
            //!  use lastName as the key    create a pair using {}.
        }
    }

    //! print the content.
    for(const auto &e : famlies_map)
    {
        std::cout << e.first <<":\n";

        for (const auto &l : e.second)
        {
            std::cout << l.first << " "
                      << l.second << " ";
        }
    }

    return 0;
}
