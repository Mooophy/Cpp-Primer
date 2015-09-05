/***************************************************************************
*  @file       main.cpp
*  @author     Queequeg
*  @date       26  Nov 2014
*  @remark     This code is for the exercises from C++ Primer 5th Edition
*  @note
***************************************************************************/
//
// Exercise 17.21
// Rewrite your phone number program from 8.3.2 (p. 323) to use the 
// valid function defined in this section.

#include <iostream>
using std::cerr;
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <sstream>
using std::istringstream;
using std::ostringstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <regex>
using std::regex;
using std::sregex_iterator;
using std::regex_error;

int main() {
	try {
		regex reg("(\\d{ 4 })?([-])?(\\d{ 5 })");
		string str;
		while (getline(cin, str)) {
			for (sregex_iterator b(str.cbegin(), str.cend(), reg), e; b != e; ++b) {
				if (!(*b)[1].matched) // if if there is only the last 5 digits of index
					cout << b->str(3);  // show them
				else
					cout << b->str();   // show index entirely
				cout << '\t';
			}
		}
	}

	catch (regex_error re) {
		cout << re.what() << endl << re.code() << endl;
	}

	return 0;
}
