//! @Alan
//!
//! Exercise 11.17:
//! Assuming c is a multiset of strings and v is a vector of strings,
//! explain the following calls. Indicate whether each call is legal:
//!
//! works:
//  copy(v.begin(), v.end(), inserter(c, c.end()));
//! multiset has no push_back() member ,so it doesn't work:
//  copy(v.begin(), v.end(), back_inserter(c));
//! works:
//  copy(c.begin(), c.end(), inserter(v, v.end()));
//! works:
//  copy(c.begin(), c.end(), back_inserter(v));
//!


#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <iterator>


int main()
{
    std::multiset<std::string> c = {"aa","bb","cc"};
    std::vector<std::string> v = {"xx","yy","zz"};

    std::copy(c.begin(), c.end(), back_inserter(v));

    return 0;
}
