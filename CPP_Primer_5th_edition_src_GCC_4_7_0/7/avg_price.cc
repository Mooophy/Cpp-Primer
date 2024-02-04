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
using std::cerr; using std::cin; using std::cout; using std::endl;

#include "Sales_data.h"

int main()
{
	Sales_data total;         // variable to hold the running sum
	if (read(cin, total))  {  // read the first transaction
		Sales_data trans;     // variable to hold data for the next transaction
		while(read(cin, trans)) {      // read the remaining transactions
			if (total.isbn() == trans.isbn())   // check the isbns
				total.combine(trans);  // update the running total
			else {
				print(cout, total) << endl;  // print the results
				total = trans;               // process the next book
			}
		}
		print(cout, total) << endl;          // print the last transaction
	} else {                                 // there was no input
		cerr << "No data?!" << endl;         // notify the user
	}

	return 0;
}
