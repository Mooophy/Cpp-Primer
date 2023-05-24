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
using std::copy; using std::sort; using std::unique_copy;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iterator>
using std::istream_iterator; using std::ostream_iterator;

#include <fstream>
using std::ofstream;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
    istream_iterator<int> int_it(cin); // reads ints from cin
    istream_iterator<int> int_eof;     // end iterator value
	vector<int> v(int_it, int_eof);    // initialize v by reading cin

    sort(v.begin(), v.end());
    ostream_iterator<int> out(cout, " "); // write ints to cout
    unique_copy(v.begin(), v.end(), out); // write unique elements to cout
    cout << endl;                         // write a newline after the output
	ofstream out_file("data/outFile2");   // writes int to named file
	ostream_iterator<int> out_iter(out_file, " ");
	copy(v.begin(), v.end(), out_iter); 
	out_file << endl;  // write a newline at end of the file
    return 0;
}
