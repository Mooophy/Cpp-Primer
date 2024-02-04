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
#include <vector>
#include <iostream>

struct Base1 {
    void print(int) const     // public by default
		{ std::cout << "Base1::print(int) " << ival << std::endl; }
protected:
    int ival = 1;
};

struct Base2 {
    void print(double) const        // public by default
		{ std::cout << "Base2::print(double) " << ival << std::endl; }
protected:
    int ival = 2;
};

struct Derived : public Base1 {
    void print(std::string) const   // public by default
		{ std::cout << "Derived::print(string) " << ival << std::endl; }
protected:
	int ival = 3;
};

struct MI : public Derived, public Base2 {
    void print(std::vector<double>) // public by default
		{ std::cout << "MI::print(int(vector<double>) " 
			        << ival << std::endl; }
protected:
    int ival = 4;
};

int main()
{
	MI obj;
	obj.Base1::print(0);
	obj.Base2::print(3.14);
	obj.Derived::print("hi");
	obj.print(std::vector<double>());
	
	return 0;
}
