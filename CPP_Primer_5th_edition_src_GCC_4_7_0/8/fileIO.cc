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
using std::cerr; using std::cout; using std::endl;

#include <fstream>
using std::ifstream; 

#include <string>
using std::string;

#include <stdexcept>
using std::runtime_error;

void process(ifstream &is)
{
	string s;
	while (is >> s)
		cout << s << endl;
}

int main(int argc, char* argv[])
{
	// for each file passed to the program
	for (auto p = argv + 1; p != argv + argc; ++p) {
	    ifstream input(*p);   // create input and open the file
	    if (input) {          // if the file is ok, ``process'' this file
	        process(input);
		} else
	        cerr << "couldn't open: " + string(*p);
	} // input goes out of scope and is destroyed on each iteration
	
	auto p = argv + 1, end = argv + argc;
	
	ifstream input;           
	while (p != end) {        // for each file passed to the program
		input.open(*p);       // open the file, automatically clears the stream 
	    if (input) {          // if the file is ok, read and ``process'' the input
	        	process(input);
		} else
			cerr << "couldn't open: " + string(*p);
	    input.close();        // close file when we're done with it
	    ++p;                  // increment pointer to get next file
	}
}
