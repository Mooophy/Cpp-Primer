##Exercise 1.3
> Write a program to print Hello, World on the standard output.

```cpp
#include <iostream>

int main()
{
  std::cout << "Hello, World" << endl;
  return 0;
}
```

##Exercise 1.4
> Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, *, to print the product instead.

```cpp
#include <iostream>

int main()
{
  std::cout << "Enter two numbers:" << std::endl;
  int v1 = 0, v2 = 0;
  std::cin >> v1 >> v2;
  std::cout << "The product of " << v1 << " and " << v2
  << " is " << v1 * v2 << std::endl;
  return 0;
}
```

##Exercise 1.5

> We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.

```cpp
#include <iostream>

int main()
{
  std::cout << "Enter two numbers:" << std::endl;
  int v1 = 0, v2 = 0;
  std::cin >> v1 >> v2;
  std::cout << "The product of ";
  std::cout << v1;
  std::cout << " and ";
  std::cout << v2;
  std::cout << " is ";
  std::cout << v1 * v2;
  std::cout << std::endl;
  return 0;
}
```

##Exercise 1.6
> Explain whether the following program fragment is legal.

It's illegal.

**[Error] expected primary-expression before '<<' token**

Fixed it: remove the spare semicolons.

```cpp
std::cout << "The sum of " << v1
          << " and " << v2
          << " is " << v1 + v2 << std::endl;
```
