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
#include <string>
#include "Sales_data.h"

int main()
{
	Sales_data data1, data2;

	// code to read into data1 and data2
	double price = 0;  // price per book, used to calculate total revenue

	// read the first transactions: ISBN, number of books sold, price per book
	std::cin >> data1.bookNo >> data1.units_sold >> price;
	// calculate total revenue from price and units_sold
	data1.revenue = data1.units_sold * price;

	// read the second transaction
	std::cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;

	// code to check whether data1 and data2 have the same ISBN
	//        and if so print the sum of data1 and data2
	if (data1.bookNo == data2.bookNo) {
		unsigned totalCnt = data1.units_sold + data2.units_sold;
		double totalRevenue = data1.revenue + data2.revenue;

		// print: ISBN, total sold, total revenue, average price per book
		std::cout << data1.bookNo << " " << totalCnt 
		          << " " << totalRevenue << " ";
		if (totalCnt != 0)
			std::cout << totalRevenue/totalCnt << std::endl;
		else
			std::cout  << "(no sales)" << std::endl;

		return 0;  // indicate success
	} else {  // transactions weren't for the same ISBN
		std::cerr << "Data must refer to the same ISBN" 
		          << std::endl;
		return -1; // indicate failure
	}
}
