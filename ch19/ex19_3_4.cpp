/* Exercises Section 19.2.1 

Exercise 19.3: 

Given the following class hierarchy in which each class defines a public default constructor and virtual destructor: 

class A { . . . }; 
class B : public A { . . . }; 
class C : public B {  . . . }; 
class D : public B, public A { . . . };

which, if any, of the following dynamic_casts fail? 
(a) A *pa = new C;    
	B *pb = dynamic_cast< B* >(pa); 
(b) B *pb = new B;    
	C *pc = dynamic_cast< C* >(pb); 
(c) A *pa = new D;    
	B *pb = dynamic_cast< B* >(pa); 

Solution:
(a) Succeed. The type of ‘pa’ (class type 'C') is publicly derived from the target type 'B'.
(b) Fail. The type of ‘pb’ (class type 'B') is a public base class of the target type 'C'. ‘pc’ will equal to nullptr.
(c) Fail. ‘A’ is an ambiguous base of ‘D’. Converting a pointer of 'D' to a pointer of 'A' is not allowed.

Exercise 19.4: 

Using the classes defined in the first exercise, rewrite the following code to convert the expression *pa to the type C&: 

if (C *pc = dynamic_cast< C* >(pa))    
	// use C's members 
} else {    
	// use A's members 
} 

Solution:

try {
	C &rc = dynamic_cast<C&>(ra);
	// use C's members 
} catch (bad_cast) {
	// use A's members 
}

*/

#include <iostream>
#include <typeinfo>

using namespace std;

class A {
public:
	virtual ~A() {}
};

class B : public A {
public:
	virtual ~B() {}
};

class C : public B {
public:
	virtual ~C() {}
};

class D : public B, public A {
public:
	virtual ~D() {}
};

int main(int argc, char const *argv[])
{
	/* Exercise 19.3 */

	A *pa = new C;    
	B *pb = dynamic_cast< B* >(pa); 
	if (pb) cout << "19.3 (a) succeed!" << endl;
	else cout << "19.3 (a) fail!" << endl;

	pb = new B;    
	C *pc = dynamic_cast< C* >(pb); 
	if (pc) cout << "19.3 (b) succeed!" << endl;
	else cout << "19.3 (b) fail!" << endl;

/*	pa = new D;    
	pb = dynamic_cast< B* >(pa); */

	/* Exercise 19.4 */

	C c; B b;
	A &ra1 = c, &ra2 = b;
	try {
		/* succeed */
		C &rc1 = dynamic_cast<C&>(ra1);
		cout << "19.4 succeed!" << endl;
		/* fail */
		C &rc2 = dynamic_cast<C&>(ra2);
	} catch (bad_cast) {
		cout << "19.4 failed!" << endl;
	}
	return 0;
}