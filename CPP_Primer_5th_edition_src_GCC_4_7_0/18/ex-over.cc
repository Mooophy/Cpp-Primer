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

namespace primerLib {
    void compute() { cout << "primerLib::compute()" << endl; }
    void compute(const void *) 
	   { cout << "primerLib::compute(const void *)" << endl; }
}

// brings comput() and compute(const void*) into scope
using primerLib::compute;

void compute(int) { cout << "compute(int)" << endl; }
void compute(double, double = 3.4)
	   { cout << "compute(double, double)" << endl; }
void compute(char*, char* = 0)
         { cout << "compute(char*, char*)" << endl; }

int main()
{
	int i = 42;
	char c = 'a';
	compute(i);  // compute(int)
	compute(c);  // compute(int)
	compute(&i); // primerLib::compute(const void*)
	compute(&c); // compute(char*, char*)
	compute(3.4);// compute(double, double)
	
	return 0;
}
