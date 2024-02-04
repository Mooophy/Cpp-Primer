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

#include "compare.h"
#include "Blob.h"

#include <string>
using std::string;

// Application.cc
// these template types must be instantiated elsewhere in the program
// instantion declaration and definition
extern template class Blob<string>;  
extern template int compare(const int&, const int&);

int main() {

	Blob<string> sa1, sa2; // instantiation will appear elsewhere

	// Blob<int> and its initializer_list constructor 
	// are instantiated in this file
	Blob<int> a1 = {0,1,2,3,4,5,6,7,8,9}; 
	Blob<int> a2(a1);  // copy constructor instantiated in this file

	int i = compare(a1[0], a2[0]); // instantiation will appear elsewhere

	return 0;
}
