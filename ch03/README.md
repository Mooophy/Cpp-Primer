## Exercise 3.1 : [part1](ex3_1a.cpp) | [part2](ex3_1b.cpp)
## Exercise 3.2 : [part1](ex3_2a.cpp) | [part2](ex3_2b.cpp)
## Exercise 3.3
>Explain how whitespace characters are handled in the string
input operator and in the `getline` function.

 * For code like `is >> s`, input is separated by whitespaces while reading into string `s`.
 * For code like `getline(is, s)` input is separated by newline `\n` while reading into string `s`. Other whitespaces are ignored.
 * For code like `getline(is, s, delim)`input is separated by `delim` while reading into string `s`. All whitespaces are ignored.

## Exercise 3.4 : [part1](ex3_4a.cpp) | [part2](ex3_4b.cpp)
## Exercise 3.5 : [part1](ex3_5a.cpp) | [part2](ex3_5b.cpp)

## [Exercise 3.6](ex3_6.cpp)
## Exercise 3.7
>What would happen if you define the loop control variable in the previous
exercise as type char? Predict the results and then change your program
to use a char to see if you were right.

The point here is using reference to mutate a string. If changed to something like below, `c` would become a `char` rather than `char&`. In such case, `c` is a copy of each character of string `str`, thus the assignment `c = 'X'` won't mutate `str`. As a result, after this for range statement, nothing changes. 
```cpp
string str("a simple string");
for (char c : str) c = 'X';
```

## [Exercise 3.8](ex3_8.cpp)
## Exercise 3.9
>What does the following program do? Is it valid? If not, why not?
```cpp
string s;
cout << s[0] << endl;
```

This code was dereferencing and printing the first item stored in `s`. Since `s` is empty, such operation is invalid, a.k.a. **undefined behavior**. 


## [Exercise 3.10](ex3_10.cpp)
## Exercise 3.11
>Is the following range for legal? If so, what is the type of c?
```cpp
const string s = "Keep out!";
for (auto &c : s){ /*... */ }
```

Depending on the code within for loop body. For example:

    cout << c;  // legal.
    c = 'X';    // illegal.

The type of `c` is `const char&`. 

## Exercise 3.12
>Which, if any, of the following vector definitions are in error?
For those that are legal, explain what the definition does.
For those that are not legal, explain why they are illegal.
```cpp
vector<vector<int>> ivec;         // legal(c++11), vectors.
vector<string> svec = ivec;       // illegal, different type.
vector<string> svec(10, "null");  // legal, vector have 10 strings: "null".
```

## Exercise 3.13
>How many elements are there in each of the following
vectors? What are the values of the elements?
```cpp
vector<int> v1;         // size:0,  no values.
vector<int> v2(10);     // size:10, value:0
vector<int> v3(10, 42); // size:10, value:42
vector<int> v4{ 10 };     // size:1,  value:10
vector<int> v5{ 10, 42 }; // size:2,  value:10, 42
vector<string> v6{ 10 };  // size:10, value:""
vector<string> v7{ 10, "hi" };  // size:10, value:"hi"
```

## [Exercise 3.14](ex3_14.cpp)
## [Exercise 3.15](ex3_15.cpp)
## [Exercise 3.16](ex3_16.cpp)
## [Exercise 3.17](ex3_17.cpp)
## [Exercise 3.18](ex3_18.cpp)
## [Exercise 3.19](ex3_19.cpp)
## Exercise 3.20 : [part1](ex3_20a.cpp) | [part2](ex3_20b.cpp)
## [Exercise 3.21](ex3_21.cpp)
## [Exercise 3.22](ex3_22.cpp)
## [Exercise 3.23](ex3_23.cpp)
## [Exercise 3.24](ex3_24.cpp)
## [Exercise 3.25](ex3_25.cpp)
## Exercise 3.26
>In the binary search program on page 112,
why did we write `mid=beg+(end-beg)/2;` instead of `mid=(beg+end) /2;`?

`(beg + end)` is meaningless. 

## Exercise 3.27
>Assuming txt_size is a function that takes no arguments
and returns an int value, which of the following definitions are illegal?
Explain why.

```cpp
unsigned buf_size = 1024;

int ia[buf_size];   // illegal, The dimension value must be a constant expression.
int ia[4 * 7 - 14]; // legal
int ia[txt_size()]; // illegal, The dimension value must be a constant expression.
char st[11] = "fundamental";  // illegal, the string's size is 12.
```

## Exercise 3.28
>What are the values in the following arrays?

```cpp
string sa[10];      //all elements are empty strings
int ia[10];         //all elements are 0

int main() 
{
    string sa2[10]; //all elements are empty strings
    int ia2[10];    //all elements are undefined
}
```

## Exercise 3.29:
>List some of the drawbacks of using an array instead of a vector.

1. Size is fixed at compiling time.
2. No API as that of vector.
3. Bug prone.

## Exercise 3.30
>Identify the indexing errors in the following code:
```cpp
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
      ia[ix] = ix;
```

When `ix` equal to 10, the expression `ia[ix]` becomes a **UB**, as it is trying to dereference an element out of range.

## [Exercise 3.31](ex3_31.cpp)
## [Exercise 3.32](ex3_32.cpp)
## Exercise 3.33
>What would happen if we did not initialize the scores array in the program
on page 116?

If so, values of array are undefined. Like this:

![result](https://db.tt/3T4TQoo8)

## Exercise 3.34
>Given that p1 and p2 point to elements in the same array, what does the following code do?
Are there values of p1 or p2 that make this code illegal?

```cpp
p1 += p2 - p1;
```
 * It moves `p1` with the offset `p2 - p1`. After this statement, `p1` and `p2` points to the same address. 
 * Any legal value p1, p2 make this code legal.

## [Exercise 3.35](ex3_35.cpp)
## [Exercise 3.36](ex3_36.cpp)
## Exercise 3.37
>What does the following program do?
```cpp
const char ca[] = { 'h', 'e', 'l', 'l', 'o' };
const char *cp = ca;
while (*cp) {
    cout << *cp << endl;
    ++cp;
}
```

This code will print all characters in `ca`, afterwards as no `\0` appended, **UB** would happen. For most cases, the while loop here won't be terminated as expected and many rubbish would be printed out. 


## Exercise 3.38
>In this section, we noted that it was not only illegal but meaningless to try to add two pointers.
Why would adding two pointers be meaningless?

See:
- [Why can't I add pointers](http://stackoverflow.com/questions/2935038/why-cant-i-add-pointers)

## [Exercise 3.39](ex3_39.cpp)
## [Exercise 3.40](ex3_40.cpp)
## [Exercise 3.41](ex3_41.cpp)
## [Exercise 3.42](ex3_42.cpp)
## [Exercise 3.43](ex3_43.cpp)
## [Exercise 3.44](ex3_44.cpp)
## [Exercise 3.45](ex3_45.cpp)
