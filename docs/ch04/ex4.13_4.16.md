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
