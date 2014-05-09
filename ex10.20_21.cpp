//! @Alan
//!
//! Exercise 10.20:
//! The library defines an algorithm named count_if. Like find_if, this function takes
//! a pair of iterators denoting an input range and a predicate that it applies to each
//! element in the given range. count_if returns a count of how often the predicate is
//! true. Use count_if to rewrite the portion of our program that counted how many words
//! are greater than length 6.
//!
//! Exercise 10.21:
//! Write a lambda that captures a local int variable and decrements that variable until
//! it reaches 0. Once the variable is 0 additional calls should no longer decrement the
//! variable. The lambda should return a bool that indicates whether the captured variable is 0.
//!

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//! Exercise 10.20
unsigned
bigerThan6(const std::vector<std::string> &vs);

int main()
{
    //! ex10.21
    std::size_t count = 3;

    for (unsigned i = 0; i != 9; ++i)

        std::cout << ([&](){
            count? --count : count;
            return count == 0;
        }())
                 << std::endl;

    return 0;
}

unsigned bigerThan6(const std::vector<std::string> &vs)
{
    return std::count_if(vs.begin(), vs.end(), [](const std::string &s)->bool
                                                 {return s.size() > 6;});
}




