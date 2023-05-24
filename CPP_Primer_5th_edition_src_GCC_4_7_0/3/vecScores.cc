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

#include <vector>
using std::vector;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	// hold the grades we read from the standard input
	vector<unsigned> grades;

	// count the number of grades by clusters of ten: 
	// 0--9, 10--19, . ..  90--99, 100
	vector<unsigned> scores(11, 0); // 11 buckets, all initially 0
	unsigned grade;
	while (cin >> grade) {      // read the grades
		if (grade <= 100)       // handle only valid grades
			grades.push_back(grade);
			++scores[grade/10]; // increment the counter for the current cluster
	}
	cout << "grades.size = " << grades.size() << endl;
	for (auto it : grades)
		cout << it << " " ;
	cout << endl;

	cout << "scores.size = " << scores.size() << endl;
	for (auto it : scores)
		cout << it << " " ;
	cout << endl;

	// equivalent program using iterators instead of subscripts
	vector<unsigned> alt_scores(11, 0);  // 11 buckets, all initially 0
	// for each grade in the input
	for (auto it = grades.begin(); it != grades.end(); ++it) {
		unsigned i = *it;
		// increment the counter for the current cluster
		++(*(alt_scores.begin() + i/10));
	}

	cout << "alt_scores.size = " << alt_scores.size() << endl;
	for (auto it = alt_scores.begin(); it != alt_scores.end(); ++it) 
		cout << *it << " " ;
	cout << endl;

}

