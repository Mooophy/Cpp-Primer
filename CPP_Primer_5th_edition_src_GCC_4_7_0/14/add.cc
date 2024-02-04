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
using std::cin; using std::cout; using std::endl;

#include "Sales_data.h"
#include "Sales_item.h"

int main() 
{
    Sales_item item1, item2;
    cin >> item1 >> item2;   //read a pair of transactions
    // print the sum of two Sales_items
    cout << item1 + item2 << endl; 

	Sales_data data1, data2;
    read(read(cin, data1), data2);   //read a pair of transactions
    print(cout, add(data1, data2));  // print the sum of two Sales_datas
 	cout << std::endl; 

	cin >> data1 >> data2; // use input operator to read Sales_datas
    // use operators to print the sum of two Sales_datas
    cout << data1 + data2 << endl;

    return 0;
}
