# Chapter 14. Overloaded Operations and Conversions

## Exercise 14.1:
>In what ways does an overloaded operator differ from a built-in operator? In what ways are overloaded operators the same as the built-in operators?

**Differ**
1. We can call an overloaded operator function directly.
2. An overloaded operator function must either be a member of a class or have at least one parameter of class type.
3. A few operators guarantee the order in which operands are evaluated. These overloaded versions of these operators do not preserve order of evaluation and/or short-circuit evaluation, it is usually a bad idea to overload them.
> In particular, the operand-evaluation guarantees of the logical `AND`, logical `OR`, and comma operators are not preserved, Moreover, overloaded versions of `&&` or `||` operators do not preserve short-circuit evaluation properties of the built-in operators. Both operands are always evaluated.

**Same**

- An overloaded operator has the same precedence and associativity as the corresponding built-in operator.

## Exercise 14.2:
>Write declarations for the overloaded input, output, addition, and compound-assignment operators for `Sales_data`.

[hpp](ex14_02.h) | [cpp](ex14_02.cpp)

## Exercise 14.3:
>Both `string` and `vector` define an overloaded == that can be used to compare objects of those types. Assuming `svec1` and `svec2 `are `vectors` that hold `strings`, identify which version of == is applied in each of the following expressions:
- (a) `"cobble" == "stone"`
- (b) `svec1[0] == svec2[0]`
- (c) `svec1 == svec2`
- (d) `"svec1[0] == "stone"`

(a) neither. (b) `string` (c) `vector` (d) `string`

-----

**Reference**
- [Why does the following not invoke the overloaded operator== (const String &, const String &)? “cobble” == “stone”](http://stackoverflow.com/questions/2690737/why-does-the-following-not-invoke-the-overloaded-operator-const-string-con)

## Exercise 14.4:
>Explain how to decide whether the following should be class members:
- (a) %
- (b) %=
- (c) ++
- (d) ->
- (e) <<
- (f) &&
- (g) ==
- (h) ()

(a) symmetric operator. Hence, non-member

(b) changing state of objects. Hence, member

(c) changing state of objects. Hence, member

(d) = [] () -> must be member

(e) non-member

(f) symetric , non-member

(g) symetric , non-member

(h) = [] () -> must be member

## Exercise 14.5:
>In exercise 7.40 from 7.5.1 (p. 291) you wrote a sketch of one of the following classes. Decide what, if any, overloaded operators your class should provide.

Such as `Book`

[hpp](ex14_05.h) | [cpp](ex14_05.cpp) | [test](ex14_05_TEST.cpp)

## Exercise 14.6:
>Define an output operator for your `Sales_data` class.

see [Exercise 14.2](#Exercise 14.2).

## Exercise 14.7:
>Define an output operator for you String class you wrote for the exercises in 13.5 (p. 531).

[hpp](ex14_07.h) | [cpp](ex14_07.cpp) | [Test](ex14_07_TEST.cpp)

## Exercise 14.8:
>Define an output operator for the class you chose in exercise 7.40 from 7.5.1 (p. 291).

see [Exercise 14.5](#Exercise 14.5)

## Exercise 14.9:
>Define an input operator for your Sales_data class.

see [Exercise 14.2](#Exercise 14.2).

## Exercise 14.10:
>Describe the behaviour of the Sales_data input operator if given the following input:
- (a) 0-201-99999-9 10 24.95
- (b) 10 24.95 0-210-99999-9

- (a) correct format.
- (b) ilegal input. But `0-210-99999-9` will be converted to a float stored in this object. As a result, the data inside will be a wrong one.
Output: `10 24 22.8 0.95`

check [Test](ex14_02_TEST.cpp)

## Exercise 14.11:
>What, if anything, is wrong with the following Sales_data input operator? What would happen if we gave this operator the data in the previous exercise?
```cpp
istream& operator>>(istream& in, Sales_data& s)
{
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    s.revenue = s.units_sold * price;
    return in;
}
```

no input check. nothing happend.

## Exercise 14.12:
>Define an input operator for the class you used in exercise 7.40 from 7.5.1 (p. 291). Be sure the operator handles input errors.

see [Exercise 14.5](#Exercise 14.5)

## Exercise 14.13:
>Which other arithmetic operators (Table 4.1 (p. 139)), if any, do you think Sales_data ought to support? Define any you think the class should include.

no others.

## Exercise 14.14:
>Why do you think it is more efficient to define `operator+` to call `operator+=` rather than the other way around?

Discussing on [SO](http://stackoverflow.com/questions/21071167/why-is-it-more-efficient-to-define-operator-to-call-operator-rather-than-the).

## Exercise 14.15:
>Should the class you chose for exercise 7.40 from 7.5.1 (p. 291) define any of the arithmetic operators? If so, implement them. If not, explain why not.

[hpp](ex14_15.h) | [cpp](ex14_15.cpp) | [Test](ex14_15_TEST.cpp)

## Exercise 14.16:
>Define equality and inequality operators for your `StrBlob` (12.1.1, p. 456), `StrBlobPtr` (12.1.6, p. 474), `StrVec` (13.5, p.526), and `String` (13.5, p. 531) classes.
