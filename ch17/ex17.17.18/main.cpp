/***************************************************************************
*  @file       main.cpp
*  @author     Queequeg
*  @date       25  Nov 2014
*  @remark     This code is for the exercises from C++ Primer 5th Edition
*  @note
***************************************************************************/
//!
//! Exercise 17.17
//! Update your program so that it finds all the words in an input sequence
//! that violiate the ¡°ei¡± grammar rule.

//!
//! Exercise 17.18
//! Revise your program to ignore words that contain ¡°ei¡± but are not 
//! misspellings, such as ¡°albeit¡± and ¡°neighbor.¡±

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include<string>
using std::string;

#include <regex>
using std::regex;
using std::sregex_iterator;

int main()
{
	string s;
	cout << "Please input a sequence of words:" << endl;
	getline(cin, s);
	cout << endl;
	cout << "Word(s) that violiate the ¡°ei¡± grammar rule:" << endl;
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern, regex::icase);
	for (sregex_iterator it(s.begin(), s.end(), r), end_it;
		it != end_it; ++it)
		cout << it->str() << endl;

	return 0;
}