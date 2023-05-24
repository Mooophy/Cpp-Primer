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

#include "StrFolder.h"

#include "String.h"

int main()
{
	String s1("contents1");
	String s2("contents2");
	String s3("contents3");
	String s4("contents4");
	String s5("contents5");
	String s6("contents6");
	
	// all new messages, no copies yet
	Message m1(s1);
	Message m2(s2);
	Message m3(s3);
	Message m4(s4);
	Message m5(s5);
	Message m6(s6);

	Folder f1;
	Folder f2;

	m1.save(f1); m3.save(f1); m5.save(f1);
	m1.save(f2);
	m2.save(f2); m4.save(f2); m6.save(f2);
	
	m1.debug_print();
	f2.debug_print();

	// create some copies
	Message c1(m1);
	Message c2(m2), c4(m4), c6(m6);
	
	m1.debug_print();
	f2.debug_print();

	// now some assignments
	m2 = m3;
	m4 = m5;
	m6 = m3;
	m1 = m5;

	m1.debug_print();
	f2.debug_print();

	// finally, self-assignment
	m2 = m2;
	m1 = m1;

	m1.debug_print();
	f2.debug_print();

	vector<Message> vm;
	cout << "capacity: " << vm.capacity() << endl;
	vm.push_back(m1);

	cout << "capacity: " << vm.capacity() << endl;
	vm.push_back(m2);

	cout << "capacity: " << vm.capacity() << endl;
	vm.push_back(m3);

	cout << "capacity: " << vm.capacity() << endl;
	vm.push_back(m4);

	cout << "capacity: " << vm.capacity() << endl;
	vm.push_back(m5);

	cout << "capacity: " << vm.capacity() << endl;
	vm.push_back(m6);

	vector<Folder> vf;
	cout << "capacity: " << vf.capacity() << endl;
	vf.push_back(f1);

	cout << "capacity: " << vf.capacity() << endl;
	vf.push_back(f2);

	cout << "capacity: " << vf.capacity() << endl;
	vf.push_back(Folder(f1));

	cout << "capacity: " << vf.capacity() << endl;
	vf.push_back(Folder(f2));

	cout << "capacity: " << vf.capacity() << endl;
	vf.push_back(Folder());

	Folder f3;
	f3.save(m6);
	cout << "capacity: " << vf.capacity() << endl;
	vf.push_back(f3);


	return 0;
}
