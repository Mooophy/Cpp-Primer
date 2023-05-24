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

#include <vector>
using std::vector;

// function that takes a reference to an int 
// and sets the given object to zero
// i is just another name for the object passed to reset
void reset(int &i)  
{
    i = 0;  // changes the value of the object to which i refers
}

// function that takes a pointer 
// and sets the pointed-to value to zero
void reset(int *ip)
{
    *ip = 0;  // changes the value of the object to which ip points
    ip = 0;   // changes the local copy of ip; the argument is unchanged
}

int main() 
{
	int j = 42;
	reset(j);  // j is passed by reference; the value in j is changed
	cout << "j = " << j  << endl;  // prints j = 0

	j = 42;    // restore the original value of j
	reset(&j);                     // changes j but not the address of j
	cout << "j = "  << j << endl;  // prints j = 0

	j = 42;    // restore the original value of j
	int *p = &j;
	reset(p); // changes object to which p points not the address in p
	cout << "j = "  << *p << endl;  // prints j = 0

    return 0;
}
