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

#include "Blob.h"

#include <utility>
using std::pair;

#include <string>
using std::string;

typedef Blob<string> StrBlob; 


template<typename T> using twin = pair<T, T>;

template <typename T> using partNo = pair<T, unsigned>;

int main()
{
	// authors is a pair<string, string>
	twin<string> author("Mark", "Twain");
	
	twin<int> win_loss(2, 45);  // win_loss is a pair<int, int>
	
	typedef string Vehicle;
	partNo<Vehicle> car("volvo", 242);  // car is a pair<Vehicle, unsigned>

	return 0;
}
