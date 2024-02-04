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

#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>

using std::map; using std::string; using std::vector;
using std::ifstream; using std::cout; using std::endl;
using std::getline; 
using std::runtime_error; using std::istringstream;

map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> trans_map;   // holds the transformations
    string key;    // a word to transform
	string value;  // phrase to use instead
	// read the first word into key and the rest of the line into value
	while (map_file >> key && getline(map_file, value))
		if (value.size() > 1) // check that there is a transformation
        	trans_map[key] = value.substr(1); // skip leading space 
		else
			throw runtime_error("no rule for " + key);
	return trans_map;
}

const string &
transform(const string &s, const map<string, string> &m)
{
	// the actual map work; this part is the heart of the program
	auto map_it = m.find(s);
	// if this word is in the transformation map
	if (map_it != m.cend()) 
		return map_it->second; // use the replacement word
	else
		return s;              // otherwise return the original unchanged
}

// first argument is the transformations file; 
// second is file to transform
void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = buildMap(map_file); // store the transformations

	// for debugging purposes print the map after its built
    cout << "Here is our transformation map: \n\n";
	for (auto entry : trans_map)
        cout << "key: "   << entry.first
             << "\tvalue: " << entry.second << endl;
    cout << "\n\n";

	// do the transformation of the given text 
    string text;                    // hold each line from the input
    while (getline(input, text)) {  // read a line of input
        istringstream stream(text); // read each word 
        string word;
        bool firstword = true;      // controls whether a space is printed 
        while (stream >> word) {
           if (firstword)
               firstword = false;
           else
               cout << " ";  // print a space between words
           // transform returns its first argument or its transformation 
           cout << transform(word, trans_map); // print the output 
        }
        cout << endl;        // done with this line of input
    }
}

int main(int argc, char **argv)
{
	// open and check both files
    if (argc != 3)
        throw runtime_error("wrong number of arguments");

    ifstream map_file(argv[1]); // open transformation file 
    if (!map_file)              // check that open succeeded
        throw runtime_error("no transformation file");
    
    ifstream input(argv[2]);    // open file of text to transform
    if (!input)                 // check that open succeeded
        throw runtime_error("no input file");

	word_transform(map_file, input);

    return 0;  // exiting main will automatically close the files
}
