##Exercise 2.1
> What are the differences between int, long, long long,
and short? Between an unsigned and a signed type? Between a float and
a double?

C++ guarantees `short` and `int` is **at least** 16 bits, `long` **at least** 32 bits, `long long` **at least** 64 bits.

The `unsigned` and `signed` type have the **same size**. for example, sizeof(unsigned short) == sizeof(short).

The C and C++ standards do not specify the representation of float, double and long double.
It is possible that all three implemented as IEEE double-precision.
Nevertheless, for most architectures (gcc, MSVC; x86, x64, ARM) float is indeed a IEEE **single-precision** floating point number (binary32),
and double is a IEEE **double-precision** floating point number (binary64).

Usage:

- Use `int` for integer arithmetic. `short` is usually too small and, in practice,
`long` often has the same size as `int`. If your data values are larger than
the minimum guaranteed size of an `int`, then use `long long`.
(In a word: short < **int** < long < long long)

- Use an unsigned type when you know that the values cannot be negative.
(In a word: no negative, unsigned.)

- Use double for floating-point computations; float usually does not have
enough precision, and the cost of double-precision calculations versus
single-precision is negligible. In fact, on some machines, double-precision
operations are faster than single. The precision offered by long double
usually is unnecessary and often entails considerable run-time cost.
(In a word: float < **double** < long double)

Reference:

- [What are the criteria for choosing between short / int / long data types?](http://www.parashift.com/c++-faq/choosing-int-size.html)
- [Difference between float and double](http://stackoverflow.com/questions/2386772/difference-between-float-and-double)
- Advice: Deciding which Type to Use(This book.)

##Exercise 2.2
>To calculate a mortgage payment, what types would you use
for the rate, principal, and payment? Explain why you selected each type.

use `double`, or also `float`.

The rate most like that: 4.50 % per year.
The principal most like that: $854.36
The payment most like that: $1,142.36

Reference:

- [mortgage-calculator](http://www.bankrate.com/calculators/mortgages/mortgage-calculator.aspx)
- [What's in a Mortgage Payment?](http://www.homeloanlearningcenter.com/mortgagebasics/whatsinamortgagepayment.htm)
