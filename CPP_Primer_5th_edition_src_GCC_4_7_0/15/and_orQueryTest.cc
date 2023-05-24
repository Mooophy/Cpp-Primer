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

#include "Query.h"
#include "TextQuery.h"
#include <string>
#include <set>
#include <iostream>

using std::set;
using std::string;
using std::cin; using std::cout; using std::cerr;
using std::endl;

int main(int argc, char **argv)
{
    // gets file to read and builds map to support queries
    TextQuery file = get_file(argc, argv);

    // iterate with the user: prompt for a word to find and print results
    while (true) {
        string sought1, sought2, sought3;
        if (!get_words(sought1, sought2)) break;
        cout << "\nenter third word: " ;
        cin  >> sought3;
        // find all the occurrences of the requested string
        Query q = Query(sought1) & Query(sought2) 
                             | Query(sought3);
        cout << "\nExecuting Query for: " << q << endl;
        const auto results = q.eval(file);
        // report matches
		print(cout, results);
     } 
     return 0;
}
