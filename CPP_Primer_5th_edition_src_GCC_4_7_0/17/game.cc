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

#include <random>
using std::default_random_engine;
using std::bernoulli_distribution;

#include <iostream>
using std::cin; using std::cout; using std::endl;

bool play(bool player) { return player; }
int main()
{
	string resp;
	// distributions and engines have state,
    // they must be defined outside the loop!
	default_random_engine e;  

	// 50/50 odds by default
	bernoulli_distribution b(0.55); // give the house a slight edge

	do {
		bool first = b(e);    // if true, the program will go first
		cout << (first ? "We go first" 
	                   : "You get to go first") << endl;
		// play the game passing the indicator of who goes first
		cout << ((play(first)) ? "sorry, you lost" 
	                           : "congrats, you won") << endl;
		cout << "play again? Enter 'yes' or 'no'" << endl;
	} while (cin >> resp && resp[0] == 'y');

	return 0;
}
