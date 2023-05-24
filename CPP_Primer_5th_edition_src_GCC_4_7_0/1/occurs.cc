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

int main()
{
	// currVal is the number we're counting; we'll read new values into val
	int currVal = 0, val = 0;

	// read first number and ensure that we have data to process
	if (std::cin >> currVal) {        
		int cnt = 1;  // store the count for the current value we're processing
		while (std::cin >> val) { // read the remaining numbers 
			if (val == currVal)   // if the values are the same
				++cnt;            // add 1 to cnt 
			else { // otherwise, print the count for the previous value
				std::cout << currVal << " occurs " 
				          << cnt << " times" << std::endl;
				currVal = val;    // remember the new value
				cnt = 1;          // reset the counter
			}
		}  // while loop ends here
		// remember to print the count for the last value in the file
		std::cout << currVal << " occurs " 
		          << cnt << " times" << std::endl;
	} // outermost if statement ends here
	return 0;
}
