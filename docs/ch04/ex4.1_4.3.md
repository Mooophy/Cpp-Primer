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
