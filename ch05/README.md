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
