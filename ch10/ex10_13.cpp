//! @Alan
//!
//! Exercise 10.13:
//! The library defines an algorithm named partition that takes a predicate
//! and partitions the container so that values for which the predicate is
//! true appear in the first part and those for which the predicate is false
//! appear in the second part. The algorithm returns an iterator just past
//! the last element for which the predicate returned true. Write a function
//! that takes a string and returns a bool indicating whether the string has
//! five characters or more. Use that function to partition words. Print the
//! elements that have five or more characters.
//!

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//! Predicate
inline
bool isLongerThan5(const std::string &s)
{
    return s.size() >= 5;
}

void partition_words(std::vector<std::string> &v)
{
    auto iter_longerLast = std::partition(v.begin(), v.end(), isLongerThan5);

    //! @note   the range to be printed not whole of the v, so can't use for range.
    for(auto it = v.begin(); it != iter_longerLast; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> v{"a","as","aasss","aaaaassaa","aaaaaabba","aaa"};
    partition_words(v);

    return 0;
}



