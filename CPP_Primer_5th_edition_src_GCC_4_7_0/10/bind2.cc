/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/ 

#include <algorithm>
using std::for_each;

#include <functional>
using std::bind; using namespace std::placeholders;
using std::ref;

#include <iterator>
using std::istream_iterator;

#include <vector>
using std::vector;

#include <string>
using std::string; 

#include <iostream>
using std::cout; using std::cin; using std::endl;
using std::ostream; 

#include <fstream>
using std::ifstream; using std::ofstream; 

ostream &print(ostream &os, const string &s, char c)
{
	return os << s << c;
}

int main()
{
	string s;
	vector<string> words;
	while (cin >> s)
		words.push_back(s);

	for_each(words.begin(), words.end(), 
	         bind(print, ref(cout), _1, ' '));
	cout << endl;

	ofstream os("data/outFile1");
	for_each(words.begin(), words.end(), 
	         bind(print, ref(os), _1, ' '));
	os << endl;

	ifstream is("data/outFile1");
	istream_iterator<string> in(is), eof;
	for_each(in, eof, bind(print, ref(cout), _1, '\n'));
	cout << endl;

	return 0;
}
