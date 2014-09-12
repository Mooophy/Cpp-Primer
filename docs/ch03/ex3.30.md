##Exercise 3.30
>Identify the indexing errors in the following code:
```cpp
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
      ia[ix] = ix;
```

The size of ia is 10, so the index of value should less than 10.
ix **cannot** equal the array_size.
