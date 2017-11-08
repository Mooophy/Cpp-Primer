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

 * (a): **incorrect**, derive from itself.
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
[Exercise 15.9](ex15.9/main.cpp)

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

[Limit_quote](ex15.15.16.17/limit_quote.h)

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

* Base \*p = &d1; **legal**
* p = &d2; **illegal**
* p = &d3; **illegal**
* p = &dd1; **legal**
* p = &dd2; **illegal**
* p = &dd3; **illegal**

User code may use the derived-to-base conversion only if D inherits publicly from B. User code may not use the conversion if D inherits from B using either protected or private.

## Exercise 15.19:
> Assume that each of the classes from page 612 and page 613 has a member function of the form:

> `void memfcn(Base &b) { b = *this; }`

> For each class, determine whether this function would be legal.

Member functions and friends of D can use the conversion to B regardless of how D inherits from B. The derived-to-base conversion to a direct base class is always accessible to members and friends of a derived class.

Hence, the 3 below are all legal:

* Pub_Derv
* Priv_Derv
* Prot_Derv

Member functions and friends of classes derived from D may use the derived-to-base conversion if D inherits from B using either public or protected. Such code may not use the conversion if D inherits privately from B.Hence:

* Derived_from_Public **legal**
* Derived_from_Private **illegal**
* Derived_from_Protected **legal**

## [Exercise 15.20](ex15.18.19.20/main.cpp)
> Choose one of the following general abstractions containing a family of types (or choose one of your own). Organize the types into an inheritance hierarchy:

> (a) Graphical file formats (such as gif, tiff, jpeg, bmp)

> (b) Geometric primitives (such as box, circle, sphere, cone)

> (c) C++ language types (such as class, function, member function)

[Here is a example of 2D shape](ex15.21.22/main.cpp)

## [Exercise 15.21](ex15.21.22/main.cpp)

## Exercise 15.23:
> Assuming class D1 on page 620 had intended to override its inherited `fcn` function, how would you fix that class? Assuming you fixed the class so that `fcn` matched the definition in Base, how would the calls in that section be resolved?

remove the parameter int.

[main](ex15.23.cpp) | [Disscussion on SO](http://stackoverflow.com/questions/21320779/trying-to-understand-dynamic-binding-and-virtual-functions)

## Exercise 15.24:
> What kinds of classes need a virtual destructor? What operations must a virtual destructor perform?

Generally, a base class should define a virtual destructor.

The destructor needs to be virtual to allow objects in the inheritance hierarchy to be dynamically allocated and destroyed.

## Exercise 15.25:
> Why did we define a default constructor for Disc_quote? What effect, if any, would removing that constructor have on the behavior of Bulk_quote?

Without it, when building the statement below, the compiler would complain that:

> note: 'Bulk_quote::Bulk_quote()' is implicitly deleted because the default definition would be ill-formed.

The reason is that a constructor taking 4 parameters has been defined, which prevented the compiler generate synthesized version default constructor.

As a result, the default constructor of any class derived from it has been defined as deleted. Thus the default constructor must be defined explicitly so that the derived classes can call it when executing its default constructor.

## Exercise 15.26:
> Define the `Quote` and `Bulk_quote` copy-control members to do the same job as the synthesized versions. Give them and the other constructors print statements that identify which function is running. Write programs using these classes and predict what objects will be created and destroyed.

>Compare your predictions with the output and continue experimenting until your predictions are reliably correct.

[Quote](ex15.26/quote.h) | [Bulk_quote](ex15.26/bulk_quote.h)

## Exercise 15.27:
> Redefine your `Bulk_quote` class to inherit its constructors.

**rules:**

1. only inherit from the direct base class.
2. default, copy and move constructors can not inherit.
3. any data members of its own are default initialized.
4. the rest details are in the section section 15.7.4.

[Bulk_quote](ex15.27/bulk_quote.h)

## [Exercise 15.28](ex15.28.29/main.cpp)

## Exercise 15.29:
> Repeat your program, but this time store `shared_ptrs` to objects of type `Quote`. Explain any discrepancy in the sum generated by the this version and the previous program. If there is no discrepancy, explain why there isn’t one.

Since the vector from the previous exercise holds objects, there's no polymorphism happened while calling the virtual function net_price. Essentially, the objects held in it are the Quote subjects of the Bulk_quote objects being pushed back, Thus, the virtual net_price functions called are Quote::net_price. As a result, no discount was applied. The outcome was 9090.

The objects held for this exercise are smart pointers to the Quote objects.In this case, polymorphism happened as expected.The actual virtual functions being called are Bulk_quote::net_price that ensure discount is applied.Thus, the outcome is 6363. It can be found that 30% discount has been applied to the price calculation.

## Exercise 15.30:
> Write your own version of the `Basket` class and use it to compute prices for the same transactions as you used in the previous exercises.

[Basket h](ex15.30/basket.h) | [Basket cpp](ex15.30/basket.cpp) | [main](ex15.30/main.cpp)

## Exercise 15.31:
> Given that s1, s2, s3, and s4 are all strings, determine what objects are created in the following expressions:

> (a) `Query(s1) | Query(s2) & ~ Query(s3);`

> (b) `Query(s1) | (Query(s2) & ~ Query(s3));`

> (c) `(Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)));`

* (a) `OrQuery, AndQuery, NotQuery, WordQuery`
* (b) the same as the previous one
* (c) `OrQuery, AndQuery, WordQuery`

## Exercise 15.32:
> What happens when an object of type Query is copied, moved, assigned, and destroyed?

* **copy:**
While being copied, the synthesized copy constructor is called. It copies the data member into the new object. Since in this case, the data member is a shared pointer, while copying, the corresponding shared pointer points to the same address and the use count from the both shared pointer becomes 2.

* **move:**
while being moved, the synthesized move constructor is called. It moves the data member into the new object. In this case, the shared pointer from the newly created object will point to the address to which the original shared pointer pointed.
After the move operation, the use count of the shared pointer in the new object is 1, whereas the pointer from the original object becomes `nullptr`.

* **copy assignment:**
The synthesized copy assignment will be called. The outcome of this operation is identical with the copy operation.

* **move assignment:**
The synthesized move assignment will be called. The rest is the same as the move operation.

* **destroy:**
The synthesized destructor will be called. It will call the destructor of `shared_ptr` which decrements the use count. If the count becomes zero, the destructor from shared_ptr will delete the resources it point to.

## Exercise 15.33:
> What about objects of type `Query_base`?

Managed by the synthesized version. Since Query_base a abstract class, the object of this type is essentially a subobject of its derived class.

## Exercise 15.34:
> For the expression built in Figure 15.3 (p. 638):

> (a) List the constructors executed in processing that expression.

> (b) List the calls to rep that are made from `cout << q`.

> (c) List the calls to `eval` made from `q.eval()`.


* **a:** Query q = Query("fiery") & Query("bird") | Query("wind");


1. `Query::Query(const std::string& s)` where s == "fiery","bird" and "wind"
2. `WordQuery::WordQuery(const std::string& s)` where s == "fiery","bird" and "wind"
3. `AndQuery::AndQuery(const Query& left, const Query& right);`
4. `BinaryQuery(const Query&l, const Query& r, std::string s);`
5. `Query::Query(std::shared_ptr<Query_base> query)` 2times
6. `OrQuery::OrQuery(const Query& left, const Query& right);`
7. `BinaryQuery(const Query&l, const Query& r, std::string s);`
8. `Query::Query(std::shared_ptr<Query_base> query)` 2times


* **b:**


1. `query.rep()` inside the operator <<().
2. `q->rep()` inside the member function rep().
3. `OrQuery::rep()` which is inherited from `BinaryQuery`.
4. `Query::rep()` for `lhs` and `rhs`:
for `rhs` which is a `WordQuery` : `WordQuery::rep()` where `query_word("wind")` is returned.For `lhs` which is an `AndQuery`.
5. `AndQuery::rep()` which is inherited from `BinaryQuery`.
6. `BinaryQuer::rep()`: for `rhs: WordQuery::rep()`   where query_word("fiery") is returned. For `lhs: WordQuery::rep()` where query_word("bird" ) is returned.


* **c:**


1. `q.eval()`
2. `q->rep()`: where q is a pointer to `OrQuary`.
3. `QueryResult eval(const TextQuery& )const override`: is called but this one has not been defined yet.

## Exercise 15.35:
> Implement the `Query` and `Query_base classes`, including a definition of rep but omitting the definition of `eval`.

[Query](ex15.34.35.36.39/query.h) | [Query_base](ex15.34.35.36.38/query_base.h)

## Exercise 15.36:
> Put print statements in the constructors and rep members and run your code to check your answers to (a) and (b) from the first exercise.

```cpp
Query q = Query("fiery") & Query("bird") | Query("wind");

WordQuery::WordQuery(wind)
Query::Query(const std::string& s) where s=wind
WordQuery::WordQuery(bird)
Query::Query(const std::string& s) where s=bird
WordQuery::WordQuery(fiery)
Query::Query(const std::string& s) where s=fiery
BinaryQuery::BinaryQuery()  where s=&
AndQuery::AndQuery()
Query::Query(std::shared_ptr<Query_base> query)
BinaryQuery::BinaryQuery()  where s=|
OrQuery::OrQuery
Query::Query(std::shared_ptr<Query_base> query)
Press <RETURN> to close this window...
```

```cpp
std::cout << q <<std::endl;

Query::rep()
BinaryQuery::rep()
Query::rep()
WodQuery::rep()
Query::rep()
BinaryQuery::rep()
Query::rep()
WodQuery::rep()
Query::rep()
WodQuery::rep()
((fiery & bird) | wind)
Press <RETURN> to close this window...
```

## Exercise 15.37:

## Exercise 15.38:
> Are the following declarations legal? If not, why not? If so, explain what the declarations mean.

> BinaryQuery a = Query("fiery") & Query("bird");

>AndQuery b = Query("fiery") & Query("bird");

> OrQuery c = Query("fiery") & Query("bird");


1. Illegal. Because `BinaryQuery` is an abstract class.
2. Illegal. Because operator & returns a `Query` which can not convert to an `AndQuery` object.
3. Illegal. Because operator & returns a `Query` which can not convert to an `OrQuery` object.

## Exercise 15.39:
> Implement the `Query` and `Query_base` classes. Test your application by evaluating and printing a query such as the one in Figure 15.3 (p. 638).

[Query](ex.15.39.40/query.h) | [Query_base](ex.15.39.40/query_base.h) | [main](ex.15.39.40/main.cpp)

## Exercise 15.40:
> In the `OrQuery` eval function what would happen if its `rhs` member returned an empty set? What if its `lhs` member did so? What if both `rhs` and `lhs` returned empty sets?

Nothing special will happen.  The codes as following:

```cpp
std::shared_ptr<std::set<line_no>> ret_lines =
       std::make_shared<std::set<line_no>>(left.begin(), left.end());
```

Since `std::make_shared` will allocate dynamically a new `std::set`, nothing will be added into this `std::set` if any set is empty.The codes in main function proves this.

## Exercise 15.41:

## Exercise 15.42:
>  Design and implement one of the following enhancements:

> **(a)** Print words only once per sentence rather than once per line.

> **(b)** Introduce a history system in which the user can refer to a previous query by number, possibly adding to it or combining it with another.

> **(c)** Allow the user to limit the results so that only matches in a given range of lines are displayed.

Here are solutions for [(b)](ex15.42_b/main.cpp) and [(c)](ex15.42_c/main.cpp).
