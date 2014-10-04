//! @Alan
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
    std::cout << pre_suffix("alan", "Mr.", "Jr.");

    return 0;
}


std::string
pre_suffix(const std::string &name, const std::string &pre, const std::string &su)
{
    std::string result(pre);
    result += " ";
    result += name;
    result += " ";
    result += su;
    return result;
}
