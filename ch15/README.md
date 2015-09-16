# Chapter 15. Object-Oriented Programming

## Exercise 15.1:
>What is a virtual member?

A virtual member in a base class expects its derived class define its own version. In particular base classes ordinarily should define a virtual destructor, even if it does no work.

## Exercise 15.2:
>How does the protected access specifier differ from private?

* **private member**: base class itself and friend can access
* **protected members**: base class itself, friend and derived classes can access

## Exercise 15.3:
>Define your own versions of the Quote class and the print_total function.

[Quote](ex15.1.2.3/quote.h) | [main.cpp](ex15.1.2.3/main.cpp)

## Exercise 15.4:
>Which of the following declarations, if any, are incorrect? Explain why.

>class Base { ... };
 (a) class Derived : public Derived { ... };
 (b) class Derived : private Base { ... };
 (c) class Derived : public Base;

 * (a): **incorrect**, deirve from itself.
 * (b): **incorrect**, this is a definition not a declaration.
 * (c): **incorrect**, A derived class is declared like any other class. The declaration contains the class name but does not include its derivation list.

## Exercise 15.5:
>Define your own version of the Bulk_quote class.

[Bulk_quote](ex15.4.5.6/bulk_quote.h)

## Exercise 15.6:
>Test your print_total function from the exercises in § 15.2.1 (p. 595) by passing both Quote and Bulk_quote objects o that function.

[main](ex15.4.5.6/main.cpp)

## Exercise 15.7:
>Define a class that implements a limited discount strategy, which applies a discount to books purchased up to a given limit. If the number of copies exceeds that limit, the normal price applies to those purchased beyond the limit.

[main](ex15.7//main.cpp)
