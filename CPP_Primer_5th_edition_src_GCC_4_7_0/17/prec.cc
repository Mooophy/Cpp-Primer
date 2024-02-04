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
using std::cout; using std::endl; 

#include <iomanip>
using std::setprecision;

#include <cmath>
using std::sqrt;

int main()
{
	// cout.precision reports the current precision value
	cout  << "Precision: " << cout.precision()  
	      << ", Value: "   << sqrt(2.0) << endl;
	
	// cout.precision(12) asks that 12 digits of precision be printed
	cout.precision(12);
	cout << "Precision: " << cout.precision() 
	     << ", Value: "   << sqrt(2.0) << endl;
	
	// alternative way to set precision using the setprecision manipulator
	cout << setprecision(3);
	cout << "Precision: " << cout.precision() 
	     << ", Value: "   << sqrt(2.0) << endl;
	
	return 0;
}
