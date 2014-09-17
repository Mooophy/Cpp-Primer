##Exercise 4.4
>Parenthesize the following expression to show how it is evaluated.
Test your answer by compiling the expression (without parentheses)
and printing its result.
```cpp
12 / 3 * 4 + 5 * 15 + 24 % 4 / 2
// parenthesize
((12/3)*4) + (5*15) + ((24%4)/2)
// 16 + 75 + 0 = 91
// print: 91
```

##Exercise 4.5
>Determine the result of the following expressions.
```cpp
-30 * 3 + 21 / 5  // -90+4 = -86
-30 + 3 * 21 / 5  // -30+63/5 = -30+12 = -18
30 / 3 * 21 % 5   // 10*21%5 = 210%5 = 0
-30 / 3 * 21 % 4  // -10*21%4 = -210%4 = -2
```

##Exercise 4.6
>Write an expression to determine whether an int value is even or odd.

```cpp
i%2 == 0 ? "even" : "odd"
```

##Exercise 4.7
>What does overflow mean? Show three expressions that will overflow.

```cpp
short svalue = 32767; ++svalue; // -32768
unsigned uivalue = 0; --uivalue;  // 4294967295
unsigned short usvalue = 65535; ++usvalue;  // 0
```
