/* Exercise 18.29: 

Given the following class hierarchy: 

class Class { ... }; class Base : public Class { ... }; 
class D1 : virtual public Base { ... }; 
class D2 : virtual public Base { ... }; 
class MI : public D1, public D2 { ... }; 
class Final : public MI, public Class { ... }; 

(a) In what order are constructors and destructors run on a Final object? 
(b) A Final object has how many Base parts? How many Class parts? 
(c) Which of the following assignments is a compile-time error? 

Base *pb;    Class *pc;       MI *pmi;     D2 *pd2; 
(a) pb = new Class; 	(b) pc = new Final; 
(c) pmi = pb; 			(d) pd2 = pmi;

Solution: 
(a) Constructors run order: Class Base D1 D2 MI Class Final.
	Destructors run order: Final Class MI D2 D1 Base Call.
	Class parts are constructed from left to right and base class to derived class.
(b) 1 Base part and 2 Class parts.
	Because ‘Base’ is a virtual base class of ‘D1’ and ‘D2’. There is only 1 Base part. 
	However, ‘Class’ is a normal base class of ‘Final’ and ‘Base’. So there is 2 Class part.
(c) error. Can't convert a pointer of base class to a pointer of derived class implicitly.
	error. ‘Class’ is an ambiguous base of ‘Final’.
	error. Can't convert a pointer of base class to a pointer of derived class implicitly.
	pass. A pointer of derived class can be cast to a pointer of base class.

*/
#include <iostream>

using namespace std;

class Class {
public:
	Class() { cout << "Class() called" << endl; }
	~Class() { cout << "~Class() called" << endl; }
};

class Base : public Class {
public:
	Base() { cout << "Base() called" << endl; }
	~Base() { cout << "~Base() called" << endl; }
};

class D1 : virtual public Base {
public:
	D1() { cout << "D1() called" << endl; }
	~D1() { cout << "~D1() called" << endl; }
};

class D2 : virtual public Base {
public:
	D2() { cout << "D2() called" << endl; }
	~D2() { cout << "~D2() called" << endl; }
};

class MI : public D1, public D2 {
public:
	MI() { cout << "MI() called" << endl; }
	~MI() { cout << "~MI() called" << endl; }
};

class Final : public MI, public Class {
public:
	Final() { cout << "Final() called" << endl; }
	~Final() { cout << "~Final() called" << endl; }
};

int main(int argc, char const *argv[])
{
	Final final;
	Base *pb;
	Class *pc;
	MI *pmi;
	D2 *pd2;
	// pb = new Class;
	// pc = new Final;
	// pmi = pb;
	pd2 = pmi;
	return 0;
}