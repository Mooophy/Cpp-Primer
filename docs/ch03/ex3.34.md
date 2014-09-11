##Exercise 3.34
>Given that p1 and p2 point to elements in the same array, what does the following code do?
Are there values of p1 or p2 that make this code illegal?
```cpp
p1 += p2 - p1;
```

we assume p1 and p2 point to an array arr. so `p1 = &arr[0]`; and `p2 = &arr[0]`.
p2 - p1 is the distance of arr[0] to arr[0], and must be zero.
so `p1 += 0;` can not change the p1's point.

`p1 += p2 - p1;` same as `p1 = p2;`. If p2 and p1 are legal, this code always legal.
