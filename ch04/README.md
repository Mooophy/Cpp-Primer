##Exercise 4.1
>What is the value returned by 5 + 10 * 20/2?

105

##Exercise 4.2
>Using Table 4.12 (p. 166), parenthesize the following expressions to
indicate the order in which the operands are grouped:
```cpp
* vec.begin() //=> *(vec.begin())
* vec.begin() + 1 //=> (*(vec.begin())) + 1
```

##Exercise 4.3
>Order of evaluation for most of the binary operators is left
undefined to give the compiler opportunities for optimization.
This strategy presents a trade-off between efficient code generation
and potential pitfalls in the use of the language by the programmer.
Do you consider that an acceptable trade-off? Why or why not?

Yes, I think it necessary to hold the trade-off.
Because the speed always the biggest advantage of C++. Sometimes, we need
the compiler's features for efficient work. But if you are not a expert. I
have to advice you do not touch the undefined behaviors.

For an instance, `cout << i << ++i <<endl` should never appear in your code.

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

##Exercise 4.8
>Explain when operands are evaluated in the logical AND,
logical OR, and equality operators.

logical `AND` : `true` only if both its operands evaluated to `true`;
logical `OR`  : `true` if either of its operands evaluated to `true`;
equality operators : `true` only if its operands are equal.

##Exercise 4.9
>Explain the behavior of the condition in the following if:
```cpp
const char *cp = "Hello World";
if (cp && *cp)
```

cp is a pointer to `const char *`, and it's not a nullptr. true.

`*cp` is a const char: 'H', and it is explicit a nonzero value. true.

true && true = true.

##Exercise 4.10
>Write the condition for a while loop that would read ints from
the standard input and stop when the value read is equal to 42.

```cpp
int i = 0;
while(cin >> i && i != 42)
```

##Exercise 4.11
>Write an expression that tests four values, a, b, c, and d,
and ensures that a is greater than b, which is greater than c,
which is greater than d.

```cpp
a>b && b>c && c>d
```

##Exercise 4.12
>Assuming i, j, and k are all ints, explain what i != j < k means.

if `j<k` is true, means `i != 1`, else means `i != 0`.

##Exercise 4.13
>What are the values of i and d after each assignment?
```cpp
int i;   double d;
d = i = 3.5; // i = 3, d = 3.0
i = d = 3.5; // d = 3.5, i = 3
```

##Exercise 4.14
>Explain what happens in each of the if tests:
```cpp
if (42 = i)   // complie error: expression is not assignable
if (i = 42)   // true.
```

##Exercise 4.15
>The following assignment is illegal. Why? How would you correct it?
```cpp
double dval; int ival; int *pi;
dval = ival = pi = 0;
// pi is a pointer to int.
// can not assign to 'int' from type 'int *'
// correct it:
dval = ival = 0;
pi = &ival;
```

##Exercise 4.16
>Although the following are legal,
they probably do not behave as the programmer expects. Why?
Rewrite the expressions as you think they should be.
```cpp
if (p = getPtr() != 0)
if (i = 1024)
// why? always true. use an assigment as a condition.
// correct it
if ((p=getPtr()) != 0)
if (i == 1024)
```

##Exercise 4.17
>Explain the difference between prefix and postfix increment.

The postfix operators increment(or decrement) the operand but yield a copy
of the original, unchanged value as its result.

The prefix operators return the object itself as an **lvalue**.

The postfix operators return a copy of the object's original value as an **rvalue**.

##Exercise 4.18
>What would happen if the while loop on page 148 that prints
the elements from a vector used the prefix increment operator?

It will print from the second element and will dereference the v.end() at last.(It's undefined and very dangerous)

##Exercise 4.19
>Given that ptr points to an int, that vec is a vector<int>,
and that ival is an int, explain the behavior of each of these expressions.
Which, if any, are likely to be incorrect? Why? How might each be corrected?
```cpp
ptr != 0 && *ptr++  // check ptr is not a nullptr. and check the pointer value.
ival++ && ival // check ival and ival+1 whether equal zero.
vec[ival++] <= vec[ival] // incorrect. It is an **undefined behavior.**
// correct:
vec[ival] <= vec[ival+1]
```

##Exercise 4.20
>Assuming that iter is a vector<string>::iterator,
indicate which, if any, of the following expressions are legal.
Explain the behavior of the legal expressions and
why those that aren’t legal are in error.
```cpp
*iter++;  // return *iter, then ++iter.
(*iter)++;  // illegal, *iter is a string, cannot increment value.
*iter.empty() // illegal, iter should use '->' to indicate whether empty.
iter->empty();  // indicate the iter' value whether empty.
++*iter;        // illegal, string have not increment.
iter++->empty();  // return iter->empty(), then ++iter.
```

##[Exercise 4.21](ex4_21.cpp)
##[Exercise 4.22](ex4_22.cpp)
##Exercise 4.23
>The following expression fails to compile due to operator precedence.
Using Table 4.12 (p. 166), explain why it fails. How would you fix it?
```cpp
string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
```

Operator Precedence: `?:` < `+`
Fix it:
```cpp
string pl = s + (s[s.size() - 1] == 's' ? "" : "s") ;
```

##Exercise 4.24
>Our program that distinguished between high pass, pass,
and fail depended on the fact that
the conditional operator is right associative.
Describe how that operator would be evaluated
if the operator were left associative.

if the operator were left associative.
```cpp
finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
```
would same as :
```cpp
finalgrade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass";
```
if `grade > 90`, first conditional operator's result is `high pass`. so the finalgrade is always fail.
It's contradictory obviously.

##Exercise 4.25
>What is the value of ~'q' << 6 on a machine with 32-bit ints and 8 bit chars, that uses Latin-1 character set in which 'q' has the bit pattern 01110001?

the value is `-7296.`

~01110001 == 10001110(142), But `char` is -128~127, so it would be overflow. the result is `-114`, then, -114 << 6 == -114 * 2^6 = `-7296`.

##Exercise 4.26
>In our grading example in this section, what would happen if we used unsigned int as the type for quiz1?

no different in most situation. `unsigned int` have the same size as `unsigned long` on most machine. But the second one could make sure that it have **at least 32 bits** on any machine.

##Exercise 4.27
>What is the result of each of these expressions? 
```cpp
unsigned long ul1 = 3, ul2 = 7; 
ul1 & ul2 // == 3
ul1 | ul2 // == 7
ul1 && ul2 // == true
ul1 || ul2 // == ture
```
