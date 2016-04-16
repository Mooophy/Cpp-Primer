##Exercise 18.1

> What is the type of the exception object in the following throws?
> 
> **(a)**`range_error r("error");`
> `throw r`;
> **(b)**`exception *p = &r;`
> `throw *P;`

>What would happen if the `throw` in **(b)** were written as `throw p`?

	The type of the exception object in (a) is range_error which is used to report range errors in internal computations.
	The type of the exception object in (b) is exception.
	If the "throw" in (b) were written as "throw p", there will be a runtime error.


##Exercise 18.2

> Explain what happens if an exception occurs at the indicated point:


```cpp
void exercise(int *b, int *e)
{
	vector<int> v(b, e);
	int *p = new int[v.size()];
	ifstream in("ints");
	// exception occurs here
}
```

The space "p" points will not be free. There will be a memory leak.

##Exercise 18.3

##Exercise 18.21

>Explain the following declarations. Identify any that are in error and explain why they are incorrect:

>**(a)**
```cpp
class CAD{};
class Vehicle{};
class CADVehicle : public CAD, Vehicle{};
```


CAD Vehicle publicly inherits from CAD and privaetely inherits from Vehicle.  CADVehicle gets
all the  public and private methods that Vehicle has but cant be cast to a Vehicle argument.
It is an "inaccessible" base.
for example

```cpp
CadVehicle example;

void foo(Vehicle){/*do something*/};

foo(CADVehicle);//will not work, will work if Vehicle were public
```

>**(b)**
```cpp
class DBList: public List,public List {/*do something*/};
```

Error because you are trying to derive from the same base class twice.  If two different 
libraries or header files define the same named class,you need to specify with
a scope resolution operator, i.e. headerfile_name::List.

>**(c)**
```cpp
class iostream : public istream, public ostream{/*do something*/};
```


Ok. 


##Exercise 18.22

>Given the following class hierarchy, in which each class defines a default constructor.
>What is the order of constructor execution for the following definition.

```cpp
#include <iostream>

class A {};
class B : public A{};
class C : public B{};

class X {};
class Y {};
class Z : public X, public Y {};

class MI : public C, public Z {};
class D : public X, public C{};

MI mi;

int main()
{
*pd = new D;
X *px = pd;
B *pb = pd;
A *pa =pd;
C *pc = pd;
return 0;
}
```


The order in which base classes are constructed depends on the order in which they appear in the class derivation list.
construction order is as follows: A, B, C, X, Y, Z, MI.  

##Exercise 18.23

>Using the hierarchy in exercise 18.22 along with class D defined below, and assuming each class defines a default constructor, which,if any,
of the following conversion are not permitted?

```cpp
class D : public c{ ... };
D *pd = new D;

```
All of the conversions are permitted.


##Exercise 18.24

>On page 807 we presented a series of calls made through a Bear pointer that pointed to a Panda object.
>Explain each call assuming we used a ZooAnimal pointer pointing to a Panda Object instead.

```cpp
ZooAnimal *pb = new Panda ("ying_yang");

pb->print();//Ok, part of ZooAnimal interface
pb->cuddle();//Error, not part of interface
pb->highlight();//Error, not part of interface
delete pb;//Ok, part of interface
```

##Exercise 18.25

>Assume we have two base classes, Base1 and Base 2, each of which
>define a virtual member named print and a virtual destructor.  From these base
>classes we derive the following classes, each of which redefines the print function.

```cpp
class D1 : public Base1 {/* ... */};
class D2 : public Base2 {/* ... */};
class MI : public D1, public D2 {/* ... */};

//Using the following pointers, determine which funciton is used in each call:

Base1 *pb1 = new MI;
Base2 *pb2 = new MI;
D1 *pd1 =new MI;
D2 *pd2 = new MI;
```

(a), (b), and (c) will all call the MI version of print.
All of the pointer class types contain virtual versions of print so, they will look for derived definitions of print.

(d) The MI destructor is called then the base1 destructor is called.
(e) The MI destructor, then the D1 destructor, then the base 1 destructor is called.
(f) The MI destructor, then the D2 destructor, then the Base2 destructor is called.
