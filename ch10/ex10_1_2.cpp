//! @Alan
//!
//! Exercise 10.1:
//! The algorithm header defines a function named count that, like find,
//! takes a pair of iterators and a value.count returns a count of how
//! often that value appears.
//! Read a sequence of ints into a vector and print the count of how many
//! elements have a given value.
//!
//! Exercise 10.2:
//! Repeat the previous program, but read values into a list of strings.
//!

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//! Exercise 10.1
int
count_of_int(const std::vector<int> &v, const int &i);

//! Exercise 10.2
int
count_of_string(std::vector< std::string> &v, const std::string &s);

int main()
{
    //! Exercise 10.1
    std::vector<int> v={1,2,3,4,5,6,6,6,2};
    std::cout << count_of_int(v,2);

    //! Exercise 10.2
    std::vector<std::string> vs = {"aa","aa","aa","cc"};
    std::cout << count_of_string(vs,"aa");

    return 0;
}

//! Exercise 10.1
int
count_of_int(const std::vector<int> &v, const int &i)
{
    return std::count(v.begin(),v.end(), i);
}


int count_of_string(std::vector<std::string> &v, const std::string &s)
{
    return std::count(v.begin(), v.end(), s);
}
