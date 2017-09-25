/***************************************************************************
 *  @file       ex18.25.cpp
 *  @author     eipi10
 *  @date       15  Aug 2016
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 18.25
// Assume we have two base classes, Base1 and Base 2, each of which define a 
// virtual member named print and a virtual destructor. From these base classes 
// we derive the following classes, each of which redefines the print function.
// Answer:
// (a)MI
// (b)MI
// (c)MI
// (d)MI, D2, Base2, D1, Base1
// (e)MI, D2, Base2, D1, Base1
// (f)MI, D2, Base2, D1, Base1
// (d), (e), (f) will call all the destructor, for "Destructors are always 
// invoked in the reverse order from which the constructors are run." in
// Page 805

// gcc 6.1.0 x86_64-pc-linux-gnu
// results:
// pb1 print...........
// Print from MI
// pd1 print...........
// Print from MI
// pd2 print...........
// Print from MI
// delete pb2...........
// MI
// D2
// Base2
// D1
// Base1
// delete pd1...........
// MI
// D2
// Base2
// D1
// Base1
// delete pd2...........
// MI
// D2
// Base2
// D1
// Base1

#include <iostream>

struct Base1
{
	/* ... */
	virtual void print(){std::cout << "Print from Base1" << std::endl;}
	virtual ~Base1(){std::cout << "Base1" << std::endl;}
};
struct Base2
{
	/* ... */
	virtual void print(){std::cout << "Print from Base2" << std::endl;}
	virtual ~Base2(){std::cout << "Base2" << std::endl;}
};

struct D1 : public Base1 
{
	/* ... */
	void print() override {std::cout << "Print from D1" << std::endl;}
	~D1() override {std::cout << "D1" << std::endl;}
};
struct D2 : public Base2 
{
	/* ... */
	void print() override {std::cout << "Print from D2" << std::endl;}
	~D2() override {std::cout << "D2" <<std::endl;}
};
struct MI : public D1, public D2 
{
	/* ... */
	void print() override {std::cout << "Print from MI" << std::endl;}
	~MI() override {std::cout << "MI" << std::endl;}
};

//Using the following pointers, determine which funciton is used in each call:

int main()
{
	Base1 *pb1 = new MI;
	Base2 *pb2 = new MI;
	D1 *pd1 =new MI;
	D2 *pd2 = new MI;
	std::cout << "pb1 print..........." << std::endl;
	pb1 -> print();
	std::cout << "pd1 print..........." << std::endl;
	pd1 -> print();
	std::cout << "pd2 print..........." << std::endl;
	pd2 -> print();
	std::cout << "delete pb2..........." << std::endl;
	delete pb2;
	std::cout << "delete pd1..........." << std::endl;
	delete pd1;
	std::cout << "delete pd2..........." << std::endl;
	delete pd2;
}
