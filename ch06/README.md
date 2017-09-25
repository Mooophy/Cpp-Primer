## Exercise 6.1

**Parameters**: Local variable declared inside the function parameter list.
they are initialized by the **arguments** provided in the each function call.

**Arguments**: Values supplied in a function call that are used to initialize the function's **parameters**.

## Exercise 6.2
```cpp
(a) string f() {  // return should be string, not int
          string s;
          // ...
          return s;
    }
(b) void f2(int i) { /* ... */ }  // function needs return type
(c) int calc(int v1, int v2) { /* ... */ }  // parameter list cannot use same name twice
(d) double square (double x) { return x * x; }  // function body needs braces
```

## Exercise 6.3

```cpp
#include <iostream>

int fact(int i)
{
    if(i<0)
    {
        runtime_error err("Input cannot be a negative number");
        cout << err.what() << endl;
    }
    return i > 1 ? i * fact( i - 1 ) : 1;
}

int main()
{
    std::cout << std::boolalpha << (120 == fact(5)) << std::endl;
    return 0;
}
```

## Exercise 6.4

```cpp
#include <iostream>
#include <string>

int fact(int i)
{
    return i > 1 ? i * fact(i - 1) : 1;
}

void interactive_fact()
{
    std::string const prompt = "Enter a number within [1, 13) :\n";
    std::string const out_of_range = "Out of range, please try again.\n";
    for (int i; std::cout << prompt, std::cin >> i; )
    {
        if (i < 1 || i > 12)
        {
            std::cout << out_of_range; 
            continue;
        }
        std::cout << fact(i) << std::endl;
    }
}

int main()
{
    interactive_fact();
    return 0;
}
```

## Exercise 6.5

```cpp
#include <iostream>

int abs(int i)
{
    return i > 0 ? i : -i;
}

int main()
{
    std::cout << abs(-5) << std::endl;
    return 0;
}
```

## Exercise 6.6


**local variable**: Variables defined inside a **block**;

**parameter**: **Local variables** declared inside the **function parameter list**

**local static variable**: **local static variable（object）** is initialized before the first time execution passes through the object’s definition.**Local statics** are not destroyed when a function ends; they are **destroyed when the program terminates.**

```cpp
// example
size_t count_add(int n)       // n is a parameter.
{
    static size_t ctr = 0;    // ctr is a static variable.
    ctr += n;
    return ctr;
}

int main()
{
    for (size_t i = 0; i != 10; ++i)  // i is a local variable.
      cout << count_add(i) << endl;

    return 0;
}
```

## Exercise 6.7

```cpp
size_t generate()
{
    static size_t ctr = 0;
    return ctr++;
}
```

## [Exercise 6.8](Chapter6.h)
## Exercise 6.9 [fact.cc](fact.cc) | [factMain.cc](factMain.cc)
## [Exercise 6.10](ex6_10.cpp)
## [Exercise 6.11](ex6_11.cpp)
## [Exercise 6.12](ex6_12.cpp)
## Exercise 6.13

`void f(T)` pass the argument by value. **nothing the function does to the parameter can affect the argument**.
`void f(T&)` pass a reference, will be **bound to** whatever T object we pass.

## Exercise 6.14

a parameter should be a reference type:
```cpp
void reset(int &i)
{
        i = 0;
}
```

a parameter should not be a reference:
```cpp
void print(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
        for (std::vector<int>::iterator iter = begin; iter != end; ++iter)
                std::cout << *iter << std::endl;
}
```

## Exercise 6.15

>why is `s` a reference to const but `occurs` is a plain reference?

Because `s` should not be changed by this function, but `occurs` result must be calculated by the function.

>Why are these parameters references, but the char parameter `c` is not?

Because `c` may be a temp varable, such as `find_char(s, 'a', occurs)`

>What would happen if we made `s` a plain reference? What if we made `occurs` a reference to const?

`s` could be changed in the function, and `occurs` would not be changed. so `occurs = 0;` is an error.

## Exercise 6.16
```cpp
bool is_empty(const string& s) { return s.empty(); }
```

Since this function doesn't change the argument, "const" shoud be added
before string&s, otherwise this function is misleading and can't be used
with const string or in a const function.

## [Exercise 6.17](ex6_17.cpp)

Not the same.
For the first one "const" was used, since no change need to do for the argument.
For the second function, "const" can't be used, because the content of the agument
should be changed.

## Exercise 6.18
(a)
```cpp
bool compare(matrix &m1, matrix &m2);
```
(b)
```cpp
vector<int>::iterator change_val(int, vector<int>::iterator);
```

## Exercise 6.19

(a) illegal, only one parameter.
(b) legal.
(c) legal.
(d) legal.

## Exercise 6.20

If we can use `const`, just use it. If we make a parameter a plain reference when it could be a reference to `const`,
the reference value maybe changed.

## [Exercise 6.21](ex6_21.cpp)
## [Exercise 6.22](ex6_22.cpp)
## [Exercise 6.23](ex6_23.cpp)

## Exercise 6.24

>Arrays have two special properties that affect how we define and use functions that operate on arrays: We cannot copy an array, and when we use an array it is (usually) **converted to a pointer**.

So we cannot pass an array by value, and when we pass an array to a function, we are actually passing a pointer
to the array's first element.

In this question, `const int ia[10]` is actually same as `const int*`, and the size of the array is **irrelevant**.
we can pass `const int ia[3]` or `const int ia[255]`, there are no differences. If we want to pass an array which size is ten, we should use reference like that:
```cpp
void print10(const int (&ia)[10]) { /*...*/ }
```

see more discusses at http://stackoverflow.com/questions/26530659/confused-about-array-parameters

## [Exercise 6.25 && Exercise 6.26](ex6_25_26.cpp)
## [Exercise 6.27](ex6_27.cpp)

## Exercise 6.28

The type of `elem` in the `for` loop is `const std::string&`.

## Exercise 6.29

Depends on the type of elements of `initializer_list`. When the type is [PODType](http://en.cppreference.com/w/cpp/concept/PODType), reference is unnecessary. Because `POD` is **cheap to copy**(such as `int`). Otherwise, Using reference(`const`) is the better choice.

## Exercise 6.30

Error (Clang):
>Non-void function 'str_subrange' should return a value. // error #1

>Control may reach end of non-void function. // error #2

## Exercise 6.31

when you can find the preexited object that the reference refered.

## Exercise 6.32

legal, it gave the values (0 ~ 9) to array `ia`.

## [Exercise 6.33](ex6_33.cpp)([Generics Version](ex6_33_generics_version.cpp))
## Exercise 6.34

When the recursion termination condition becomes `var != 0`, two situations can happen :
* case 1 : If the argument is positive, recursion stops at 0.(Note : There is one extra multiplication step though as the combined expression for factorial(5) reads 5 * 4 * 3 * 2 * 1 * 1. In terms of programming languages learning, such subtle difference probably looks quite trivial. In algorithms analysis and proof, however, this extra step may be super important.)
* case 2 : if the argument is negative, recursion would never stop. As a result, a stack overflow would occur.

## Exercise 6.35

the recursive function will always use `val` as the parameter. *a recursion loop* would happen.

## Exercise 6.36

```cpp
string (&func(string (&arrStr)[10]))[10]
```

## Exercise 6.37

```cpp
using ArrT = string[10];
ArrT& func1(ArrT& arr);

auto func2(ArrT& arr) -> string(&)[10];

string arrS[10];
decltype(arrS)& func3(ArrT& arr);
```

I pefer the first one. because it is more simpler to me.

## Exercise 6.38
```cpp
decltype(arrStr)& arrPtr(int i)
{
          return (i % 2) ? odd : even;
}
```

## Exercise 6.39

(a) illegal

(b) illegal

(c) legal

## Exercise 6.40

(a) no error

(b) Missing default argument on parameter 'wd', 'bckgrnd'.

## Exercise 6.41

(a) illegal. No matching function for call to 'init'.

(b) legal, and match.

(c) legal, but not match. `wd` whould be setting to '*'.

## [Exercise 6.42](ex6_42.cpp)
## Exercise 6.43

Both two should put in a header. (a) is an inline function. (b) is the declaration of useful function. we always put them in the header.

## [Exercise 6.44](ex6_44.cpp)
## Exercise 6.45

For example, the function `arrPtr` in [Exercise 6.38](# Exercise-638) and `make_plural` in [Exercise 6.42](# Exercise-642) should be defined as `inline`. But the function `func` in [Exercise 6.4](# Exercise-64) shouldn't. It is not that small and it's only being called once. Hence, it will probably not expand as inline.

## Exercise 6.46
> Would it be possible to define `isShorter` as a `constexpr`? If so, do so. If not, explain why not.

No.

Because `std::string::size()` is not a `constexpr` function and `s1.size() == s2.size()` is not a constant expression.

> **For a** non-template, non-defaulted **constexpr function** or a non-template, non-defaulted, non-inheriting
constexpr constructor, **if no argument values exist such that an invocation of the function or constructor
could be an evaluated subexpression of a core constant expression (5.19), the program is ill-formed;** no
diagnostic required. (N3690 §7.1.5 [dcl.constexpr]/5)

## [Exercise 6.47](ex6_47.cpp)
## Exercise 6.48

This loop let user input a word all the way until the word is sought.

It isn't a good use of assert. because if user begin to input a word, the `cin` would be always have content. so the `assert` would be always `true`. It is meaningless. using `assert(s == sought)` is better.

## Exercise 6.49

candidate function:
>Set of functions that are considered when resolving a function call. (all the functions
with the name used in the call for which a declaration is in scope at the time of the call.)

viable function:
>Subset of the candidate functions that could match a given call.
>It have the same number of parameters as arguments to the call,
and each argument type can be converted to the corresponding parameter type.

## Exercise 6.50

(a) illegal. 2.56 match the `double`, but 42 match the `int`.

(b) match `void f(int)`.

(c) match `void f(int, int)`.

(d) match `void f(double, double = 3.14)`.

## [Exercise 6.51](ex6_51.cpp)
## Exercise 6.52

(a) Match through a promotion

(b) Arithmetic type conversion

## Exercise 6.53

(a)
```cpp
int calc(int&, int&); // calls lookup(int&)
int calc(const int&, const int&); // calls lookup(const int&)
```
(b)
```cpp
int calc(char*, char*); // calls lookup(char*)
int calc(const char*, const char*); calls lookup(const char *)
```
(c)

illegal. both calls lookup(char*)

## Exercise 6.54
```cpp
int func(int a, int b);

using pFunc1 = decltype(func) *;
typedef decltype(func) *pFunc2;
using pFunc3 = int (*)(int a, int b);
using pFunc4 = int(int a, int b);
typedef int(*pFunc5)(int a, int b);
using pFunc6 = decltype(func);

std::vector<pFunc1> vec1;
std::vector<pFunc2> vec2;
std::vector<pFunc3> vec3;
std::vector<pFunc4*> vec4;
std::vector<pFunc5> vec5;
std::vector<pFunc6*> vec6;
```

## Exercise 6.55
```cpp
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }
```

## Exercise 6.56
```cpp
std::vector<decltype(func) *> vec{ add, subtract, multiply, divide };
for (auto f : vec)
          std::cout << f(2, 2) << std::endl;
```

----

see @Mooophy 's [complete codes](ex6_54_55_56.cpp).
