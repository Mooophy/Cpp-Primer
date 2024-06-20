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

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <cstddef>
using std::size_t;

// returns the index of the first occurrence of c in s
// the reference parameter occurs counts how often c occurs
string::size_type find_char(const string &s, char c, 
                           string::size_type &occurs)
{
    auto ret = s.size();   // position of the first occurrence, if any
    occurs = 0;            // set the occurrence count parameter 

    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size()) 
                ret = i;   // remember the first occurrence of c
            ++occurs;      // increment the occurrence count
         }
	}
    return ret;            // count is returned implicitly in occurs
}

// returns an iterator that refers to the first occurrence of value
// the reference parameter occurs contains a second return value
vector<int>::const_iterator find_val(
    vector<int>::const_iterator beg,  // first element
    vector<int>::const_iterator end,  // one past last element
    int value,                        // the value we want
    vector<int>::size_type &occurs)   // number of times it occurs
{
    auto res_iter = end; // res_iter will hold first occurrence, if any
    occurs = 0;          // set occurrence count parameter 

    for ( ; beg != end; ++beg)
        if (*beg == value) {
            // remember first occurrence of value
            if (res_iter == end) 
                res_iter = beg;
            ++occurs;    // increment occurrence count
         }

    return res_iter;     // count returned implicitly in occurs
}

int main() 
{
	
	string s;
	getline(cin, s); 
	size_t ctr = 0;
	auto index = find_char(s, 'o', ctr);
	cout << index << " " << ctr << endl;
	
	vector<int> ivec;
	int i;
	// read values into ivec
	while (cin >> i)
		ivec.push_back(i);

	// for each value in the list of ints
	for (auto i : {42, 33, 92}) {
		auto it = find_val(ivec.begin(), ivec.end(), i, ctr);
		if (it == ivec.end())
			cout << i << " is not in the input data" << endl;
		else
			cout << i << " was at position " 
			     << it - ivec.begin() << endl;
	}

	return 0;
}
