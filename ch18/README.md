## Exercise 18.1

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


## Exercise 18.2

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

## Exercise 18.3

## Exercise 18.21

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


## Exercise 18.22

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

## Exercise 18.23

>Using the hierarchy in exercise 18.22 along with class D defined below, and assuming each class defines a default constructor, which,if any,
of the following conversion are not permitted?

```cpp
class D : public c{ ... };
D *pd = new D;

```
All of the conversions are permitted.


## Exercise 18.24

>On page 807 we presented a series of calls made through a Bear pointer that pointed to a Panda object.
>Explain each call assuming we used a ZooAnimal pointer pointing to a Panda Object instead.

```cpp
ZooAnimal *pb = new Panda ("ying_yang");

pb->print();//Ok, part of ZooAnimal interface
pb->cuddle();//Error, not part of interface
pb->highlight();//Error, not part of interface
delete pb;//Ok, part of interface
```

## Exercise 18.25

>Assume we have two base classes, Base1 and Base 2, each of which
>define a virtual member named print and a virtual destructor.  From these base
>classes we derive the following classes, each of which redefines the print function.

[cpp](./ex18.25.cpp "Exercise 18.25")

## Exercise 18.26

>Given the hierarchy in the box on page 810, why is the following call to print an error?
>Revise MI to allow this call to print to compile and execute correctly.

```cpp
#include <iostream>
#include <vector>
struct Base1{
    void print(int) const{
        std::cout<<"Base1 Print Used"<<std::endl;
        };
protected:
        int ival;
        double dval;
        char cval;
private:
        int *id;
};
struct Base2 {
    void print(double) const;
protected:
    double fval;
private:
    double dval;
};

struct Derived : public Base1 {
void print(std::string) const;
protected:
    std::string sval;
    double dval;
};

struct MI : public Derived, public Base2{

void print(std::vector<double>){};
void print(int x){
    Base1::print(x);
}
protected:
    int *ival;
    std::vector<double> dvec;
};

using namespace std;

int main()
{
    MI mi;
    mi.print(42);
    return 0;
}
```

There is no matching version of print in MI that matches an integer argument.  If we just remove the print function in MI there is an ambiguity between the Derived and Base2 versions
of print; therefore, we should overload the MI version of print() to take an int argument.

## Exercise 18.27

>Given the hierarchy in the box on page 810, why is the following call to print an error?
>Revise MI to allow this call to print to compile and execute correctly.

```cpp
#include <iostream>
#include <vector>
struct Base1{
    void print(int) const{
        std::cout<<"Base1 Print Used"<<std::endl;
        };
protected:
    int ival;
    double dval;
    char cval;
private:
    int *id;
};

struct Base2 {
    void print(double) const;
protected:
    double fval;
private:
    double dval;
};

struct Derived : public Base1 {
    void print(std::string) const;
protected:
    std::string sval=std::string(1,Base1::cval);//(e)
    double dval;
};

struct MI : public Derived, public Base2{

void print(std::vector<double>){};
void print(int x){
    Base1::print(x);
}

int ival;
double dval;

void foo(double cval)
    {
        int dval;
        dval = Base1::dval+Derived::dval;//(c)
        Base2::fval=dvec.back()-1;//(d)
        Derived::sval[0]= Base1::cval;//(e)
        std::cout<<dval;
    }
protected:
    std::vector<double> dvec={9,8,7};
};

int main()
{
    MI mi;
    return 0;
}
```

(a) Everything that is a property of the classes that MI derives from is visible except those that are private.
(b) Yes any names in the base classes that repeat and are not private can be accessed in foo by adding a scope operator.
(c) see above
(d) see above
(e) see above

## Exercise 18.28

>Given the following class hierarchy, which inherited members can be accessed without qualification, from within the vmi class?
>which require qualification? Explain your reasoning.

```cpp
struct Base{
    void bar(int); //Accessed without qualification, not defined with int arg anywhere
protected:
    int ival;//Need qualification, VMI will use Derived2::ival by default
};

struct Derived1 : virtual public Base{
    void bar(char);//Accessed with no qualification, VMI derives from Derived1 which derives from Base.
    void foo(char);//Need qualification, can convert arg between two foos.
protected:
    char cval;//need to qualify ambiguous with other cval.
};

struct Derived2 : virtual public Base{
void foo(int);//Need qualification, can convert arg between two foos.
protected:
    int ival;//Accessed with no qualification.
    char cval;//need to qualify ambiguous with other cval.
};
class VMI : public Derived1, public Derived2 { };
```
