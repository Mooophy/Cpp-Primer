Chapter 6. Functions
====================

## Exercise 6.1
> What is the difference between a parameter and an argument?
* **Parameters**: Local variable declared inside the function parameter list.
they are initialized by the **arguments** provided in the each function call.
* **Arguments**: Values supplied in a function call that are used to initialize the function's **parameters**.

## Exercise 6.2
> Indicate which of the following functions are in error and why. Suggest how you might correct the problems.
```c++
    // return should be string, not int.
    int f() {                
          string s;
          // ...
          return s;
    }
    // string f() { string s; /* ... */ return s}

    // function needs return type
    f2(int i) { /* ... */ }  
    // void f2(int i) { /* ... */ }

    // parameter list cannot use same name twice.
    int calc(int v1, int v1) { /* ... */ }  
    // int calc(int v1, int v2) { /* ... */ }

    // function body needs braces
    double square (double x) return x * x;
    // double square (double x) { return x * x; }
```

## Exercise 6.3
> Write and test your own version of `fact`.
```c++
#include <iostream>

int fact(int i) {
    if (i < 0) throw std::runtime_error("Input cannot be a negative number");
    int ret = 1;
    while (i > 1) ret *= i--;
    return ret;
}

int main(int argc, char *argv[]) {
    int j = fact(5);
    std::cout << "5! is " << j << std::endl;
    return 0;
}
```

## Exercise 6.4
> Write a function that interacts with the user, asking for a number and generating the factorial of that number. Call this function from `main`.
```c++
#include <iostream>

int fact(int i) {
    if (i < 0) throw std::runtime_error("Input cannot be a negative number");
    int ret = 1;
    while (i > 1) ret *= i--;
    return ret;
}

void interactive_fact() {
    const std::string prompt       = "Enter a number within [1, 13) :\n";
    const std::string out_of_range = "Out of range, please try again.\n";
    for (int i; std::cout << prompt, std::cin >> i; )
    {
        if (i < 1 || i > 12)
        {
            std::cout << out_of_range; 
            continue;
        }
        std::cout << fact(i) << std::endl;
    }
}

int main() {
    interactive_fact();
    return 0;
}
```

## Exercise 6.5
> Write a function to return the absolute value of its argument.
```c++
int abs(int i) {
    return i >= 0 ? i : -i;
}
```

## Exercise 6.6
> Explain the differences between a parameter, a local variable, and a local `static` variable. Give an example of a function in which each might be useful.
* **local variable**: Variables defined inside a **block**;
* **parameter**: **Local variables** declared inside the **function parameter list**
* **local static variable**: **local static variable (object)** is initialized before the *first* time execution passes through the object’s definition. Local `static`s are not destroyed when a function ends; they are **destroyed when the program terminates.**
```c++
// example
size_t count_add(int n)       // n is a parameter.
{
    static size_t ctr = 0;    // ctr is a static variable.
    ctr += n;
    return ctr;
}

int main()
{
    for (size_t i = 0; i != 10; ++i)    // i is a local variable.
        cout << count_add(i) << endl;
    // This program will print the numbers 0, 1, 3, 6, 10, 15, 21, 28, 36, 45.
    return 0;
}
```

## Exercise 6.7
> Write a function that returns 0 when it is first called and then generates numbers in sequence each time it is called again.
```c++
size_t generate() {
    static size_t ctr = 0;
    return ctr++;
}
```

## Exercise 6.8
> Write a header file named `Chapter6.h` that contains declarations for the functions you wrote for the exercises in § 6.1 (p. 205).
```c++
// filename: Chapter6.h
int fact(int i);
void interactive_fact();
int abs(int i);
```

## Exercise 6.9
> Write your own versions of the `fact.cc` and `factMain.cc` files. These files should include your `Chapter6.h` from [Exercise 6.8](#exercise-68). Use these files to understand how your compiler supports separate compilation.
* PART 1: `fact.cc`
```c++
// filename: fact.cc
#include "Chapter6.h"
#include <iostream>

int fact(int i) {
    if (i < 0) throw std::runtime_error("Input cannot be a negative number");
    int ret = 1;
    while (i > 1) ret *= i--;
    return ret;
}

void interactive_fact() {
    const std::string prompt       = "Enter a number within [1, 13) :\n";
    const std::string out_of_range = "Out of range, please try again.\n";
    for (int i; std::cout << prompt, std::cin >> i; )
    {
        if (i < 1 || i > 12)
        {
            std::cout << out_of_range; 
            continue;
        }
        std::cout << fact(i) << std::endl;
    }
}

int abs(int i) {
    return i >= 0 ? i : -i;
}
```
* PART 2: `factMain.cc`
```c++
// filename: factMain.cc
#include "Chapter6.h"

int main(int argc, char *argv[])
{
    std::cout << "5! is " << fact(5) << std::endl; 
    interactive_fact();
    std::cout << abs(-10) << std::endl;
    return 0;
}
```

## Exercise 6.10
> Using pointers, write a function to swap the values of two `int`s. Test the function by calling it and printing the swapped values.
```c++
#include <iostream>

void swap(int* lhs, int* rhs){
    int tmp;
    tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
}

int main() {
    for (int lft, rht; 
         std::cout << "Please Enter two ints:\n", std::cin >> lft >> rht;
         std::cout << std::endl){
        swap(&lft, &rht);
        std::cout << lft << " " << rht;
    }
    return 0;
}
```

## Exercise 6.11
> Write and test your own version of `reset` that takes a reference.
```c++
#include <iostream>

void reset(int &i) {
    i = 0;
}

int main() {
    int i = 42;
    reset(i);
    std::cout << i  << std::endl;
    return 0;
}
```

## Exercise 6.12
> Rewrite the program from [Exercise 6.10](#exercise-610) to use references instead of pointers to swap the value of two `int`s. Which version do you think would be easier to use and why?
```c++
void swap(int& lhs, int& rhs) {
    int temp = lhs;
    lhs = rhs;
    rhs = temp;
}
```
I think that one using references is easier to use because it is terser.

## Exercise 6.13
> Assuming `T` is the name of a type, explain the difference between a function declared as `void f(T)` and `void f(T&)`.
* `void f(T)` pass the argument by value. **nothing the function does to the parameter can affect the argument**.
* `void f(T&)` pass a reference, will be **bound to** whatever `T` object we pass.

## Exercise 6.14
> Give an example of when a parameter should be a reference type. Give an example of when a parameter should not be a reference.
* a parameter should be a reference type:
```c++
void reset(int &i) {
    i = 0;
}
```
* a parameter should not be a reference:
```c++
void print(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    for (std::vector<int>::iterator iter = begin; iter != end; ++iter)
        std::cout << *iter << std::endl;
}
```

## Exercise 6.15
```c++
string::size_type find_char(const string &s, char c, string::size_type &occurs){
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i){
        if (s[i] == c){
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}
```
> Explain the rationale for the type of each of `find_char`'s parameters. In particular, why is `s` a reference to `const` but `occurs` is a plain reference? 

Because `s` should not be changed by this function, but `occurs` result must be calculated by the function.

> Why are these parameters references, but the char parameter `c` is not?

Because `c` may be a temporary variable, such as `find_char(s, 'a', occurs)`

> What would happen if we made `s` a plain reference? What if we made `occurs` a reference to const?

`s` could be changed in the function, and `occurs` would not be changed. so `occurs = 0;` is an error.

## Exercise 6.16
> The following function, although legal, is less useful than it might be. Identify and correct the limitation on this function:
```c++
bool is_empty(const string &s) { return s.empty(); }
```
Since this function doesn't change the argument, `const` shoud be added before `string& s`, otherwise this function is misleading and can't be used with `const string` or in a `const` function.

## Exercise 6.17
> Write a function to determine whether a `string` contains any capital letters. Write a function to change a `string` to all lowercase. Do the parameters you used in these functions have the same type? If so, why? If not, why not?
* A function to determine whether a `string` contains any capital letters.
```c++
bool containsUpper(const string &s){
    for (auto ch : s) if (isupper(ch)) return true;
    return false;
}
```
* A function to change a `string` to all lowercase.
```c++
void toLowercase(string &s){
    for (auto &ch : s) ch = tolower(ch);
}
```
Not the same.
* For the first one `const` was used, since no change need to do for the argument.
* For the second function, `const` can't be used, because the content of the agument should be changed.

## Exercise 6.18
> Write declarations for each of the following functions. When you write these declarations, use the name of the function to indicate what the function does.
1. A function named `compare` that returns a `bool` and has two parameters that are references to a class named `matrix`.
```c++
bool compare(matrix &, matrix &);
```
2. A function named `change_val` that returns a `vector<int>` iterator and takes two parameters: One is an `int` and the other is an iterator for a `vector<int>`.
```c++
vector<int>::iterator change_val(int, vector<int>::iterator);
```

## Exercise 6.19
> Given the following declarations, determine which calls are legal and which are illegal. For those that are illegal, explain why.
```c++
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);
```
* `calc(23.4, 55.1);`  
illegal. it only has one parameter.
* `count("abcda", 'a');`  
legal.
* `calc(66);`  
legal.
* `sum(vec.begin(), vec.end(), 3.8);`  
legal.

## Exercise 6.20
> When should reference parameters be references to `const`? What happens if we make a parameter a plain reference when it could be a reference to `const`?

If we can use `const`, just use it. If we make a parameter a plain reference when it could be a reference to `const`, the reference value maybe changed.

## Exercise 6.21
> Write a function that takes an `int` and a pointer to an `int` and returns the larger of the `int` value or the value to which the pointer points. What type should you use for the pointer?
```c++
int larger_one(const int i, const int * const p){
    return i > *p ? i : *p;
}
```

## Exercise 6.22
> Write a function to swap two `int` pointers.
```c++
void swap(int* &lft, int* &rht) {
    auto tmp = lft;
    lft = rht;
    rht = tmp;
}
```

## Exercise 6.23
> Write your own versions of each of the `print` functions presented in this section. Call each of these functions to print `i` and `j` defined as follows:
```c++
int i = 0, j[2] = {0, 1};
```
See the following `print` functions.
```c++
void print(const int *pi) {
    if(pi) cout << *pi << endl;
}

void print(const char *p) {
    if (p) while (*p) cout << *p++;
    cout << endl;
}

void print(const int *beg, const int *end) {
    while (beg != end) cout << *beg++ << endl;
}

void print(const int ia[], size_t size) {
    for (size_t i = 0; i != size; ++i) cout << ia[i] << endl;
}

void print(int (&arr)[2]) {
    for (auto i : arr) cout << i << endl;
}
```

## Exercise 6.24
> Explain the behavior of the following function. If there are problems in the code, explain what they are and how you might fix them.
```c++
void print(const int ia[10]){
    for (size_t i = 0; i != 10; ++i) cout << ia[i] << endl;
}
```

Arrays have two special properties that affect how we define and use functions that operate on arrays: We cannot copy an array, and when we use an array it is (usually) converted to a pointer.

So we cannot pass an array by value, and when we pass an array to a function, we are actually passing a pointer to the array's first element.

In this question, `const int ia[10]` is actually same as `const int *ia`, and the size of the array is **irrelevant**.

we can pass `const int ia[3]` or `const int ia[255]`, there are no differences. If we want to pass an array which size is ten, we should use reference like that:

```c++
void print10(const int (&ia)[10]) { /*...*/ }
```

## Exercise 6.25
> Write a `main` function that takes two arguments. Concatenate the supplied arguments and print the resulting `string`.
```c++
#include <iostream>

int main(int argc, char *argv[])
{
    std::string str;
    for (int i = 1; i != argc; ++i)
        str += std::string(argv[i]) + " ";
    std::cout << str << std::endl;
    return 0;
}
```

## Exercise 6.26
> Write a program that accepts the options presented in this section. Print the values of the arguments passed to `main`.
```c++
#include <iostream>

int main(int argc, char *argv[])
{
    for (int i = 1; i != argc; ++i)
        std::cout << argv[i] << std::endl;
    return 0;
}
```

## Exercise 6.27
> Write a function that takes an `initializer_list<int>` and produces the sum of the elements in the list.
```c++
#include <iostream>

int sum(const std::initializer_list<int> &lst){
    int s = 0;
    for (auto i : lst) s += i;
    return s;
}

int main(int argc, char *argv[]){
    std::cout << sum({ 1, 2, 3, 4, 5, 6, 7, 8, 9 }) << std::endl;
    return 0;
}
```

## Exercise 6.28
> In the following function `error_msg` that has an `ErrCode` parameter, what is the type of `elem` in the `for` loop?
```c++
void error_msg(ErrCode e, initializer_list<string> il){
    cout << e.msg() << ": ";
    for (const auto &elem : il) cout << elem << " ";
    cout << endl;
}
```
The type of `elem` in the `for` loop is `const std::string&`.

## Exercise 6.29
> When you use an `initializer_list` in a range `for` would you ever use a reference as the loop control variable? If so, why? If not, why not?

Depends on the type of elements of `initializer_list`. When the type is [PODType](https://en.cppreference.com/w/cpp/named_req/PODType), reference is unnecessary. Because `POD` is **cheap to copy** (such as `int`). Otherwise, Using reference(`const`) is the better choice.

## Exercise 6.30
> Compile the version of `str_subrange` as presented on page 223 to see what your compiler does with the indicated errors.
```c++
bool str_subrange(const string &str1, const string &str2){
    if (str1.size() == str2.size())
        return str1 == str2;
    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
    for (decltype(size) i = 0; i != size; ++i){
        if (str1[i] != str2[i]) return ; // error #1: no return value; compiler should detect this error.
    }
    // error #2: control might flow off the end of the function without a return
    // the compiler might not detect this error.
}
```
* Error#1 (clang): non-void function 'str_subrange' should return a value. 
* Control may reach end of non-void function.

## Exercise 6.31
> When is it valid to return a reference? A reference to `const`?

When you can find the reference referring to the pre-existing object.

## Exercise 6.32
> Indicate whether the following function is legal. If so, explain what it does; if not, correct any errors and then explain it.
```c++
int &get(int *array, int index) { return array[index]; }
int main() {
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;
    return 0;
}
```

legal, it gave the values (0 ~ 9) to array `ia`.

## Exercise 6.33
> Write a recursive function to print the contents of a `vector`.
```c++
void printVec(vector<int> &vec){
    if (!vec.empty()){
        auto tmp = vec.back();
        vec.pop_back();
        printVec(vec);
        cout << tmp << " ";
    }
}
```

## Exercise 6.34
> What would happen if the stopping condition in `factorial` were `if (val != 0)`.
```c++
int factorial(int val){
    if (val > 1)        // if (val != 0)
        return factorial(val - 1) * val;
    return 1;
}
```
When the recursion termination condition becomes `var != 0`, two situations can happen :
* case 1: If the argument is positive, recursion stops at 0. (Note : There is one extra multiplication step though as the combined expression for factorial(5) reads 5 * 4 * 3 * 2 * 1 * 1. In terms of programming languages learning, such subtle difference probably looks quite trivial. In algorithms analysis and proof, however, this extra step may be super important.)
* case 2: if the argument is negative, recursion would never stop. As a result, a stack overflow would occur.

## Exercise 6.35
> In the call to `factorial`, why did we pass `val - 1` rather than `val--`?

the recursive function will always use `val` as the parameter. *a recursion loop* would happen.

## Exercise 6.36
> Write the declaration for a function that returns a reference to an array of ten `string`s, without using either a trailing return, `decltype`, or a type alias.
```c++
string (&func(string (&arrStr)[10]))[10]
```

## Exercise 6.37
> Write three additional declaration for the function in the previous exercise. One should use a type alias, one should use a trailing return, and the third should use `decltype`. Which form do you prefer and why?
* use a type alias.
```c++
using ArrT = string[10];
ArrT& func1(ArrT& arr);
```
* use a trailing return type.
```c++
auto func2(ArrT& arr) -> string(&)[10];
```
* use `decltype`.
```c++
string arrS[10];
decltype(arrS)& func3(decltype(arrS)& arr);
```
I pefer the first one. because it is more simpler to me.

## Exercise 6.38
> Revise the `arrPtr` function on to return a reference to the array.
```c++
int odd[]  = { 1, 3, 5, 7, 9 };
int even[] = { 0, 2, 4, 6, 8 };
int (&arrPtr(int i))[5] {
    return (i % 2) ? odd : even;
}
```

## Exercise 6.39
> Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.
```c++
int calc(int, int);
int calc(const int, const int); // legal. Repeated declarations (without definition) are legal in C++

int get();
double get();                   // error: only the return type is different.

int *reset(int *);
double *reset(double *);        // legal. The parameter type is different and return type is changed.
```

## Exercise 6.40
> Which, if either, of the following declarations are errors? Why?
```c++
int ff(int a, int b = 0, int c = 0);           // ok: adds default arguments.

char *init(int ht = 24, int wd, char bckgrnd); // error: missing default argument on parameter 'wd', 'bckgrnd'.
```

## Exercise 6.41
> Which, if any, of the following calls are illegal? Why? Which, if any, are legal but unlikely to match the programmer's intent? Why?
```c++
char *init(int ht, int wd = 80, char bckgrnd = ' ');

init();        // error: no matching function for call to 'init'

init(24, 10);  // ok. ht = 24, wd = 10, bckgrnd = ' '

init(14, '*'); // ok. but no match. wd would be setting to '*'. ht = 14, wd = '*', bckgrnd = ' '
```

## Exercise 6.42
> Give the second parameter of `make_plural` (§ 6.3.2, p.224) a default argument of `'s'`. Test your program by printing singular and plural versions of the words `success` and `failure`.
```c++
string make_plural(size_t ctr, const string& word, const string& ending = "s") {
    return (ctr > 1) ? word + ending : word;
}

int main() {
    cout << "singual: " << make_plural(1, "success", "es") << " "
         << make_plural(1, "failure") << endl;
    cout << "plural : " << make_plural(2, "success", "es") << " "
         << make_plural(2, "failure") << endl;
    return 0;
}
```

## Exercise 6.43
> Which one of the following declarations and definitions would you put in a header? In a source file? Explain why.
```c++
inline bool eq(const BigInt&, const BigInt&) { /* ... */ } // (a)

void putValues(int *arr, int size);                        // (b)
```
Both should put in a header. 
* (a) is an inline function. 
* (b) is the declaration of useful function. 

We always put them in the header.
## Exercise 6.44
> Rewrite the `isShorter` function from § 6.2.2 (p. 211) to be `inline`.
```c++
inline bool isShorter(const string &s1, const string &s2){
    // defining in the header more better.
    return s1.size() < s2.size();
}
```

## Exercise 6.45
> Review the programs you've written for the earlier exercises and decide whether they should be defined as `inline`. If so, do so. If not, explain why they should not be `inline`.

For example, the function `arrPtr` in [Exercise 6.38](#exercise-638) and `make_plural` in [Exercise 6.42](#exercise-642) should be defined as `inline`. But the function `func` in [Exercise 6.4](#exercise-64) shouldn't. It is not that small and it's only being called once. Hence, it will probably not expand as inline.

## Exercise 6.46
> Would it be possible to define `isShorter` as a `constexpr`? If so, do so. If not, explain why not.

No. Because `std::string::size()` is not a `constexpr` function and `s1.size() == s2.size()` is not a constant expression.

## Exercise 6.47
> Revise the program you wrote in [Exercise 6.33](#exercise-633) that used recursion to print the contents of a `vector` to conditionally print information about its execution. For example, you might print the size of the `vector` on each call. Compile and run the program with debugging turned on and again with it turned off.
```c++
void printVec(vector<int> &vec){
#ifndef NDEBUG
    cout << "vector size: " << vec.size() << endl;
#endif
    if (!vec.empty()){
        auto tmp = vec.back();
        vec.pop_back();
        printVec(vec);
        cout << tmp << " ";
    }
}
```

## Exercise 6.48
> Explain what this loop does and whether it is a good use of `assert`:
```c++
string s;
while (cin >> s && s != sought) { } // empty body
assert(cin);
```

This loop let user input a word all the way until the word is `sought`.

It isn't a good use of assert. because if user begin to input a word, the `cin` would be always have content. so the `assert` would be always `true`. It is meaningless. using `assert(s == sought)` is better.

## Exercise 6.49
> What is a *candidate function*? What is a *viable function*?

* Candidate function: Set of functions that are considered when resolving a function call. (all the functions with the name used in the call for which a declaration is in scope at the time of the call.)
* Viable function: Subset of the candidate functions that could match a given call. It have the same number of parameters as arguments to the call, and each argument type can be converted to the corresponding parameter type.

## Exercise 6.50
> Given the declarations for `f` from page 242, list the viable functions, if any for each of the following calls. Indicate which function is the best match, or if the call is illegal whether there is no match or why the call is ambiguous.
```c++
f(2.56, 42)   // error: call to f is ambiguous.

f(42)         // calls void f(int)

f(42, 0)      // calls void f(int, int)

f(2.56, 3.14) // calls void f(double, double = 3.14)
```

## Exercise 6.51
> Write all four versions of `f`. Each function should print a distinguishing message. Check your answers for the previous exercise. If your answers were incorrect, study this section until you understand why your answers were wrong.
```c++
#include <iostream>
using std::cout; using std::endl;

void f() {
    cout << "f()" << endl;
}

void f(int) {
    cout << "f(int)" << endl;
}

void f(int, int) {
    cout << "f(int, int)" << endl;
}

void f(double, double) {
    cout << "f(double, double)" << endl;
}

int main() {
    // f(2.56, 42); // error: 'f' is ambiguous.
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}
```

## Exercise 6.52
> Given the following declarations,
```c++
void manip(int, int);
double dobj;
```
what is the rank (§ 6.6.1, p. 245) of each conversion in the following calls?
```c++
manip('a', 'z');     // Match through a promotion, char promotes to int
manip(55.4, dobj);   // Match through an arithmetic, double is converted to int
```

## Exercise 6.53
> Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.
```c++
int calc(int&, int&);
int calc(const int&, const int&);   // ok. low-level const conversion.

int calc(char*, char*);
int calc(const char*, const char*); // ok. low-level const conversion.

int calc(char*, char*);
int calc(char* const, char* const); // error: redefinition. 
                                    // two exact match happens: 
                                    // A top-level const is added to 
                                    // or discarded from the argument.
```

## Exercise 6.54
> Write a declaration for a function that takes two `int` parameters and returns an `int`, and declare a `vector` whose elements have this function pointer type.
```c++
int func(int, int);

using pFunc1 = decltype(func) *;
typedef decltype(func) *pFunc2;
using pFunc3 = int (*)(int, int);
using pFunc4 = int(int, int);
typedef int(*pFunc5)(int, int);
using pFunc6 = decltype(func);

std::vector<pFunc1> vec1;
std::vector<pFunc2> vec2;
std::vector<pFunc3> vec3;
std::vector<pFunc4*> vec4;
std::vector<pFunc5> vec5;
std::vector<pFunc6*> vec6;
```

## Exercise 6.55
> Write four functions that add, subtract, multiply, and divide two `int` values. Store pointers to these values in your `vector` from the previous exercise.
```c++
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }
```
See the following code.
```c++
using fp = int(*)(int, int);
vector<fp> v { add, subtract, multiply, divide };
```

## Exercise 6.56
> Call each element in the `vector` and print their result.
```c++
#include <iostream>
#include <vector>

using fp = int(*)(int, int);

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

int main(int argc, char *argv[]){
    std::vector<fp> v { add, subtract, multiply, divide };
    for (auto it = v.cbegin(); it != v.cend(); ++it)
        std::cout << (*it)(2, 2) << std::endl;
}
```