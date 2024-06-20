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

#include <iostream>
using std::cout; using std::endl;

int main() 
{
	string numbers("0123456789"), name("r2d2");
	// returns 1, i.e., the index of the first digit in name
	auto pos = name.find_first_of(numbers);  
	if (pos != string::npos)
		cout << "found number at index: " << pos 
		     << " element is " << name[pos] << endl;
	else
		cout << "no number in: " << name << endl;
	
	pos = 0;  
	// each iteration finds the next number in name
	while ((pos = name.find_first_of(numbers, pos)) 
	              != string::npos) {
	    cout << "found number at index: " << pos 
	         << " element is " << name[pos] << endl;
	
	    ++pos; // move to the next character
	}
	
	string river("Mississippi");
	
	auto first_pos = river.find("is");  // returns 1
	auto last_pos = river.rfind("is");  // returns 4
	cout << "find returned: " << first_pos 
	     << " rfind returned: " << last_pos << endl;
	
	string dept("03714p3");
	// returns 5, which is the index to the character 'p'
	pos = dept.find_first_not_of(numbers);
	cout << "first_not returned: " << pos << endl;
	
	return 0;
}
