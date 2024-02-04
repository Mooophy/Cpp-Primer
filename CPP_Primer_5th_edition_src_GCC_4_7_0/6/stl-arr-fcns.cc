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
using std::endl; using std::cout;

#include <iterator>
using std::begin; using std::end;

// prints a null-terminated array of characters
void print(const char *cp)
{
	if (cp)          // if cp is not a null pointer
		while (*cp)  // so long as the character it points to is not a null character
			cout << *cp++;  // print the character and advance the pointer
}

// print ints in the given range
void print(const int *beg, const int *end) 
{
	// print every element starting at beg up to but not including end
    while (beg != end) 
        cout << *beg++ << " "; // print the current element 
		                       // and advance the pointer
}

int main() 
{
	print("hi world!"); // calls first version of print
	cout << endl;

    // j is converted to a pointer to the first element in j
    // the second argument is a pointer to one past the end of j
    int j[2] = {0, 1};  
    print(begin(j), end(j));  // library begin and end functions
	cout << endl;

	// equivalent call, directly calculate the begin and end pointers
	print(j, j + 2); 
	cout << endl;

    return 0;
}
