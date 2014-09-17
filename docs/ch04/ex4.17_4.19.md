##Exercise 4.17
>Explain the difference between prefix and postfix increment.

The postfix operators increment(or decrement) the operand but yield a copy
of the original, unchanged value as its result.

The prefix operators return the object itself as an **lvalue**.

The postfix operators return a copy of the object's original value as an **rvalue**.

##Exercise 4.18
>What would happen if the while loop on page 148 that prints
the elements from a vector used the prefix increment operator?

It will print from the second element and will dereference the v.end() at last.

##Exercise 4.19
>Given that ptr points to an int, that vec is a vector<int>,
and that ival is an int, explain the behavior of each of these expressions.
Which, if any, are likely to be incorrect? Why? How might each be corrected?
```cpp
ptr != 0 && *ptr++  // check ptr is not a nullptr. and check the pointer value.
ival++ && ival // check ival and ival+1 whether equal zero.
vec[ival++] <= vec[ival] // incorrect. It is an **undefined behavior.**
// correct:
vec[ival+1] <= vec[ival]
```
