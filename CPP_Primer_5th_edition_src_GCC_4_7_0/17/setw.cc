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
using std::cout; using std::endl; 
using std::left; using std::right; using std::internal;

#include <iomanip>
using std::setw; using std::setfill;

int main()
{
	int i = -16;
	double d = 3.14159;
	
	// pad the first column to use a minimum of 12 positions in the output
	cout << "i: " << setw(12) << i << "next col" << '\n'
	     << "d: " << setw(12) << d << "next col" << '\n';
	
	// pad the first column and left-justify all columns
	cout << left 
	     << "i: " << setw(12) << i << "next col" << '\n'
	     << "d: " << setw(12) << d << "next col" << '\n'
	     << right;           // restore normal justification
	
	// pad the first column and right-justify all columns
	cout << right
	     << "i: " << setw(12) << i << "next col" << '\n'
	     << "d: " << setw(12) << d << "next col" << '\n';
	
	// pad the first column but put the padding internal to the field
	cout << internal
	     << "i: " << setw(12) << i << "next col" << '\n'
	     << "d: " << setw(12) << d << "next col" << '\n';
	
	// pad the first column, using # as the pad character
	cout << setfill('#')
	     << "i: " << setw(12) << i << "next col" << '\n'
	     << "d: " << setw(12) << d << "next col" << '\n'
	     << setfill(' ');   // restore the normal pad character

	return 0;
}
