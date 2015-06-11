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


//! Exercise 9.45
#include <iostream>
#include <string>
#include <iterator>
using namespace std;
/*
* Ex 9.45
* Date:2015.6.11
*use iterator
*/
string func(string &name, string const &prev, string const &su)
{
<<<<<<< HEAD

    string ret(name);
    ret.insert(ret.begin(), prev.begin(), prev.end());
=======
    std::string name("alan");
    std::cout << pre_suffix(name, "Mr.", ",Jr.") << std::endl;

    return 0;
}


inline std::string
pre_suffix(const std::string &name, const std::string &pre, const std::string &su)
{
    auto ret = name;
    ret.insert(ret.begin(), pre.begin(), pre.end());
>>>>>>> moon/master
    ret.append(su);

    return ret;
}
int main()
{
    string s= {"Jack"};
    cout << func(s, "Mr.", " III") << endl;
    return 0;
}
