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
using std::cin; using std::cout; using std::cerr;
using std::istream; using std::ostream; using std::endl;

#include <sstream>
using std::ostringstream; using std::istringstream;

#include <vector>
using std::vector;

#include <string>
using std::string;

// members are public by default
struct PersonInfo { 
	string name;
	vector<string> phones;
};

// we'll see how to reformat phone numbers in chapter 17
// for now just return the string we're given
string format(const string &s) { return s; }

bool valid(const string &s)
{
	// we'll see how to validate phone numbers 
	// in chapter 17, for now just return true
	return true;
}

vector<PersonInfo>
getData(istream &is)
{
	// will hold a line and word from input, respectively
	string line, word;

	// will hold all the records from the input
	vector<PersonInfo> people;

	// read the input a line at a time until end-of-file (or other error)
	while (getline(is, line)) {       
		PersonInfo info;            // object to hold this record's data
	    istringstream record(line); // bind record to the line we just read
		record >> info.name;        // read the name
	    while (record >> word)      // read the phone numbers 
			info.phones.push_back(word);  // and store them
		people.push_back(info); // append this record to people
	}
	
	return people;
}

ostream& process(ostream &os, vector<PersonInfo> people)
{
	for (const auto &entry : people) {    // for each entry in people
		ostringstream formatted, badNums; // objects created on each loop
		for (const auto &nums : entry.phones) {  // for each number 
			if (!valid(nums)) {           
				badNums << " " << nums;  // string in badNums
			} else                        
				// ``writes'' to formatted's string
				formatted << " " << format(nums); 
		}
		if (badNums.str().empty())      // there were no bad numbers
			os << entry.name << " "     // print the name 
			   << formatted.str() << endl; // and reformatted numbers 
		else                   // otherwise, print the name and bad numbers
			cerr << "input error: " << entry.name 
			     << " invalid number(s) " << badNums.str() << endl;
	}
	
	return os;
}

int main()
{
	process(cout, getData(cin));

	return 0;
}
