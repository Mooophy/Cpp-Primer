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

class Base {
public:
    virtual int fcn();
};

int Base::fcn() { cout << "Base::fcn()" << endl; return 0; }

class D1 : public Base {
public:
    // hides fcn in the base; this fcn is not virtual
    // D1 inherits the definition of Base::fcn() 
    int fcn(int);      // parameter list differs from fcn in Base
	virtual void f2(); // new virtual function that does not exist in Base
};

int D1::fcn(int) { cout << "D1::fcn(int)" << endl; return 0; }
void D1::f2() { cout << "D1::f2()" << endl; }

class D2 final : public D1 {
public:
    int fcn(int); // nonvirtual function hides D1::fcn(int)
    int fcn();    // overrides virtual fcn from Base
	void f2();    // overrides virtual f2 from D1
};

int D2::fcn(int) { cout << "D2::fcn(int)" << endl; return 0; }
int D2::fcn() { cout << "D2::fcn()" << endl; return 0; }
void D2::f2() { cout << "D2::f2()" << endl; }

int main()
{
    D1 dobj, *dp = &dobj;
    dp->fcn(42); // ok: static call to D1::fcn(int)

    Base bobj;  D1 d1obj; D2 d2obj;

    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
    bp1->fcn(); // virtual call, will call Base::fcn at run time
    bp2->fcn(); // virtual call, will call Base::fcn at run time
    bp3->fcn(); // virtual call, will call D2::fcn at run time

	D1 *d1p = &d1obj; D2 *d2p = &d2obj;
	d1p->f2(); // virtual call, will call D1::f2() at run time
	d2p->f2(); // virtual call, will call D2::f2() at run time
	Base *p1 = &d2obj; D1 *p2 = &d2obj; D2 *p3 =  &d2obj;
	p2->fcn(42);  // statically bound, calls D1::fcn(int)
	p3->fcn(42);  // statically bound, calls D2::fcn(int)

    Base* bp = &d1obj; D1 *dp1 = &d2obj; D2 *dp2 = &d2obj;
    dp1->fcn(10); // static call to D1::fcn(int)
    dp2->fcn(10); // static call to D2::fcn(int)
}

