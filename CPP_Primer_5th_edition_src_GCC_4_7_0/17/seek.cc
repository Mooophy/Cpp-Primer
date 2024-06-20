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
using std::cerr; using std::endl;

#include <fstream>
using std::fstream;

#include <string>
using std::string;

#include <cstdlib> // for EXIT_FAILURE

int main()
{
    // open for input and output and preposition file pointers to end-of-file
	// file mode argument 
    fstream inOut("data/copyOut", 
                   fstream::ate | fstream::in | fstream::out);
    if (!inOut) {
        cerr << "Unable to open file!" << endl;
        return EXIT_FAILURE; // EXIT_FAILURE 
    } 

    // inOut is opened in ate mode, so it starts out positioned at the end
    auto end_mark = inOut.tellg();// remember original end-of-file position
    inOut.seekg(0, fstream::beg); // reposition to the start of the file
    size_t cnt = 0;               // accumulator for the byte count
    string line;                  // hold each line of input

    // while we haven't hit an error and are still reading the original data 
    while (inOut && inOut.tellg() != end_mark
           && getline(inOut, line)) { // and can get another line of input
        cnt += line.size() + 1;       // add 1 to account for the newline
		auto mark = inOut.tellg();    // remember the read position
        inOut.seekp(0, fstream::end); // set the write marker to the end
        inOut << cnt;                 // write the accumulated length
        // print a separator if this is not the last line
        if (mark != end_mark) inOut << " "; 
        inOut.seekg(mark);            // restore the read position
    }
    inOut.seekp(0, fstream::end);     // seek to the end
    inOut << "\n";                    // write a newline at end-of-file

    return 0;
}
