//! @Alan
//! Exercise 11.15:
//! What are the mapped_type, key_type, and value_type of a map from int to vector<int>?
//  mapped_type :   std::vector<int>
//  key_value   :   int
//  value_type  :   std::pair<const int, vector<int>>
//!
//! Exercise 11.16:
//! Using a map iterator write an expression that assigns a value to an element.
//!



#include <iostream>
#include <map>
#include <string>
#include <algorithm>




int main()
{
    //! ex 11.16
    std::map<int, std::string> m;
    m[25] = "Alan";
    std::map<int, std::string>::iterator it = m.begin();

    it->second = "Wang";
    std::cout << it->second;



    return 0;
}
