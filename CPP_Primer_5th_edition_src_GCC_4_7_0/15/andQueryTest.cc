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
using std::string;

#include <iostream>
using std::cout; using std::endl;

#include <set>
using std::set;

int main(int argc, char **argv)
{
	// gets file to read and builds map to support queries
	TextQuery file = get_file(argc, argv);

    do {
        string sought1, sought2;
        // stop if hit eof on input or a "q" is entered
        if (!get_words(sought1, sought2)) break;
    
        // find all the occurrences of the requested string
        Query andq = Query(sought1) & Query(sought2);
        cout << "\nExecuting query for: " << andq << endl;
        auto results = andq.eval(file);
        // report matches
        print(cout, results);
    
        results = Query(sought1).eval(file);
        cout << "\nExecuted query: " << Query(sought1) << endl;
        // report matches
        print(cout, results);
    
        results = Query(sought2).eval(file);
        cout << "\nExecuted query: " << Query(sought2) << endl;
        // report matches
        print(cout, results);
    } while(true);

    return 0;
}
