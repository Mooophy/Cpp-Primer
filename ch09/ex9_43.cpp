//
//  ex9_43.cpp
//  Exercise 9.43
//
//  Created by XDXX on 4/16/2015.
//  Copyright (c) 2015 XDXX. All rights reserved.
//
//  @Brief  Write a function that takes three strings, s, oldVal, and newVal.
//          Using iterators, and the insert and erase functions replace
//          all instances of oldVal that appear in s by newVal.
//	    Test your function by using it to replace common abbreviations,
//          such as “tho” by “though” and “thru” by “through”.
//  @notice This program doesn't compile on GCC because GCC(4.9.2) doesn't 
//	    support the feature of c++11 which the
//          insert(iterator p, InputIterator first, InputIterator last) function
//	    could return an iterator.So please use VS(2012+) or clang instead.

#include <iterator>
#include <iostream>
#include <string>

using std::cout; using std::endl; using std::string;

void func(string &s, const string &oldVal, const string &newVal)
{
	for (auto iter = s.begin(); iter != s.end();)
	{
		if (s.end() - iter < oldVal.size())
			break;
		if (*iter == oldVal[0])
		{
			string substring{ iter, iter + oldVal.size() };
			if (oldVal == substring)
			{
				iter = s.erase(iter, iter + oldVal.size());
				iter = s.insert(iter, newVal.begin(), newVal.end());
				iter += newVal.size();
			}
			else
				++iter;
		}
		else
			++iter;
	}
}

int main() 
{
	string s{ "To drive straight thru is a foolish, tho courageous act." };
	func(s, "tho", "though");
	func(s, "thru", "through");
	cout << s << endl;

	return 0;
}
