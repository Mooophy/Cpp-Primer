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

#include <cstring>

#include <cstddef>
using std::size_t;

int main() {
	string s1 = "A string example";
	string s2 = "A different string";
	
	if (s1 < s2)  // false: s2 is less than s1
		cout << s1 << endl;
	else
		cout << s2 << endl;
	const char ca1[] = "A string example";
	const char ca2[] = "A different string";
	
	if (strcmp(ca1, ca2) < 0) // same effect as string comparison s1 < s2
		cout << ca1 << endl;
	else
		cout << ca2 << endl;
	
	const char *cp1 = ca1, *cp2 = ca2;
	cout << strcmp(cp1, cp2) << endl; // output is positive
	cout << strcmp(cp2, cp1) << endl; // output is negative
	cout << strcmp(cp1, cp1) << endl; // output is zero
	
	
	cout << strlen(cp1) << endl; // prints 16; strlen ignores the null
	
	const unsigned sz = 16 + 18 + 2;
	char largeStr[sz];      // will hold the result
	// disastrous if we miscalculated the size of largeStr
	strcpy(largeStr, ca1);  // copies ca1 into largeStr
	strcat(largeStr, " ");  // adds a space at the end of largeStr
	strcat(largeStr, ca2);  // concatenates ca2 onto largeStr
	// prints A string example A different string
	cout << largeStr << endl;       
	
	strncpy(largeStr, ca1, sz); // size to copy includes the null
	if (strlen(ca1) > sz)
		largeStr[sz-1] = '\0';
	strncat(largeStr, " ", 2);  // pedantic, but a good habit
	strncat(largeStr, ca2, sz - strlen(largeStr)); 
	cout << largeStr << endl;       
	
	// initialize large_string as a concatenation of s1, a space, and s2
	string large_string = s1 + " " + s2; 
	cout << large_string << endl;       
	
	return 0;
}
