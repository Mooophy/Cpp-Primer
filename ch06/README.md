##Exercise 6.1

**Parameters**: Local variable declared inside the function parameter list. 
they are initialized by the **arguments** provided in the each function call.

**Arguments**: Values supplied in a function call that are used to initialize the function's **parameters**.

##Exercise 6.2

```cpp
(a) string f() {
          string s;
          // ...
          return s;
    }
(b) void f2(int i) { /* ... */ }
(c) int calc(int v1, int v2) { /* ... */ }
(d) double square (double x) { return x * x; }
```

##Exercise 6.3

```cpp
#include <iostream>

int fact(int val)
{
    if (val == 0 || val == 1) return 1;
    else return val * fact(val-1);
}

int main()
{
    int j = fact(5);  // j equals 120, i.e., the result of fact(5)    
    std::cout << "5! is " << j << std::endl; 
    return 0;
}
```

##Exercise 6.4

```cpp
int func()
{
    int n, ret = 1;
    std::cout << "input a number: ";
    std::cin >> n;
    while (n > 1) ret *= n--;
    return ret;
}

int main()
{
    std::cout << func() << std::endl; 
    return 0;
} 
```

##Exercise 6.5

```cpp
template <typename T> 
T abs(T i)
{
    return i >= 0 ? i : -i;
}
```

##Exercise 6.6


**local variable**: Variables defined inside a **block**;

**parameter**: **Local variables** declared inside the **function parameter list**

**local static variable**: **Local variable** whose value persists across calls to the function. 
The variable that are created and initialized **before** contorl reaches their use and are **destoryed when the program ends**.

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

cause the `s` should not be changed by this function. but `occurs`'s result must be calculated by the function.

>Why are these parameters references, but the char parameter `c` is not? 

casue `c` maybe a temp varable. such as `find_char(s, 'a', occurs)`

>What would happen if we made `s` a plain reference? What if we made `occurs` a reference to const?

`s` could be changed in the function, and `occurs` whould not be changed. so `occurs = 0;` is an error.

## Exercise 6.16
```cpp
bool is_empty(const string& s) { return s.empty(); }
```

Since this function doesn't change the argument,"const" shoud be added
before string&s,otherwise this function is misleading and can't be used
with const string or in a const function.

## [Exercise 6.17](ex6_17.cpp)

Not the same.
For the first one "const" was used, since no change need to do for the argument.
For the second function,"const" can't be used,because the content of the agument
should be changed.

## Exercise 6.18
(a)
```cpp
bool compare(matrix &m1, matrix &m2){ /.../ }
```
(b)
```cpp
vector<int>::iterator change_val(int, vector<int>::iterator) { /.../ }
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
## [Exercise 6.23](ex6.23.cpp)

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

The type of `elem` in the `for` loop is `std::string`.

## Exercise 6.29

We should use `const reference` as the loop control variable. because the elements in an `initializer_list` are always const values, so we cannot change the value of an element in an `initializer_list`.

## Exercise 6.30

Error (Clang):
>Non-void function 'str_subrange' should return a value. // error #1

>Control may reach end of non-void function. // error #2

## Exercise 6.31

when you can find the preexited object that the reference refered.

## Exercise 6.32

legal, it gave the values (0 ~ 9) to array `ia`.

##[Exercise 6.33](ex6_33.cpp)
## Exercise 6.34

nothing would happen. the function would be stoped when val is `2`.

## Exercise 6.35

the recursive function will always use `val` as the parameter. *a recursion loop* would happen.
