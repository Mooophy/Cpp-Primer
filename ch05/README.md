##Exercise 5.1
>What is a null statement? When might you use a null statement?

null statement is the empty statement. like this:
```cpp
; // null statement
```

I might use a null statement when the **language requires a statement but the program's logic does not. For example:
```cpp
// read until we hit end-of-file or find an input equal to sought
while (cin >> s && s != sought)
    ; // null statement.
```

##Exercise 5.2
>What is a block? When might you might use a block?

block is a (possiby empty) sequence of statements and declarations surrounded by a pair of curly braces.

I might use a block when the language requires a single statement but the logic of our program needs more than one. For example:
```cpp
while (val <= 10)
{
    sum += val;
    ++val;
}
```

##Exercise 5.3
>Use the comma operator (§ 4.10, p. 157) to rewrite the while loop from § 1.4.1 (p. 11)
so that it no longer requires a block. 
Explain whether this rewrite improves or diminishes the readability of this code.

```cpp
#include <iostream>
int main()
{
    int sum = 0, val = 1;
    while (val <= 10)
        sum += val, ++val;
    std::cout << "Sum of 1 to 10 inclusive is " 
              << sum << std::endl;
    
    return 0;
}
```

This rewrite diminishes the readability of the code. The comma operator always guarantees the order and discards the front result.
But there are no meaning in this example, however, also are incomprehensible.

##Exercise 5.4
>Explain each of the following examples, and correct anyproblems you detect.
- (a) while (string::iterator iter != s.end()) { /* . . . */ } 
- (b) while (bool status = find(word)) { /* . . . */ }
if (!status) { /* . . . */ }

(a) iter point at nothing. invalid.
```cpp
std::string::iterator iter = s.begin();
    while (iter != s.end()) { /* . . . */ }
```

(b) The if statement is not in the while's block. so the `status` is invalid. And if status is true, go through the `while` block forever, else go through the `if` block.
```cpp
if (!find(word)) { /* . . . */ }
else while (true) { /* . . . */ }
```

##[Exercise 5.5](ex5_5.cpp)
##[Exercise 5.6](ex5_6.cpp)
##Exercise 5.7
>Correct the errors in each of the following code fragments:
```cpp
(a) if (ival1 != ival2) ival1 = ival2
    else ival1 = ival2 = 0;
(b) if (ival < minval) minval = ival;
    occurs = 1;
(c) if (int ival = get_value())
    cout << "ival = " << ival << endl;
    if (!ival)
    cout << "ival = 0\n";
(d) if (ival = 0)
    ival = get_value();
```

```cpp
(a) if (ival1 != ival2) ival1 = ival2; // lost semicolon.
    else ival1 = ival2 = 0;
(b) if (ival < minval)
    {
        minval = ival;
        occurs = 1;
    }
(c) if (int ival = get_value())
        cout << "ival = " << ival << endl;
    else if (!ival)
        cout << "ival = 0\n";
(d) if (ival == 0)
    ival = get_value();
```

Exercise 5.8
>What is a “dangling else”? How are else clauses resolved in C++?

Colloquial term used to refer to the problem of how to process nested if statements in which there are more ifs than elses. In C++, an else is always paired with the closest preceding unmatched if.
