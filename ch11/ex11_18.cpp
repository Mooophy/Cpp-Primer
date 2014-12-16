//! @Alan
//!
//! Exercise 11.18:
//! Write the type of map_it from the loop on page 430 without using auto or decltype.
//!

#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<std::string, size_t> word_count;

    //! the orignal codes:
    //auto map_it = word_count.cbegin();


    std::map<std::string, size_t>::const_iterator map_it = word_count.cbegin();
//! ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//! the type ex11.18 required.

    // compare the current iterator to the off-the-end iterator
    while (map_it != word_count.cend())
    {
        // dereference the iterator to print the element key--value pairs
        std::cout << map_it->first << " occurs "
             << map_it->second << " times" << std::endl;
        ++map_it;  // increment the iterator to denote the next element
    }

    return 0;
}
