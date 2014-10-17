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
