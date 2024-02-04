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

#include <algorithm>
using std::copy;

#include <list>
using std::list;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

#include <iterator>
using std::inserter; using std::front_inserter;

void print(const string &label, const list<int> &lst)
{
	cout << label << endl;
	for (auto iter : lst)
        cout << iter << " ";
    cout << endl;
}

int main() 
{

    list<int> lst = {1,2,3,4};
	print("lst", lst);

    // after copy completes, lst2 contains 4 3 2 1
	list<int> lst2, lst3;     // empty lists
    copy(lst.cbegin(), lst.cend(), front_inserter(lst2));

    // after copy completes, lst3 contains 1 2 3 4
    copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));

	print("lst2", lst2);
	print("lst3", lst3);
	
	vector<int> v = {1,2,3,4,5};
	list<int> new_lst = {6,7,8,9};
	auto it = new_lst.begin();
	copy(v.begin(), v.end(), inserter(new_lst, it));
	print("new_lst", new_lst);

	return 0;
}
