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

#include <string>
using std::string;

#include "Screen.h"

int main()
{
	Screen myScreen(5,3);
	// move the cursor to a given position, and set that character 
	myScreen.move(4,0).set('#');

	Screen nextScreen(5, 5, 'X');
	nextScreen.move(4,0).set('#').display(cout);
	cout << "\n";
	nextScreen.display(cout);
	cout << endl;

	const Screen blank(5, 3);
	myScreen.set('#').display(cout);  // calls nonconst version
	cout << endl;
	blank.display(cout);              // calls const version
	cout << endl;

	myScreen.clear('Z').display(cout); cout << endl;
	myScreen.move(4,0);
	myScreen.set('#');
	myScreen.display(cout); cout << endl;
	myScreen.clear('Z').display(cout); cout << endl;

	// if move returns Screen not Screen&
	Screen temp = myScreen.move(4,0); // the return value would be copied
	temp.set('#'); // the contents inside myScreen would be unchanged
	myScreen.display(cout);
	cout << endl;
}
