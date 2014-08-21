//! @Alan
//!
//! Exercise 11.22:
//! Given a map<string, vector<int>>, write the types used as an argument
//! and as the return value for the version of insert that inserts one element.
//!
//! the type used as an argument:
//  std::pair<std::string, std::vector<int>>
//! the type used as the return value:
//  std::pair<std::map<std::string, std::vector<int>>::iterator, bool>
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
    std::map<std::string, std::vector<int>> m;

    std::pair<std::string, std::vector<int>>    pair{"Alan",{1,2,3}};
//! ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//! the type used as an argument



    std::pair<std::map<std::string, std::vector<int>>::iterator, bool>  it;
//! ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//! the type used as the return value

    it = m.insert(pair);

    for(const auto &e : m)
    {
        std::cout << e.first <<":\n";
        for(const auto &l : e.second)
            std::cout << l << " ";
        std::cout << "\n";
    }




    return 0;
}
