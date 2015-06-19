//!
//! @author @Yue Wang @shbling @Soyn @Yue Wang
//!
//! Exercise 10.24:
//! Use bind and check_size to find the first element in a vector of ints that has a value greater
//! than the length of a specified string value.
//!
//  Discussion over this exercise on StackOverflow
//  http://stackoverflow.com/questions/20539406/what-type-does-stdfind-if-not-return
//!

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::find_if;
using std::bind;

inline auto check_size(string const& s, string::size_type sz) -> bool
{
    return s.size() < sz;
}

inline auto find_first_greater(vector<int> const& v, string const& s) -> vector<int>::const_iterator
{
    auto lambda = [&](int i){ return i >= 0 && bind(check_size, s, i)(); };
    return find_if(v.cbegin(), v.cend(), lambda);
}

int main()
{
    vector<int> v{ -1, -2, 3, 4, 5, 6, 7 };
    string s("test");
    cout << *find_first_greater(v, s) << endl;

    return 0;
}
//! output:
//!
//5
