##Exercise 2.3
> What output will the following code produce?
```cpp
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```

Output(g++ 4.8):

```
32
4294967264
32
-32
0
0
```

##Exercise 2.4
> Write a program to check whether your predictions were
correct. If not, study this section until you understand what the problem is.

[Here](https://github.com/pezy/Cpp-Primer/blob/master/ch02/ex2_4.cpp) is the code, please test it in your computer.

##Exercise 2.5
> Determine the type of each of the following literals. Explain
the differences among the literals in each of the four examples:
- (a) 'a', L'a', "a", L"a"
- (b) 10, 10u, 10L, 10uL, 012, 0xC
- (c) 3.14, 3.14f, 3.14L
- (d) 10, 10u, 10., 10e-2

(a): character literal, wide character literal, string literal, string wide character literal.

(b): decimal, unsigned decimal, long decimal, unsigned long decimal, octal, hexadecimal.

(c): double, float, long double.

##Exercise 2.6
> What, if any, are the differences between the following
definitions:
```cpp
int month = 9, day = 7;
int month = 09, day = 07;
```

The first line's integer is decimal, the second line's integer is octal.

##Exercise 2.7
> What values do these literals represent? What type does each
have?
- (a) "Who goes with F\145rgus?\012"
- (b) 3.14e1L
- (c) 1024f
- (d) 3.14L

(a): Who goes with Fergus?(new line) "string"

(b): 31.4 "long double"

(c): 1024 "float"

(d): 3.14 "long double"

Reference:

- [ASCII Table](http://www.asciitable.com/)

##Exercise 2.8
> Using escape sequences, write a program to print 2M followed
by a newline. Modify the program to print 2, then a tab, then an M, followed
by a newline.

```cpp
#include <iostream>

int main()
{
  std::cout << 2 << "\115\012";
  std::cout << 2 << "\t\115\012";

  return 0;
}

```
