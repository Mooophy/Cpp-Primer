Chapter 4. Expressions
======================

## Exercise 4.1
> What is the value returned by `5 + 10 * 20/2`?

105

## Exercise 4.2
> Using Table 4.12 (p. 166), parenthesize the following expressions to indicate the order in which the operands are grouped:
```c++
*vec.begin()           // --> *(vec.begin())
*vec.begin() + 1       // --> (*(vec.begin())) + 1
```

## Exercise 4.3
> Order of evaluation for most of the binary operators is left undefined to give the compiler opportunities for optimization. This strategy presents a trade-off between efficient code generation and potential pitfalls in the use of the language by the programmer. Do you consider that an acceptable trade-off? Why or why not?

No. IMHO, such design cannot improve performance significantly, but it can make bugs very tricky to handle.

## Exercise 4.4
> Parenthesize the following expression to show how it is evaluated. Test your answer by compiling the expression (without parentheses) and printing its result.
```c++
12 / 3 * 4 + 5 * 15 + 24 % 4 / 2

// parenthesize
((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2)
// 16 + 75 + 0 = 91
// print: 91
```

## Exercise 4.5
> Determine the result of the following expressions.
```c++
-30 * 3 + 21 / 5  // -90 + 4 = -86
-30 + 3 * 21 / 5  // -30 + 63 / 5 = -30 + 12 = -18
30 / 3 * 21 % 5   // 10 * 21 % 5 = 210 % 5 = 0
-30 / 3 * 21 % 4  // -10 * 21 % 4 = -210 % 4 = -2
```

## Exercise 4.6
> Write an expression to determine whether an `int` value is even or odd.
```c++
    i & 0x1 // true: odd; false: even.
```

## Exercise 4.7
> What does overflow mean? Show three expressions that will overflow.

Overflow happens when a value is computed that is outside the range of values that the type can represent.
```c++
short svalue = 32767; ++svalue;             // -32768
unsigned uivalue = 0; --uivalue;            // 4294967295
unsigned short usvalue = 65535; ++usvalue;  // 0
```

## Exercise 4.8
> Explain when operands are evaluated in the logical `AND`, logical `OR`, and equality operators.

The logical `AND` and `OR` operators always evaluate their left operand before the right. Moreover, the right operand is evaluated if and only if the left operand does not determine the result. This strategy is known as **short-circuit evaluation**.
- logical `AND`: the right size of an `&&` is evaluated if and only if the left side is `true`.
- logical `OR`: the right size of an `||` is evaluated if and only if the left side is `false`
- equality operators `==`: undefined.

## Exercise 4.9
> Explain the behavior of the condition in the following `if`:
```c++
    const char *cp = "Hello World";
    if (cp && *cp)
```
* `cp` is a pointer to `const char *`, and it's not a `nullptr`. true.
* `*cp` is a `const char`: `'H'`, and it is explicit a nonzero value. true.

true && true --> true.

## Exercise 4.10
> Write the condition for a `while` loop that would read `int`s from the standard input and stop when the value read is equal to `42`.
```c++
    int i = 0;
    while(cin >> i && i != 42);
```

## Exercise 4.11
> Write an expression that tests four values, `a`, `b`, `c`, and `d`, and ensures that `a` is greater than `b`, which is greater than `c`, which is greater than `d`.
```c++
    a > b && b > c && c > d
```

## Exercise 4.12
> Assuming `i`, `j`, and `k` are all `int`s, explain what `i != j < k` means.

`i != j < k` is equivalent to `i != (j < k)`.

## Exercise 4.13
> What are the values of `i` and `d` after each assignment?
```c++
    int i;   double d;
    d = i = 3.5;      // i = 3, d = 3.0
    i = d = 3.5;      // d = 3.5, i = 3
```

## Exercise 4.14
> Explain what happens in each of the `if` tests:
```c++
    if (42 = i)   // complie error: expression is not assignable
    if (i = 42)   // true. i gets value 42.
```

## Exercise 4.15
> The following assignment is illegal. Why? How would you correct it?
```c++
    double dval; int ival; int *pi;
    dval = ival = pi = 0;
```
* `pi` is a pointer to `int`, hence it can not assign to `int` from type `int*`.
```c++
    dval = ival = 0;
    pi = 0;
```

## Exercise 4.16
> Although the following are legal, they probably do not behave as the programmer expects. Why? Rewrite the expressions as you think they should be.
```c++
    if (p = getPtr() != 0)
    if (i = 1024)
```
They use an assignment as a condition. Correct it as follows:
```c++
    if ((p = getPtr()) != 0)
    if (i == 1024)
```

## Exercise 4.17
> Explain the difference between prefix and postfix increment.
* `++i` (prefix increment) will increase the value of `i`, and then return the incremented value.
* `i++` (postfix increment) will increase the value of `i`, but return the original value that `i` held before beging incrementd.

## Exercise 4.18
> What would happen if the `while` loop in the following program that prints the elements from a `vector` used the prefix increment operator?
```c++
    auto pbeg = v.begin();
    // print elements up to the first negative value
    while (pbeg != v.end() && *beg >= 0)
        cout << *pbeg++ << endl; // print the current value and advance pbeg
```

It will print from the second element and dereference `v.end()` at last, which is a **Undefined Behavior**.

## Exercise 4.19
> Given that `ptr` points to an `int`, that `vec` is a `vector<int>`, and that `ival` is an `int`, explain the behavior of each of these expressions. Which, if any, are likely to be incorrect? Why? How might each be corrected?
```c++
ptr != 0 && *ptr++       // check ptr is not a nullptr, and then check the pointer value.
ival++ && ival           // check ival, and then check ival + 1 whether equal zero.
vec[ival++] <= vec[ival] // undefined behavior.

// correct it.
vec[ival] <= vec[ival + 1]
```
See [order of evaluation](http://en.cppreference.com/w/cpp/language/eval_order) and [C++ Operator Precedence](https://en.cppreference.com/w/cpp/language/operator_precedence).

## Exercise 4.20
> Assuming that `iter` is a `vector<string>::iterator`, indicate which, if any, of the following expressions are legal. Explain the behavior of the legal expressions and why those that aren’t legal are in error.
```c++
*iter++;          // return *iter, then iter++.
(*iter)++;        // illegal, *iter is a string, cannot increment value.
*iter.empty()     // illegal, iter should use '->' to indicate whether empty.
iter->empty();    // indicate the iter's value whether empty.
++*iter;          // illegal, string have not increment.
iter++->empty();  // return iter->empty(), then iter++.
```

## Exercise 4.21
> Write a program to use a *conditional operator* to find the elements in a `vector<int>` that have odd value and double the value of each such element.
```c++
    vector<int> ivec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (auto &i : ivec) i = (i & 0x1) ? : 2 * i : i;
```

## Exercise 4.22
> Extend the program that assigned high pass, pass, and fail grades to also assign low pass for grades between 60 and 75 inclusive. Write two versions: One version that uses only conditional operators; the other should use one or more `if` statements. Which version do you think is easier to understand and why?
* Use conditional operator.
```c++
void check_and_print(unsigned grade){
    auto result = grade < 60 ? "fail" : grade < 75 ? "low pass" : grade < 90 ? "pass" : "high pass";
    cout << result << endl;
}
```
* Use `if` statement.
```c++
void check_and_print(unsigned grade){
    if (grade < 60)         cout << "fail";
    else if (grade < 75)    cout << "low pass";
    else if (grade < 90)    cout << "pass";
    else                    cout << "high pass";
    cout << endl;
}
```

## Exercise 4.23
> The following expression fails to compile due to operator precedence. Using Table 4.12 (p. 166), explain why it fails. How would you fix it?
```c++
string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s";
```

Operator Precedence: `?:` has lower precedence than `+`.

Fix it as follows:
```c++
string pl = s + (s[s.size() - 1] == 's' ? "" : "s");
```

## Exercise 4.24
> Our program that distinguished between high pass, pass, and fail depended on the fact that the *conditional operator* is right associative. Describe how that operator would be evaluated if the operator were left associative.

if the operator were left associative.
```c++
final_grade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
```
would same as :
```c++
final_grade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass";
```
if `grade > 90`, first conditional operator's result is `high pass`. so the `final_grade` is always fail. It's contradictory obviously.

## Exercise 4.25
> What is the value of `~'q' << 6` on a machine with 32-bit `int`s and 8 bit `char`s, that uses Latin-1 character set in which `'q'` has the bit pattern `01110001`?
* `'q'` is 8-bit character literal and would be promoted to 32-bit `int` and then inverted, giving
    
    `~'q' == ~00000000 00000000 00000000 01110001 == 11111111 11111111 11111111 10001110`
* `~'q'` shifted left by 6 bits, giving

    `~'q' << 6 == 11111111 11111111 11111111 10001110 << 6 == 11111111 11111111 11100011 10000000`

## Exercise 4.26
> In our grading example in this section, what would happen if we used `unsigned int` as the type for `quiz1`?

The C++ standard does not specify the size of integral types in bytes, but it specifies minimum ranges they must be able to hold. The minimum range of `unsigned int` is 0 to 65535. Since some implementations use only the minimum 16 bits for `unsigned int`, this could cause undefined behavior.

## Exercise 4.27
> What is the result of each of these expressions?
```c++
unsigned long ul1 = 3, ul2 = 7;
ul1 & ul2       // == 3
ul1 | ul2       // == 7
ul1 && ul2      // == true
ul1 || ul2      // == true
```

## Exercise 4.28
> Write a program to print the size of each of the built-in types.
```c++
#include <iostream> // high level input/output operations.

int main(int argc, char *argv[]){
    // by using method below only include what is needed.
    using std::cout;
    using std::endl;
    
    // void type
    cout << "void: nullptr_t\t" << sizeof(std::nullptr_t) << " bytes" << endl << endl;
    
    // boolean type
    cout << "bool:\t\t" << sizeof(bool) << " bytes" << endl << endl;
    
    // charactor type
    cout << "char:\t\t"   << sizeof(char)     << " bytes" << endl;
    cout << "wchar_t:\t"  << sizeof(wchar_t)  << " bytes" << endl;
    cout << "char16_t:\t" << sizeof(char16_t) << " bytes" << endl;
    cout << "char32_t:\t" << sizeof(char32_t) << " bytes" << endl << endl;
    
    // integers type
    cout << "short:\t\t"   << sizeof(short)     << " bytes" << endl;
    cout << "int:\t\t"     << sizeof(int)       << " bytes" << endl;
    cout << "long:\t\t"    << sizeof(long)      << " bytes" << endl;
    cout << "long long:\t" << sizeof(long long) << " bytes" << endl << endl;
    
    // floating point type
    cout << "float:\t\t"     << sizeof(float)       << " bytes" << endl;
    cout << "double:\t\t"    << sizeof(double)      << " bytes" << endl;
    cout << "long double:\t" << sizeof(long double) << " bytes" << endl << endl;
	
    // Fixed width integers
    cout << "int8_t:\t\t" << sizeof(int8_t)   << " bytes" << endl;
    cout << "uint8_t:\t"  << sizeof(uint8_t)  << " bytes" << endl;
    cout << "int16_t:\t"  << sizeof(int16_t)  << " bytes" << endl;
    cout << "uint16_t:\t" << sizeof(uint16_t) << " bytes" << endl;
    cout << "int32_t:\t"  << sizeof(int32_t)  << " bytes" << endl;
    cout << "uint32_t:\t" << sizeof(uint32_t) << " bytes" << endl;
    cout << "int64_t:\t"  << sizeof(int64_t)  << " bytes" << endl;
    cout << "uint64_t:\t" << sizeof(uint64_t) << " bytes" << endl;
    	
    return 0;
}
```

## Exercise 4.29
> Predict the output of the following code and explain your reasoning. Now run the program. Is the output what you expected? If not, figure out why.
```c++
int x[10];   int *p = x;
cout << sizeof(x) / sizeof(*x) << endl; // returns the number of elements in x
cout << sizeof(p) / sizeof(*p) << endl;
```
* The first is 10. It returns the number of elements in x. 
* The second result is undefined. 
    
    `sizeof(p)` returns the size needed hold a pointer and `sizeof(*p)` return the size of the the type to which the pointer points.

## Exercise 4.30
>Using Table 4.12 (p. 166), parenthesize the following expressions to match the default evaluation:
```cpp
sizeof x + y      // (sizeof x) + y . "sizeof" has higher precedence than binary `+`.
sizeof p->mem[i]  // sizeof(p->mem[i])
sizeof a < b      // (sizeof a) < b
sizeof f()        // If `f()` returns `void`, this is invalid; otherwise it returns the size of return type.
```

## Exercise 4.31
> The program in this section used the prefix increment and decrement operators. Explain why we used prefix and not postfix. What changes would have to be made to use the postfix versions? Rewrite the program using postfix operators.
```c++
    vector<int>::size_type cnt = ivec.size();
    // assign values from size... 1 to the elements in ivec
    for (vector<int>::size_type ix = 0;
                      ix != ivec.size(); ++ix, --cnt)
        ivec[ix] = cnt;
```

~~postfix will copy itself as return, then increment or decrement. prefix will increment or decrement first, and return itself. so prefix is more effective in this program. (reduce one copy space.)~~

We use prefix and not postfix, just because of the **Advice: Use Postfix Operators only When Necessary** on § 4.5. Increment and Decrement Operators.

> **Advice: Use Postfix Operators only When Necessary**

> Readers from a C background might be surprised that we use the prefix increment in the programs we've written. The reason is simple: The prefix version avoids unnecessary work. It increments the value and returns the incremented version.The postfix operator must store the original value so that it can return the unincremented value as its result. If we don’t need the unincremented value, there’s no need for the extra work done by the postfix operator.

> For `int`s and pointers, the compiler can optimize away this extra work. For more complicated iterator types, this extra work potentially might be more costly. By habitually using the prefix versions, we do not have to worry about whether the performance difference matters. Moreover—and perhaps more importantly—we can express the intent of our programs more directly.

So, it's just a good habits. And there are no changes if we have to be made to use the postfix versions. 

## Exercise 4.32
> Explain the following loop.
```c++
    constexpr int size = 5;
    int ia[size] = { 1, 2, 3, 4, 5 };
    for (int *ptr = ia, ix = 0;
        ix != size && ptr != ia + size;
        ++ix, ++ptr) { /* ... */ }
```

`ptr` and `ix` have the same function. The former use a pointer, and the latter use the index of array. We use the loop to through the array. (just choose one from `ptr` and `ix`)

## Exercise 4.33
> Using Table 4.12 (p. 166) explain what the following expression does:
```c++
    someValue ? ++x, ++y : --x, --y
```
Because of the most lowest precedence of the comma operator, the expression is same as:
```c++
    (someValue ? ++x, ++y : --x), --y
```
If `someValue` is `true`, then `++x`, and the result is `y`, if `someValue` is `false`, then `--x`, and the result is `--y`. so it is also same as:
```c++
    someValue ? (++x, y) : (--x, --y);
```
Even though the result has nothing to do with `x`, the evaluation of `someValue` does effect the operation on `x`.

## Exercise 4.34
> Given the variable definitions in this section, explain what conversions take place in the following expressions:
```c++
if (fval)
dval = fval + ival;
dval + ival * cval;
```
Remember that you may need to consider the associativity of the operators.
```c++
if (fval)           // fval converted to bool
dval = fval + ival; // ival converted to float, then the result of fval add ival converted to double.
dval + ival * cval; // cval converted to int, then that int and ival converted to double.
```

## Exercise 4.35
> Given the following definitions,
```c++
char cval; int ival; unsigned int ui; float fval; double dval;
```
identify the implicit type conversions, if any, taking place:
```c++
cval = 'a' + 3;             // 'a' promoted to int, then the result of ('a' + 3)(int) converted to char.
fval = ui - ival * 1.0;     // ival converted to double , ui also converted to double. then that double converted(by truncation) to float.
dval = ui * fval;           // ui promoted to float. then that float converted to double.
cval = ival + fval + dval;  // ival converted to float, then that float and fval converted to double. At last, that double converted to char(by truncation).
```

## Exercise 4.36
> Assuming `i` is an `int` and `d` is a `double` write the expression `i *= d` so that it does integral, rather than floating-point, multiplication.
```c++
i *= static_cast<int>(d);
```

## Exercise 4.37
> Rewrite each of the following old-style casts to use a named cast:
```c++
int i; double d; const string *ps; char *pc; void *pv;
pv = (void*)ps; // pv = const_cast<string*>(ps); or pv = static_cast<void*>(const_cast<string*>(ps));
i = int(*pc);   //  i = static_cast<int>(*pc);
pv = &d;        // pv = static_cast<void*>(&d);
pc = (char*)pv; // pc = static_cast<char*>(pv);
```

## Exercise 4.38
> Explain the following expression:
```c++
int i; const int &j = i;
double slope = static_cast<double>(j / i);
```
`j / i` is an `int`, then converted to `double` and assigned to `slope`.
