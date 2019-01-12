Chapter 1. Getting Started
==========================

## Exercise 1.1
> Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the `main` program from page 2.
 * [GCC and File Extensions](http://labor-liber.org/en/gnu-linux/development/index.php?diapo=extensions) 
 * [File Types Created for Visual C++ Projects](https://msdn.microsoft.com/en-us/library/3awe4781.aspx)

## Exercise 1.2
> Change the program to return `-1`. A return value of `-1` is often treated as an indicator that the program failed. Recompile and rerun your program to see how your system treats a failure indicator from main.

After you running the `main` program that return `-1`, you will see a failure indicator from different system in the following.
* Windows.
```cmd
$ echo %ERRORLEVEL%
-1
```
* Unix/Linux.
```bash
$ echo $?
255
```
why `255`? please see [here](http://www.tldp.org/LDP/abs/html/exitcodes.html).

## Exercise 1.3
> Write a program to print `Hello, World` on the standard output.
```c++
#include <iostream>

int main() {
    std::cout << "Hello, World" << std::endl;
    return 0;
}
```

## Exercise 1.4
> Our program used the addition operator, `+`, to add two numbers. Write a program that uses the multiplication operator, `*`, to print the product instead.
```c++
#include <iostream>

int main() {
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product is " << v1 * v2 << std::endl;

    return 0;
}
```

## Exercise 1.5
> We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.
```c++
#include <iostream>

int main() {
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
> Explain whether the following program fragment is legal. If the program is legal, what does it do? If the program is not legal, why not? How would you fix it?
```c++
std::cout << "The sum of " << v1;
          << " and " << v2;
          << " is "  << v1 + v2 << std::endl;
```

It's illegal. Error: expected primary-expression before '<<' token.

Fixed it: remove the spare semicolons.
```c++
std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
```

## Exercise 1.7
> Compile a program that has incorrectly nested comments.

Example:
```c++
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

## Exercise 1.8
> Indicate which, if any, of the following output statements are legal:
```c++
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```
> After you’ve predicted what will happen, test your answers by compiling a
program with each of these statements. Correct any errors you encounter.

Correct it. just added a quote:
```c++
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */";
std::cout << /* "*/" /* "/*" */;
```
Output:
```bash
/**/ */ /* 
```

## Exercise 1.9
> Write a program that uses a `while` to sum the numbers from 50 to 100.
```c++
#include <iostream>

int main() {
    int sum = 0, lo = 50, hi = 100;
    while (lo <= hi) sum += lo++;
    std::cout << "Sum of 50 to 100 inclusive is: " << sum << std::endl;
    return 0;
}
```

## Exercise 1.10
> In addition to the `++` operator that adds `1` to its operand, there is a decrement operator (`--`) that subtracts `1`. Use the decrement operator to write a `while` that prints the numbers from ten down to zero.
```c++
#include <iostream>

int main() {
    int i = 10;
    while (i >= 0)
        std::cout << i-- << std::endl;
    return 0;
}
```

## Exercise 1.11
> Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.
```c++
#include <iostream>

int main() {
    int low = 0, high = 0;
    std::cout << "Please input two integers:\n";
    std::cin >> low >> high;
    while (low < high)
        std::cout << low++ << std::endl;
    return 0;
}
```

## Exercise 1.12
> What does the following `for` loop do? What is the final value of `sum`?
```c++
int sum = 0;
for (int i = -100; i <= 100; ++i)
    sum += i;
```
The loop sums the numbers from -100 to 100. the final value of sum is 0.

## Exercise 1.13
> Rewrite the exercises from § 1.4.1 (p. 13) using `for` loops.
* Rewrite [Exercise 1.9](#exercise-19).
```c++
#include <iostream>

int main() {
    int sum = 0;
    for (int i = 50; i <= 100; ++i)
        sum += i;
    std::cout << "Sum of 50 to 100 inclusive is: " << sum << std::endl;
    return 0;
}
```
* Rewrite [Exercise 1.10](#exercise-110).
```c++
#include <iostream>

int main() {
    for (int i = 10; i >= 0; --i)
        std::cout << i << std::endl;
    return 0;
}
```
* Rewrite [Exercise 1.11](#exercise-111).
```c++
#include <iostream>

int main() {
    int low = 0, high = 0;
    std::cout << "Please input two integers:\n";
    std::cin >> low >> high;
    for (int i = low; i < high; ++i)
        std::cout << i << std::endl;
    return 0;
}
```

## Exercise 1.14
> Compare and contrast the loops that used a `for` with those using a `while`. Are there advantages or disadvantages to using either form?

[A similar question on Stack Overflow.](http://stackoverflow.com/questions/2950931/for-vs-while-in-c-programming)
    
> The main difference between the `for`'s and the `while`'s is a matter of pragmatics: we usually use `for` when there is a known number of iterations, and use `while` constructs when the number of iterations in not known in advance. The `while` vs `do ... while` issue is also of pragmatics, the second executes the instructions once at start, and afterwards it behaves just like the simple while.

## Exercise 1.15
> Write programs that contain the common errors discussed in the box on page 16. Familiarize yourself with the messages the compiler generates.

**Syntax Errors**:
```c++
int main() {
    std::cout << "Hello World!" << std::endl // semicolon missed 
    return 0;
}
```

**Type errors**:
```c++
int main() {
    char s = "Hello World!";                 // Here char should be std::string
    std::cout << s << std::endl;
    return 0;
}
```

**Declaration errors**:
```c++
int main() {
    int k = 0;
    std::cout << K << std::endl;             // use of undeclared identifier 'K'
    return 0;
}
```

## Exercise 1.16
> Write your own version of a program that prints the sum of a set of integers read from `cin`.
```c++
#include <iostream>

int main() {
    int sum = 0;
    for (int val; std::cin >> val; sum += val);
    std::cout << sum << std::endl;
    return 0;
}
```

## Exercise 1.17
> What happens in the program presented in this section if the input values are all equal? What if there are no duplicated values?
* If the input values are all equal, it will print a line which shows the count of the number you input.
* If there are no duplicated values, when different values input, a new line will be printed if you click `Enter`.

## Exercise 1.18
> Compile and run the program from this section giving it only equal values as input. Run it again giving it values in which no number is repeated.
```c++
#include <iostream>
int main() {
    // currVal is the number we're counting; we'll read new values into val
    int currVal = 0, val = 0;
    // read first number and ensure that we have data to process
    if (std::cin >> currVal) {
        int cnt = 1; // store the count for the current value we're processing
        while (std::cin >> val) {
            if (val == currVal)
                ++cnt;
            else { // otherwise, print the count for the previous value
                std::cout << currVal << " occurs "
                          << cnt << " times" << std::endl;
                currVal = val; // remember the new value
                cnt = 1;       // reset the counter
            }
        }   // while loop ends here
        // remember to print the count for the last value in the file
        std::cout << currVal << " occurs "
                  << cnt << " times" << std::endl;
    } // outermost if statement ends here
    return 0;
}
```

## Exercise 1.19
> Revise the program you wrote for [Exercise 1.11](#exercise-111) in § 1.4.1 (p. 13) that printed a range of numbers so that it handles input in which the first number is smaller than the second.
```c++
#include <iostream>

void print_range(int lo, int hi) {
    if (lo > hi) {
        print_range(hi, lo);
        return ;
    }
    while (lo != hi)
        std::cout << lo++ << std::endl;
}

int main() {
    int low = 0, high = 0;
    std::cout << "Please input two integers:\n";
    std::cin >> low >> high;
    print_range(low, high);
    return 0;
}
```

## Exercise 1.20
> [http://www.informit.com/title/032174113](http://www.informit.com/title/032174113) contains a copy of `Sales_item.h` in the Chapter 1 code directory. Copy that file to your working directory. Use it to write a program that reads a set of book sales transactions, writing each transaction to the standard output.
```c++
#include <iostream>
#include "Sales_item.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    for (Sales_item item; cin >> item; cout << item << endl);
    return 0;
}
```
Note : C++11 flag need to enable.

## Exercise 1.21
> Write a program that reads two `Sales_item` objects that have the same `ISBN` and produces their sum.
```c++
#include <iostream>
#include "Sales_item.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main() {
    Sales_item item1, item2;
    cin >> item1 >> item2;
    if (item1.isbn() == item2.isbn())
        cout << item1 + item2 << endl;
    else
        cerr << "Different ISBN." << endl;
}
```

## Exercise 1.22
> Write a program that reads several transactions for the same `ISBN`. Write the sum of all the transactions that were read.
```c++
#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item total;
    if (std::cin >> total) {
        Sales_item trans;
        while (std::cin >> trans) {
            if (total.isbn() == trans.isbn())
                total += trans;
            else {
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }

    return 0;
}
```
Tips: this program will appear in the section 1.6.

## Exercise 1.23
> Write a program that reads several transactions and counts how many transactions occur for each `ISBN`.
```c++
#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item currItem, valItem;
    if (std::cin >> currItem) {
        int cnt = 1;
        while (std::cin >> valItem) {
            if (valItem.isbn() == currItem.isbn()) {
                ++cnt;
            } else {
                std::cout << currItem << " occurs " << cnt << " times " << std::endl;
                currItem = valItem;
                cnt = 1;
            }
        }
        std::cout << currItem << " occurs "<< cnt << " times " << std::endl;
    }
    return 0;
}
```
Tip: please review the `1.4.4`.

## Exercise 1.24
> Test the previous program by giving multiple transactions representing multiple `ISBN`s. The records for each `ISBN` should be grouped together.
* Test cases:
```
0-201-78345-X 3 20
0-201-78345-X 2 25
0-201-78346-X 1 100
0-201-78346-X 2 99.9
0-201-78346-X 6 89.9
```
Run program in [Exercise 1.22](#exercise-122) and [Exercise 1.23](#exercise-123).
## Exercise 1.25
> Using the `Sales_item.h` header from the Web site, compile and execute the bookstore program presented in this section.

It is the same as [Exercise 1.22](#exercise-122).
