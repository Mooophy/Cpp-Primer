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

#include "Sales_data.h"
#include "bookexcept.h"

#include <iostream>
using std::cin; using std::cerr; using std::endl;

int main()
{
    // use the hypothetical bookstore exceptions 
    Sales_data item1, item2, sum;
    while (cin >> item1 >> item2) {  // read two transactions
        try {
            sum = item1 + item2;     // calculate their sum
            // use sum
        } catch (const isbn_mismatch &e) {
          cerr << e.what() << ": left isbn(" << e.left
               << ") right isbn(" << e.right << ")" << endl;
        }
    }
     return 0;
}
