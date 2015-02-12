//
//  ex9_32.cpp
//  Exercise 9.32 
//
//  Created by pezy on 12/3/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Assuming vi is a container of ints that includes even and odd values, 
//          predict the behavior of the following loop. 
//          After you've analyzed this loop, write a program to test whether your expectations were correct.
//			
//			iter = vi.begin(); 
//			while (iter != vi.end())    
//				if (*iter % 2)        
//					iter = vi.insert(iter, *iter);    
//				++iter; 
//
//  @Answer "infinite loop". Casue the `++iter` out of the `while` loop. But even through add brackets it is still infinite loop.
//          Fixed following.

#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

int main()
{
	vector<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto iter = vi.begin();
	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert(iter, *iter);
			++iter;
		}
		++iter;
	}

	for (auto i : vi)
		cout << i << " ";

	return 0;
}

