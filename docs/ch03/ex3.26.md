##Exercise 3.26
>In the binary search program on page 112,
why did we write `mid=beg+(end-beg)/2;` instead of `mid=(beg+end) /2;`?

Because the iterator of vector don't define the `+` operator **between the two iterators**.
`beg + end` is illegal.

We can only use the subtraction between the two iterators.
