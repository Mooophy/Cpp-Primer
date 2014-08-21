##Exercise 2.26
>Which of the following are legal? For those that are illegal,
explain why.

```cpp
const int buf;      // illegal, buf is uninitialized const.
int cnt = 0;        // legal.
const int sz = cnt; // legal.
++cnt; ++sz;        // illegal, attempt to write to const object(sz).
```

##Exercise 2.27
> Which of the following initializations are legal? Explain why.

```cpp
int i = -1, &r = 0;         // illegal, r must refer to an object.
int *const p2 = &i2;        // legal.
const int i = -1, &r = 0;   // legal.
const int *const p3 = &i2;  // legal.
const int *p1 = &i2;        // legal
const int &const r2;        // illegal, r2 must initialize.
const int i2 = i, &r = i;   // legal.
```

##Exercise 2.28
>Explain the following definitions. Identify any that are illegal.

```cpp
int i, *const cp;       // illegal, cp must initialize.
int *p1, *const p2;     // illegal, p2 must initialize.
const int ic, &r = ic;  // illegal, ic must initialize.
const int *const p3;    // illegal, p3 must initialize.
const int *p;           // legal. a pointer to const int.
```

##Exercise 2.29
>Uing the variables in the previous exercise, which of the
following assignments are legal? Explain why.

```cpp
i = ic;     // legal.
p1 = p3;    // illegal. p3 is a pointer to const int.
p1 = &ic;   // illegal. ic is a const int.
p3 = &ic;   // legal.
p2 = p1;    // legal.
ic = *p3;   // illegal. ic is a const int.
```

##Exercise 2.30
>For each of the following declarations indicate whether the
object being declared has top-level or low-level const.
```cpp
const int v2 = 0; int v1 = v2;
int *p1 = &v1, &r1 = v1;
const int *p2 = &v2, *const p3 = &i, &r2 = v2;
```

v2 is top-level const, p2 is low-level const.
p3: right-most const is top-level, left-most is low-level.

Exercise 2.31
>Given the declarations in the previous exercise determine
whether the following assignments are legal. Explain how the top-level or
low-level const applies in each case.

```cpp
r1 = v2; // legal, top-level const in v2 is ignored.
p1 = p2; // illegal, p2 has a low-level const but p1 doesn't.
p2 = p1; // legal, we can convert int* to const int*.
p1 = p3; // illegal, p3 has a low-level const but p1 doesn't.
p2 = p3; // legal, p2 has the same low-level const qualification as p3.
```

##Exercise 2.32
>Is the following code legal or not? If not, how might you
make it legal?

    int null = 0, *p = null;

illegal.
```cpp
int null = 0, *p = nullptr;
```
