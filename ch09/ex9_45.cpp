#include<iterator>
using std::back_inserter;

#include<utility>
using std::move;

#include<algorithm>
using std::copy;

#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

//! Exercise 9.45
string::iterator
pre_suffix(string &s,
string::iterator p_beg, string::iterator p_end,
string::iterator s_beg, string::iterator s_end)
{
	string str(move(s));
	s.clear();
	move(p_beg, p_end, back_inserter(s));
	s += " ";
	move(str.begin(), str.end(), back_inserter(s));
	s += " ";
	move(s_beg, s_end, back_inserter(s));
	return s.begin();
}


int main()
{
	string s("alan"),pre("Mr."),su("Jr.");
	pre_suffix(s, pre.begin(), pre.end(), su.begin(), su.end());
	cout << s << endl;
	
    return 0;
}




	
