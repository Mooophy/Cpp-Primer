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
