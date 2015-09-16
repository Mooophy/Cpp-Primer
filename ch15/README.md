# Chapter 15. Object-Oriented Programming

## Exercise 15.1:
> What is a virtual member?

A virtual member in a base class expects its derived class define its own version. In particular base classes ordinarily should define a virtual destructor, even if it does no work.

## Exercise 15.2:
> How does the protected access specifier differ from private?

* **private member**: base class itself and friend can access
* **protected members**: base class itself, friend and derived classes can access

## Exercise 15.3:
> Define your own versions of the `Quote` class and the `print_total` function.

[Quote](ex15.1.2.3/quote.h) | [main.cpp](ex15.1.2.3/main.cpp)

## Exercise 15.4:
> Which of the following declarations, if any, are incorrect? Explain why.

> class Base { ... };

> (a) class Derived : public Derived { ... };

> (b) class Derived : private Base { ... };

> (c) class Derived : public Base;

 * (a): **incorrect**, deirve from itself.
 * (b): **incorrect**, this is a definition not a declaration.
 * (c): **incorrect**, A derived class is declared like any other class. The declaration contains the class name but does not include its derivation list.

## Exercise 15.5:
> Define your own version of the `Bulk_quote` class.

[Bulk_quote](ex15.4.5.6/bulk_quote.h)

## Exercise 15.6:
> Test your `print_total` function from the exercises in § 15.2.1 (p. 595) by passing both `Quote` and `Bulk_quote` objects o that function.

[main](ex15.4.5.6/main.cpp)

## [Exercise 15.7](ex15.7/main.cpp)

## Exercise 15.8
> Define static type and dynamic type.

The static type of an expression is always known at compile time.

The dynamic type is the type of the object in memory that the variable or expression represents. The dynamic type may not be known until run time.

## Exercise 15.9:
> When is it possible for an expression’s static type to differ from its dynamic type? Give three examples in which the static and dynamic type differ.

The static type of a pointer or reference to a base class may differ from its dynamic type. Anything like this can be an example.

## Exercise 15.10:
> Recalling the discussion from §8.1 (p. 311), explain how the program on page 317 that passed an `ifstream` to the `Sales_data` read function works.

The function takes a `std::istream` from which `std::ifstream` is derived. Hence the `ifstream` object "is a" i`stream` , which is why it works.

## Exercise 15.11:
> Add a virtual debug function to your `Quote` class hierarchy that displays the data members of the respective classes.

```cpp
void Quote::debug() const
{
    std::cout << "data members of this class:\n"
              << "bookNo= " <<this->bookNo << " "
              << "price= " <<this->price<< " ";
}
```
[test](ex15.11/main.cpp)

## Exercise 15.12:
> Is it ever useful to declare a member function as both override and final? Why or why not?

 Sure. override means overriding the same name virtual function in base class. final means preventing any overriding this virtual function by any derived classes that are more lower at the hierarchy.

## [Exercise 15.13](ex15.12.13.14/main.cpp)

## [Exercise 15.14](ex15.12.13.14/main.cpp)

## Exercise 15.15:
> Define your own versions of `Disc_quote` and `Bulk_quote`.

[Disc_quote](ex15.15.16.17/disc_quote.h) | [Bulk_quote](ex15.15.16.17/bulk_quote.h)

## Exercise 15.16:
> Rewrite the class representing a limited discount strategy, which you wrote for the exercises in § 15.2.2 (p. 601), to inherit from Disc_quote.

[limit_quote](ex15.15.16.17/limit_quote.h)

## Exercise 15.17:
> Try to define an object of type Disc_quote and see what errors you get from the compiler.

`error: cannot declare variable 'd' to be of abstract type 'Disc_quote': Disc_quote d;`

`note: because the following virtual functions are pure within 'Disc_quote':  class Disc_quote : public Quote`


`note: virtual double Disc_quote::net_price(std::size_t) const: virtual double net_price(std::size_t n) const override = 0;`

## Exercise 15.18:
> Given the classes from page 612 and page 613, and assuming each object has the type specified in the comments, determine which of these assignments are legal. Explain why those that are illegal aren’t allowed:

> Base \*p = &d1;  //  d1 has type Pub_Derv

> p = &d2;          //  d2 has type Priv_Derv

> p = &d3;        //  d3 has type Prot_Derv

> p = &dd1;       //  dd1 has type Derived_from_Public

> p = &dd2;       //  dd2 has type Derived_from_Private

> p = &dd3;       //  dd3 has type Derived_from_Protected

* `Base \*p = &d1;`: **legal**
* `p = &d2;`: **illegal**
* `p = &d3;`: **illegal**
* `p = &dd1;`: **legal**
* `p = &dd2;`: **illegal**
* `p = &dd3;`: **illegal**

User code may use the derived-to-base conversion only if D inherits publicly from B. User code may not use the conversion if D inherits from B using either protected or private.
