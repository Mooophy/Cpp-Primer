//
//  ex9_43.cpp
//  Exercise 9.43
//
//  Created by XDXX on 4/17/2015.
//
//  @Brief  Write a function that takes three strings, s, oldVal, and newVal.
//          Using iterators, and the insert and erase functions replace
//          all instances of oldVal that appear in s by newVal.
//	        Test your function by using it to replace common abbreviations,
//          such as “tho” by “though” and “thru” by “through”.
//
//  @note   This code doesn't compile on GCC. Please use Visual Studio 2015+ or Clang 3.6+ 
//  
//  Refactored by Yue Wang Oct, 2015 
//

#include <iterator>
#include <iostream>
#include <string>
#include <cstddef>

using std::cout; 
using std::endl; 
using std::string;

auto replace_with(string &s, string const& oldVal, string const& newVal)
{
    for (auto cur = s.begin(); cur <= s.end() - oldVal.size(); )
        if (oldVal == string{ cur, cur + oldVal.size() })
            cur = s.erase(cur, cur + oldVal.size()),
            cur = s.insert(cur, newVal.begin(), newVal.end()),
            cur += newVal.size();
        else  
            ++cur;
}

int main()
{
    string s{ "To drive straight thru is a foolish, tho courageous act." };
    replace_with(s, "tho", "though");
    replace_with(s, "thru", "through");
    cout << s << endl;

    return 0;
}
