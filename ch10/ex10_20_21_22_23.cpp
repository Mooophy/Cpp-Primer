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
//! Exercise 10.22:
//! Rewrite the program to count words of size 6 or less using functions in place of the lambdas.
//!
//! Exercise 10.23:
//! How many arguments does bind take?
//  Assuming the function to be bound have n parameters, bind take n + 1 parameters. The addtional
//  one is for the funcion to be bound itself.
//!


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

//! Exercise 10.20
unsigned
bigerThan6(const std::vector<std::string> &vs);

//! Exercise 10.21
void ex10_21(int i);

//! Exercise 10.22
unsigned
bigerThan6_withFunction(const std::vector<std::string> &vs);
inline bool
predicate_biggerThan6(const std::string &s,const std::vector<std::string>::size_type sz);



int main()
{

    std::vector<std::string> v = {"aa","aaaaaaaaaaaa","aaaaaaaaaaaa","aaaaaaaaaaaa"};

    //! @test for Exercise 10.20
    //std::cout << bigerThan6(v);

    //! @test for Exercise 10.22
    std::cout << bigerThan6_withFunction(v);

    return 0;
}


unsigned bigerThan6(const std::vector<std::string> &vs)
{
    return std::count_if(vs.begin(), vs.end(), [](const std::string &s)->bool
                                                 {return s.size() > 6;});
}


void ex10_21(int i)
{
    auto l =  [&]()
    {
        i? --i : i;
        return i == 0;
    };
}

//! Exercise 10.22
unsigned
bigerThan6_withFunction(const std::vector<std::string> &vs)
{
    return std::count_if(vs.begin(), vs.end(), std::bind(predicate_biggerThan6, std::placeholders::_1, 6));
}
inline bool
predicate_biggerThan6(const std::string &s, const std::vector<std::string>::size_type sz)
{
    return s.size() > sz;
}
