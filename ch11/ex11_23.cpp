//
//  ex11_23.cpp
//  Exercise 11.23
//
//  Created by pezy on 12/16/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Rewrite the map that stored vectors of children’s names with a key that is the family last name for the exercises in 11.2.1 (p. 424) to use a multimap.

#include <map>
#include <string>
#include <vector>
#include <iostream>

int main()
{
	using namespace::std;
	multimap<string, vector<string>> families;
	string name, cname;
	while ([&]->bool
	{
		cout << "enter name:\n";
		cin >> name;
		return name != "@quit";
	}())
	{
		int count = 1;
		while ([&]->bool
		{
			cout << "Hi," << name << ", enter your " << count << "th child's name" << endl;
			cin >> cname;
			++count;
			return cname != "@end";
		}())
		{
			families.insert({ name, { cname } });
		}
	}
	for (auto f : families)
	{
		cout << f.first << " : ";
		for (auto s :f.second)
		{
			cout << s<< ends;
		}
		cout << endl;
	}
	return 0;
}

