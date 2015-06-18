//!
//! @author @Yue Wang @shbling @Soyn
//!
//! Exercise 10.24:
//! Use bind and check_size to find the first element in a vector of ints that has a value greater
//! than the length of a specified string value.
//!
//  Discussion over this exercise on StackOverflow
//  http://stackoverflow.com/questions/20539406/what-type-does-stdfind-if-not-return
//!

#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
using namespace std;
using namespace std :: placeholders;

bool check_size(const string &s, int sz)
{
    return int(s.size()) < sz;
}

inline vector<int> :: const_iterator
find_first_bigger(const vector<int> &v, const string&s)
{
    return find_if(v.cbegin(), v.cend(), bind(check_size, s, _1));
}
int main()
{
    vector<int> ivec = {1,2,3,4,5,6,7};
    string s("test");
    cout << *find_first_bigger(ivec,s) << endl;
    return 0;
}
//! output;
//!
//5
