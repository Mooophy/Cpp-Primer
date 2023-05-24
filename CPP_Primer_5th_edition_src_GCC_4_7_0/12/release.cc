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

#include <string>
using std::string;

#include <memory>
using std::unique_ptr;

#include <iostream>
using std::cout; using std::endl;

int main()
{
	unique_ptr<string> p1(new string("Stegosaurus"));
	
	// transfers ownership from p1 
	// (which points to the string Stegosaurus) to p2
	unique_ptr<string> p2(p1.release()); // release makes p1 null
	cout << *p2 << endl; // prints Stegosaurus
	
	unique_ptr<string> p3(new string("Trex"));

	// reset deletes the memory to which p2 had pointed
	// and transfers ownership from p3 to p2 
	p2.reset(p3.release()); 
	cout << *p2 << endl; // prints Trex
	
	// p1 is null, p2 is steg, and p3 is trex
	if (p1)
		cout << "p1 not null?" << endl;
	if (p3)
		cout << "p2 not null?" << endl;
	cout << *p2 << endl;
}
