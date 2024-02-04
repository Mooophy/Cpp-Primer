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
using std::sort; using std::for_each;

#include <functional>
using std::bind; 
using namespace std::placeholders;

#include <string>
using std::string;

#include <vector>
using std::vector; 

#include <iostream>
using std::cin; using std::cout; using std::endl; 

// comparison function to be used to sort by word length
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

bool LT(const string &s1, const string &s2)
{
	return s1 < s2;
}

void print(const vector<string> &words)
{
	for_each(words.begin(), words.end(),
	        [](const string &s) { cout << s << " "; });
	cout << endl;
}

int main()
{
    vector<string> words;

    // copy contents of each book into a single vector
    string next_word;
    while (cin >> next_word) {
        // insert next book's contents at end of words
        words.push_back(next_word);
    }
	print(words);

	vector<string> cpy = words; // save the original data

	// uses string < to compare elements
	// sort and print the vector
	sort(words.begin(), words.end());

	words = cpy;  // return to the original data
	// uses the LT function to compare elements
	// should have the same output as the previous sort
	sort(words.begin(), words.end(), LT);
    print(words);

	words = cpy;  // return to the original data

	// eliminate duplicates
	sort(words.begin(), words.end());
	auto it = unique(words.begin(), words.end());
	words.erase(it, words.end());

	// sort by length using a function
	stable_sort(words.begin(), words.end(), isShorter);  
    print(words);

	words = cpy; // return to the original data
	// sort the original input on word length, shortest to longest
	sort(words.begin(), words.end(), isShorter);  
    print(words);

	// use bind to invert isShorter to sort longest to shortest
	sort(words.begin(), words.end(), bind(isShorter, _2, _1));  
    print(words);

	return 0;
}
