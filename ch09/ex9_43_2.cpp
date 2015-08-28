//
//  ex9_43_2.cpp
//  Exercise 9.43
//
//  Created by pezy on 4/17/2015.
//
//  @Brief  Write a function that takes three strings, s, oldVal, and newVal.
//          Using iterators, and the insert and erase functions replace
//          all instances of oldVal that appear in s by newVal.
//	    Test your function by using it to replace common abbreviations,
//          such as “tho” by “though” and “thru” by “through”.
//  @notice This program could compiled with GCC well.But it doesn't use some c++11
//          features.There is another version(ex9_43_1.cpp) of this exercise which
//          using c++11 features.

#include <iterator>
#include <iostream>
#include <string>
#include <cstddef>

using std::cout; using std::endl; using std::string;

void func(string &s, string const& oldVal, string const& newVal)
{
    for (auto iter = s.begin(); std::distance(iter, s.end()) >= static_cast<ptrdiff_t>(oldVal.size()); )
        if (*iter == oldVal[0] && string(iter, std::next(iter, oldVal.size())) == oldVal) {
            iter = s.erase(iter, std::next(iter, oldVal.size()));
            size_t pos = std::distance(s.begin(), iter) + newVal.size();
            s.insert(iter, newVal.begin(), newVal.end());
            iter = std::next(s.begin(), pos);
        } else  ++iter;
}

int main() 
{
	string s{ "To drive straight thru is a foolish, tho courageous act." };
	func(s, "tho", "though");
	func(s, "thru", "through");
	cout << s << endl;

	return 0;
}
