//! @author @TungWah @Alan
//! @date   4 Oct,2014.
//!
//! Exercise 9.45:
//! Write a funtion that takes a string representing a name and two other
//! strings representing a prefix, such as “Mr.” or “Ms.” and a suffix,
//! such as “Jr.” or “III”. Using iterators and the insert and append functions,
//! generate and return a new string with the suffix and prefix added to the
//! given name.
//!

#include <iostream>
#include <string>

//! Exercise 9.45
std::string
pre_suffix(const std::string &name, const std::string &pre, const std::string &su);

int main()
{
    std::string name("alan");
    std::cout << pre_suffix(name, "Mr.", ",Jr.");

    return 0;
}


inline std::string
pre_suffix(const std::string &name, const std::string &pre, const std::string &su)
{
    std::string ret(name);
    ret.insert(0, pre);
    ret.append(su);

    return ret;
}
