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
