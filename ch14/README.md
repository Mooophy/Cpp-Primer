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

(d) = () [] -> must be member

(e) non-member

(f) symetric , non-member

(g) symetric , non-member

(h) = () [] -> must be member

## Exercise 14.5:
>In exercise 7.40 from 7.5.1 (p. 291) you wrote a sketch of one of the following classes. Decide what, if any, overloaded operators your class should provide.

Such as `Book`

[hpp](ex14_05.h) | [cpp](ex14_05.cpp) | [test](ex14_05_TEST.cpp)

## Exercise 14.6:
>Define an output operator for your `Sales_data` class.

see [Exercise 14.2](# Exercise-142).

## Exercise 14.7:
>Define an output operator for you `String` class you wrote for the exercises in 13.5 (p. 531).

[hpp](ex14_07.h) | [cpp](ex14_07.cpp) | [Test](ex14_07_TEST.cpp)

## Exercise 14.8:
>Define an output operator for the class you chose in exercise 7.40 from 7.5.1 (p. 291).

see [Exercise 14.5](# Exercise-145)

## Exercise 14.9:
>Define an input operator for your Sales_data class.

see [Exercise 14.2](# Exercise-142).

## Exercise 14.10:
>Describe the behaviour of the Sales_data input operator if given the following input:
- (a) 0-201-99999-9 10 24.95
- (b) 10 24.95 0-210-99999-9

- (a) correct format.
- (b) ilegal input. But `.95` will be converted to a float stored in this object. As a result, the data inside will be a wrong one.
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

see [Exercise 14.5](# Exercise-145)

## Exercise 14.13:
>Which other arithmetic operators (Table 4.1 (p. 139)), if any, do you think Sales_data ought to support? Define any you think the class should include.

Substraction, in order to be able to revert a previously addition.
[hpp](ex14_13.h) | [cpp](ex14_13.cpp) | [Test](ex14_13_TEST.cpp)

## Exercise 14.14:
>Why do you think it is more efficient to define `operator+` to call `operator+=` rather than the other way around?

Discussing on [SO](http://stackoverflow.com/questions/21071167/why-is-it-more-efficient-to-define-operator-to-call-operator-rather-than-the).

## Exercise 14.15:
>Should the class you chose for exercise 7.40 from 7.5.1 (p. 291) define any of the arithmetic operators? If so, implement them. If not, explain why not.

[hpp](ex14_15.h) | [cpp](ex14_15.cpp) | [Test](ex14_15_TEST.cpp)

## Exercise 14.16:
>Define equality and inequality operators for your `StrBlob` (12.1.1, p. 456), `StrBlobPtr` (12.1.6, p. 474), `StrVec` (13.5, p.526), and `String` (13.5, p. 531) classes.

- `StrBlob` & `StrBlobPtr`: [hpp](ex14_16_StrBlob.h) | [cpp](ex14_16_StrBlob.cpp) | [Test](ex14_16_StrBlobTest.cpp)
- `StrVec`: [hpp](ex14_16_StrVec.h) | [cpp](ex14_16_StrVec.cpp) | [Test](ex14_16_StrVecMain.cpp)
- `String`: [hpp](ex14_16_String.h) | [cpp](ex14_16_String.cpp) | [Test](ex14_16_StringMain.cpp)

## Exercise 14.17:
>Should the class you chose for exercise 7.40 from 7.5.1(p. 291) define the equality operators? If so, implement them. If not, explain why not.

yes.see [Exercise 14.15](# Exercise-1415)

## Exercise 14.18:
>Define relational operators for your `StrBlob`, `StrBlobPtr`, `StrVec`, and `String` classes.

- `StrBlob` & `StrBlobPtr`: [hpp](ex14_18_StrBlob.h) | [cpp](ex14_18_StrBlob.cpp) | [Test](ex14_18_StrBlobTest.cpp)
- `StrVec`: [hpp](ex14_18_StrVec.h) | [cpp](ex14_18_StrVec.cpp) | [Test](ex14_18_StrVecMain.cpp)
- `String`: [hpp](ex14_18_String.h) | [cpp](ex14_18_String.cpp) | [Test](ex14_18_StringMain.cpp)

## Exercise 14.19:
>Should the class you chose for exercise 7.40 from 7.5.1 (p. 291) define the relational operators? If so, implement them. If not, explain why not.

yes.see [Exercise 14.15](# Exercise-1415)

## Exercise 14.20:
>Define the addition and compound-assignment operators for your `Sales_data` class.

see [Exercise 14.2](# Exercise-142).

## Exercise 14.21:
>Write the `Sales_data` operators so that `+` does the actual addition and `+=` calls `+`. Discuss the disadvantages of this approach compared to the way these operators were defined in 14.3 (p. 560) and 14.4 (p.564).

```cpp
Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
    Sales_data old_data = *this;
    *this = old_data + rhs;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum;
    sum.units_sold = lhs.units_sold + rhs.units_sold;
    sum.revenue = lhs.revenue + rhs.revenue;
    return sum;
}
```

**Disadvantages**: Both `+` and `+=`, uses an temporary object of `Sales_data`. But it is no need for that.

## Exercise 14.22:
>Define a version of the assignment operator that can assign a `string` representing an ISBN to a `Sales_data`.

[hpp](ex14_22.h) | [cpp](ex14_22.cpp) | [Test](ex14_22_TEST.cpp)

## Exercise 14.23:
>Define an initializer_list assignment operator for your version of the `StrVec` class.

[hpp](ex14_23.h) | [cpp](ex14_23.cpp) | [Test](ex14_23_TEST.cpp)

## Exercise 14.24:
>Decide whether the class you used in exercise 7.40 from 7.5.1 (p. 291) needs a copy- and move-assignment operator. If so, define those operators.

[hpp](ex14_24.h) | [cpp](ex14_24.cpp) | [Test](ex14_24_TEST.cpp)

## Exercise 14.25:
>Implement any other assignment operators your class should define. Explain which types should be used as operands and why.

see [Exercise 14.24](# Exercise-1424)

## Exercise 14.26:
>Define subscript operators for your `StrVec`, `String`, `StrBlob`, and `StrBlobPtr` classes.

- `StrBlob` & `StrBlobPtr`: [hpp](ex14_26_StrBlob.h) | [cpp](ex14_26_StrBlob.cpp) | [Test](ex14_26_StrBlobTest.cpp)
- `StrVec`: [hpp](ex14_26_StrVec.h) | [cpp](ex14_26_StrVec.cpp) | [Test](ex14_26_StrVecMain.cpp)
- `String`: [hpp](ex14_26_String.h) | [cpp](ex14_26_String.cpp) | [Test](ex14_26_StringMain.cpp)

## Exercise 14.27:
> Add increment and decrement operators to your `StrBlobPtr` class.

[hpp](ex14_27_28_StrBlob.h) | [cpp](ex14_27_28_StrBlob.cpp) | [Test](ex14_27_28_StrBlobTest.cpp)

## Exercise 14.28:
> Define addition and subtraction for `StrBlobPtr` so that these operators implement pointer arithmetic (3.5.3, p. 119).

see [Exercise 14.27](# Exercise-1427)

## Exercise 14.29:
> We did not define a `const` version of the increment and decrement operators. Why not?

Because `++` and `--` change the state of the object. Hence , it's meaningless to do so.

## Exercise 14.30:
> Add dereference and arrow operators to your `StrBlobPtr` class and to the `ConstStrBlobPtr` class that you defined in exercise 12.22 from 12.1.6 (p. 476). Note that the operators in `constStrBlobPtr` must return `const` references because the `data` member in `constStrBlobPtr` points to a `const vector`.

[hpp](ex14_30_StrBlob.h) | [cpp](ex14_30_StrBlob.cpp) | [Test](ex14_30_StrBlobTest.cpp)

## Exercise 14.31:
> Our StrBlobPtr class does not define the copy constructor, assignment operator, or a destructor. Why is that okay?

Applying the Rule of 3/5:
There is no dynamic allocation to deal with, so the synthesized destructor is enough. Moreover, no unique is needed. Hence, the synthesized ones can handle all the corresponding operations.

## Exercise 14.32:
> Define a class that holds a pointer to a `StrBlobPtr`. Define the overloaded arrow operator for that class.

[hpp](ex14_32.h) | [cpp](ex14_32.cpp)

## Exercise 14.33:
> How many operands may an overloaded function-call operator take?

An overloaded operator function has the same number of parameters as the operator has operands. Hence the maximum value should be around 256.
([question on SO](http://stackoverflow.com/questions/21211889/how-many-operands-may-an-overloaded-function-call-operator-take))

## Exercise 14.34:
> Define a function-object class to perform an if-then-else operation: The call operator for this class should take three parameters. It should test its first parameter and if that test succeeds, it should return its second parameter; otherwise, it should return its third parameter.

```cpp
struct Test {
    int operator()(bool b, int iA, int iB) {
        return b ? iA : iB;
    }
};
```

## Exercise 14.35:
> Write a class like `PrintString` that reads a line of input from an `istream` and returns a `string` representing what was read. If the read fails, return the empty `string`.

[Test](ex14_35.cpp)

## Exercise 14.36:
> Use the class from the previous exercise to read the standard input, storing each line as an element in a vector.

[Test](ex14_36.cpp)

## Exercise 14.37:
> Write a class that tests whether two values are equal. Use that object and the library algorithms to write a program to replace all instances of a given value in a sequence.

[Test](ex14_37.cpp)

## Exercise 14.38:
> Write a class that tests whether the length of a given `string` matches a given bound. Use that object to write a program to report how many words in an input file are of sizes 1 through 10 inclusive.

[BoundTest](ex14_38_39.cpp)

## Exercise 14.39:
> Revise the previous program to report the count of words that are sizes 1 through 9 and 10 or more.

see [Exercise 14.38](# Exercise-1438)

## Exercise 14.40:
> Rewrite the `biggies` function from 10.3.2 (p. 391) to use function-object classes in place of lambdas.

[Test](ex14_40.cpp)

## Exercise 14.41:
> Why do you suppose the new standard added lambdas? Explain when you would use a lambda and when you would write a class instead.

IMO, lambda is quite handy to use. Lambda can be used when the functor is not used frequently nor complicated, whereas functor is supposed to call more times than lambda or quite complicated to implement as a lambda.

## Exercise 14.42:
> Using library function objects and adaptors, define an expression to
- (a) Count the number of values that are greater than 1024
- (b) Find the first string that is not equal to `pooh`
- (c) Multiply all values by 2

```cpp
std::count_if(ivec.cbegin(), ivec.cend(), std::bind(std::greater<int>(), _1, 1024));
std::find_if(svec.cbegin(), svec.cend(), std::bind(std::not_equal_to<std::string>(), _1, "pooh"));
std::transform(ivec.begin(), ivec.end(), ivec.begin(), std::bind(std::multiplies<int>(), _1, 2));
```

[Test](ex14_42.cpp)

## Exercise 14.43:
> Using library function objects, determine whether a given `int` value is divisible by any element in a container of `int`s.

[ex14_43.cpp](ex14_43.cpp)

## Exercise 14.44:
> Write your own version of a simple desk calculator that can handle binary operations.

[ex14_44.cpp](ex14_44.cpp)

## Exercise 14.45:
> Write conversion operators to convert a `Sales_data` to `string` and to `double`. What values do you think these operators should return?

[hpp](ex14_45.h) | [cpp](ex14_45.cpp) | [Test](ex14_45_TEST.cpp)

## Exercise 14.46:
> Explain whether defining these Sales_data conversion operators is a good idea and whether they should be explicit.

It's a bad idea to do so, because these conversion is misleading.`explicit` should be added to prevent implicit conversion.

## Exercise 14.47:
> Explain the difference between these two conversion operators:
```cpp
struct Integral {
    operator const int();   // meaningless, it will be ignored by compiler.
    operator int() const;   // promising that this operator will not change the state of the obj
};
```

## Exercise 14.48:
> Determine whether the class you used in exercise 7.40 from 7.5.1 (p. 291) should have a conversion to `bool`. If so, explain why, and explain whether the operator should be `explicit`. If not, explain why not.

A conversion to bool can be useful for the class Date. But it must be an explicit one to prevent any automatic conversion.

## Exercise 14.49:
> Regardless of whether it is a good idea to do so, define a conversion to bool for the class from the previous exercise.

[hpp](ex14_49.h) | [cpp](ex14_49.cpp) | [Test](ex14_49_TEST.cpp)

## Exercise 14.50:
> Show the possible class-type conversion sequences for the initializations of ex1 and ex2. Explain whether the initializations are legal or not.
```cpp
struct LongDouble {
    LongDouble(double = 0.0);
    operator double();
    operator float();
};
LongDouble ldObj;
int ex1 = ldObj;    // error ambiguous: double or float?
float ex2 = ldObj;  // legal
```

## Exercise 14.51:
> Show the conversion sequences (if any) needed to call each version of `calc` and explain why the best viable function is selected.
```cpp
void calc(int);
void calc(LongDouble);
double dval;
calc(dval); // which calc?
```

best viable function: `void calc(int)`. cause class-type conversion is the lowest ranked.

review the order:

1. exact match
2. const conversion
3. promotion
4. arithmetic or pointer conversion
5. class-type conversion

## Exercise 14.52:
> Which `operator+`, if any, is selected for each of the addition expressions? List the candidate functions, the viable functions, and the type conversions on the arguments for each viable function:
```cpp
struct LongDouble {
    // member operator+ for illustration purposes; + is usually a nonmember LongDouble operator+(const SmallInt&); // 1
    // other members as in 14.9.2 (p. 587)
};
LongDouble operator+(LongDouble&, double); // 2
SmallInt si;
LongDouble ld;
ld = si + ld;
ld = ld + si;
```

`ld = si + ld;` is ambiguous. `ld = ld + si` can use both 1 and 2, but 1 is more exactly. (in the 2, SmallInt need to convert to `double`)


## Exercise 14.53:
> Given the definition of SmallInt on page 588, determine whether the following addition expression is legal. If so, what addition operator is used? If not, how might you change the code to make it legal?
```cpp
SmallInt s1;
double d = s1 + 3.14;
```

ambiguous.

**Fixed**:
```cpp
SmallInt s1;
double d = s1 + SmallInt(3.14);
```
