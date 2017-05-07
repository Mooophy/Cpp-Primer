## Exercise 1.1

> Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the main program from page 2.

 * [GCC and File Extensions](http://labor-liber.org/en/gnu-linux/development/extensions) 
 * [File Types Created for Visual C++ Projects](https://msdn.microsoft.com/en-us/library/3awe4781.aspx)

## Exercise 1.2

> Exercise 1.2: Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed. Recompile and rerun your program to see how your system treats a failure indicator from main.

### Windows

![windows](https://db.tt/DIJd9eZb)

### Linux

![linux](https://db.tt/lhzXhpCt)

**255**? why? please look at [this](http://www.tldp.org/LDP/abs/html/exitcodes.html)

## Exercise 1.3
> Write a program to print Hello, World on the standard output.

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, World" << std::endl;
    return 0;
}
```

## Exercise 1.4
> Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, *, to print the product instead.

```cpp
#include <iostream>

int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product is " << v1 * v2 << std::endl;

    return 0;
}
```

## Exercise 1.5

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

## Exercise 1.6
> Explain whether the following program fragment is legal.

It's illegal.

**[Error] expected primary-expression before '<<' token**

Fixed it: remove the spare semicolons.

```cpp
std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
```

## Exercise 1.7

> Compile a program that has incorrectly nested comments.

Example:
```cpp
/*
* comment pairs /* */ cannot nest.
* ''cannot nest'' is considered source code,
* as is the rest of the program
*/
int main()
{
    return 0;
}
```

Compiled result(g++):

![result](https://db.tt/CqQKu8GQ)

## Exercise 1.8

> Indicate which, if any, of the following output statements are legal:
```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```
> After you’ve predicted what will happen, test your answers by compiling a
program with each of these statements. Correct any errors you encounter.

Compiled result(g++):

![result](https://db.tt/mrL9hDCS)

Corrected? just added a quote:
```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */";
std::cout << /* "*/" /* "/*" */;
```

Output:

    /**/ */ /*

## [Exercise 1.9](ex1_9.cpp)
## [Exercise 1.10](ex1_10.cpp)
## [Exercise 1.11](ex1_11.cpp)

## Exercise 1.12
> What does the following for loop do? What is the final value
of sum?
```cpp
int sum = 0;
for (int i = -100; i <= 100; ++i)
sum += i;
```

the loop sums the numbers from -100 to 100. the final value of sum is zero.

## Exercise 1.13
> Rewrite the exercises from § 1.4.1 (p. 13) using for loops.

Ex1.9:
```cpp
#include <iostream>

int main()
{
    int sum = 0;
    for (int i = 50; i <= 100; ++i) sum += i;
    std::cout << "the sum is: " << sum << std::endl;

    return 0;
}
```

Ex1.10:
```cpp
#include <iostream>

int main()
{
    for (int i = 10; i >= 0; --i)
        std::cout << i << std::endl;
    return 0;
}
```

Ex1.11:
```cpp
#include <iostream>

int main()
{
    std::cout << "please input two integers:\n";
    int small = 0, big = 0;
    std::cin >> small >> big;

    if (small > big)
    {
        int tmp = small;
        small = big;
        big = tmp;
    }

    for (int i = small; i != big; ++i)
        std::cout << i << std::endl;

    return 0;
}
```

## Exercise 1.14
> Compare and contrast the loops that used a for with those
using a while. Are there advantages or disadvantages to using either form?

[A similar question on Stack Overflow](http://stackoverflow.com/questions/2950931/for-vs-while-in-c-programming)

## Exercise 1.15
> Write programs that contain the common errors discussed in
the box on page 16. Familiarize yourself with the messages the compiler
generates.

Nothing to present here.

## Exercise 1.16

```cpp
#include <iostream>
int main()
{
    int sum = 0;
    for (int val; std::cin >> val; sum += val);
    std::cout << sum << std::endl;

    return 0;
}
```

## Exercise 1.17

> What happens in the program presented in this section if the input values are all equal? What if there are no duplicated values?

If the input values are all equal, it will print a line which shows the count of the number you input.

If there are no duplicated values, when different values input, a new line will be printed if you click `Enter`.

## Exercise 1.18

> Compile and run the program from this section giving it only equal values as input. Run it again giving it values in which no number is repeated.

![run](https://db.tt/F38zExnq)

## Exercise 1.19

> Revise the program you wrote for the exercises in § 1.4.1 (p. 13) that printed a range of numbers so that it handles input in which the first number is smaller than the second.

[code](https://github.com/pezy/Cpp-Primer/blob/master/ch01/ex1_11.cpp)

## Exercise 1.20

> http://www.informit.com/title/032174113 contains a copy of Sales_item.h in the Chapter 1 code directory. Copy that file to your working directory. Use it to write a program that reads a set of book sales transactions, writing each transaction to the standard output.

[Here](ex1_20.cpp) is the code.

Note : C++11 flag need to enable.
For GCC and Clang, this can be done with the `-std=c++11`

## Exercise 1.21
> Write a program that reads two Sales_item objects that have the same ISBN and produces their sum.

The program should check whether the objects have the same ISBN.

[Code](ex1_21.cpp)

## Exercise 1.22

> Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions that were read.

Tips: this program will appear in the section 1.6.

[Here](ex1_22.cpp) is the code.

![run](https://db.tt/UlkuvpAS)

## Exercise 1.23
> Write a program that reads several transactions and counts
how many transactions occur for each ISBN.

Tip: please review the `1.4.4`.

[Here](ex1_23.cpp) is the code.

## Exercise 1.24
> Test the previous program by giving multiple transactions
representing multiple ISBNs. The records for each ISBN should be grouped
together.

`data/book.txt` may be used as the records.

![run](https://db.tt/EeDI7lvN)

## Exercise 1.25
> Using the Sales_item.h header from the Web site,
compile and execute the bookstore program presented in this section.

It is the same as Exercise 1.22.

![run](https://db.tt/C6OOPuzA)
