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

#include <cmath>
using std::sqrt;

#include <iostream>
using std::cout; using std::endl;
using std::fixed; using std::scientific; 
using std::uppercase; using std::nouppercase;

#include "Version_test.h"
#ifdef HEX_MANIPS
using std::hexfloat; using std::defaultfloat;
#endif

int main() 
{
	cout << "default format: " << 100 * sqrt(2.0) << '\n'
		 << "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
	     << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
#ifdef HEX_MANIPS     // no workaround for this missing manipulator
		 << "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << '\n'
#endif
		 << "use defaults: " << defaultfloat << 100 * sqrt(2.0) 
		 << "\n\n";
	
	cout << uppercase
	     << "scientific: " << scientific << sqrt(2.0) << '\n'
	     << "fixed decimal: " << fixed << sqrt(2.0) << '\n'
#ifdef HEX_MANIPS     // no workaround for this missing manipulator
		 << "hexadecimal: " << hexfloat << sqrt(2.0) << "\n\n"
#endif
		 << nouppercase;
	
	return 0;
}
