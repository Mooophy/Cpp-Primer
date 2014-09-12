##Exercise 3.37
>What does the following program do?
```cpp
const char ca[] = {'h', 'e', 'l', 'l', 'o'};
const char *cp = ca;
while (*cp) {
    cout << *cp << endl;
    ++cp;
}
```

Print all the elements of the array.

##Exercise 3.38
>In this section, we noted that it was not only illegal but meaningless to try to add two pointers.
Why would adding two pointers be meaningless?


Because Subtracting two points gives a logically explainable result - the offset
in memory between two points. Similarly, you can subtract or add an integral number to/from a pointer,
which means "move the pointer up or down". Adding a pointer to a pointer is something which is hard to
explain. The result is meaningless.

----
References:
- [Why can't I add pointers](http://stackoverflow.com/questions/2935038/why-cant-i-add-pointers)
