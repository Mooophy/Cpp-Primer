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
using std::ostream;

#include <map>
using std::map;

#include <string>
using std::string;

#include <functional>
using std::bind; using std::function;
using namespace std::placeholders;

// this version of the desk calculator adds a class that
// represents both the left and right shift operators.
// This calss illustrates using pointers to member
// in the desk calculator
struct ShiftOps {
	ShiftOps(std::ostream &o) : os(o) { }
	unsigned Lshift(unsigned op1, unsigned op2) 
	{ os << "Lshift: " << op1 << " " << op2; return op1 << op2; }
	unsigned Rshift(unsigned op1, unsigned op2) 
	{ os << "Rshift: " << op1 << " " << op2; return op1 >> op2; }
private:
	std::ostream &os;
};

// ordinary function
int add(int i, int j) { return i + j; }

// lambda, which generates an unnamed function-object class
auto mod = [](int i, int j) { return i % j; };

// function-object class
// Note, in the first printing of The Primer this struct was named div
struct divide {
    int operator()(int denominator, int divisor) {
        return denominator / divisor;
    }
};

int main()
{
	function<int(int, int)> f1 = add;      // function pointer
	function<int(int, int)> f2 = divide(); // callable class type
	function<int(int, int)> f3 = [](int i, int j) // lambda
	                             { return i * j; };
	cout << f1(4,2) << endl; // prints 6
	cout << f2(4,2) << endl; // prints 2
	cout << f3(4,2) << endl; // prints 8

	// table of callable objects corresponding to each binary operator
	// all the callables must take two ints and return an int
	// an element can be a function pointer, function object, or lambda
	map<string, function<int(int, int)>> binops = {
		{"+", add},                  // function pointer
		{"-", std::minus<int>()},    // library function object
		{"/",  divide()},            // user-defined function object
		{"*", [](int i, int j) { return i * j; }}, // unnamed lambda
		{"%", mod} };                // named lambda object

	cout << binops["+"](10, 5) << endl; // calls add(10, 5)
	cout << binops["-"](10, 5) << endl; // uses the call operator of the minus<int> object
	cout << binops["/"](10, 5) << endl; // uses the call operator of the divide object
	cout << binops["*"](10, 5) << endl; // calls the lambda function object
	cout << binops["%"](10, 5) << endl; // calls the lambda function object

	// memp can point to either shift operation in ShiftOps
	// memp points to the Lshift member
	function<int (ShiftOps*, int, int)> memp = &ShiftOps::Lshift;  

	ShiftOps shift(cout);      // declare an object to which to bind the member pointer
	binops.insert({"<<", bind(memp, &shift, _1, _2)}); 
	cout << binops["<<"](10, 5) << endl; // calls member function
}
