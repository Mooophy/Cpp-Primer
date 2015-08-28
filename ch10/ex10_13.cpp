// @Yue Wang
//
// Exercise 10.13:
// The library defines an algorithm named partition that takes a predicate
// and partitions the container so that values for which the predicate is
// true appear in the first part and those for which the predicate is false
// appear in the second part. The algorithm returns an iterator just past
// the last element for which the predicate returned true. Write a function
// that takes a string and returns a bool indicating whether the string has
// five characters or more. Use that function to partition words. Print the
// elements that have five or more characters.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool predicate(const std::string &s) 
{ 
    return s.size() >= 5; 
}

int main()
{
    auto v = std::vector<std::string>{ "a", "as", "aasss", "aaaaassaa", "aaaaaabba", "aaa" };
    auto pivot = std::partition(v.begin(), v.end(), predicate);
    
    for (auto it = v.cbegin(); it != pivot; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}
