Chapter 3. Strings, Vectors, and Arrays
=======================================

## Exercise 3.1
> Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76) with appropriate `using` declarations.
```c++
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
```

## Exercise 3.2
> Writa a program to read the standard input a line at a time. Modify your program to read a word at a time.
* Read the standard input a line at a time
```c++
    for (string s; getline(cin, s); cout << s << endl);
```
* Read a word at a time.
```c++
    for (string s; cin >> s; cout << s << endl); 
```
## Exercise 3.3
> Explain how whitespace characters are handled in the `string` input operator and in the `getline` function.

 * For code like `is >> s`, input is separated by whitespaces while reading into string `s`.
 * For code like `getline(is, s)` input is separated by newline `\n` while reading into string `s`. Other whitespaces are ignored.
 * For code like `getline(is, s, delim)` input is separated by `delim` while reading into string `s`. All whitespaces are ignored.

## Exercise 3.4
> Write a program to read two `string`s and report whether the `string`s are equal. If not, report which of the two is larger. Now, change the program to report whether the `string`s have the same length, and if not, report which is longer.
* Read two `string`s and report whether the `string`s are equal. If not, report which of the two is larger.
```c++
    for (string s1, s2; cin >> s1 >> s2; cout << endl){
        if (s1 == s2)
            cout << "The two strings are equal.";
        else
            cout << "The larger string is " << (s1 > s2 ? s1 : s2);
    }
```
* Read two `string`s and report whether the `string`s have the same length, and if not, report which is longer.
```c++
    for (string s1, s2; cin >> s1 >> s2; cout << endl){
        if (s1.size() == s2.size())
            cout << "The two strings have the same length.";
        else
            cout << "The longer string is " << (s1.size() > s2.size() ? s1 : s2);
    }
```

## Exercise 3.5
> Write a program to read `string`s from the standard input, concatenating what is read into one large `string`. Print the concatenated `string`. Next, change the program to separate adjacent input `string`s by a space.
* Read `string`s from the standard input, concatenating what is read into one large `string`.
```c++
    string s;
    for (string tmp; cin >> tmp; s += tmp);
    cout << "The concatenated string is " << s << endl;
```
* Read `string`s from the standard input, separate adjacent input `string`s by a space.
```c++
    string s, tmp;
    for (cin >> s; cin >> tmp; s += " " + tmp);
    cout << "The concatenated string is " << s << endl;
```

## Exercise 3.6
> Use a range `for` to change all the characters in a `string` to `X`.
```c++
    string s("A Simple String");
    for (auto &c : s) c = 'X';
```

## Exercise 3.7
> What would happen if you define the loop control variable in the previous exercise as type `char`? Predict the results and then change your program to use a `char` to see if you were right.

The point here is using reference to mutate a string. If changed to something like below, `c` would become a `char` rather than `auto &`. In such case, `c` is a copy of each character of string `str`, thus the assignment `c = 'X'` won't mutate `str`. As a result, after this range for statement, nothing changes. 
```c++
    string str("A Simple String");
    for (char c : str) c = 'X';
```

## Exercise 3.8
> Rewrite the program in the [Exercise 3.6](#exercise-36), first using a `while` and again using a traditional `for` loop. Which of the three approaches do you prefer and why?
```c++
    string s("A Simple String");

    // the 2nd approach: using while. 
    decltype(s.size()) i = 0;
    while (i < s.size()) s[i++] = 'X';
    cout << s << endl;

    // the 3rd approach: using a traditional for loop.
    for (i = 0; i < s.size(); s[i++] = 'Y');
    cout << s << endl;
```

## Exercise 3.9
> What does the following program do? Is it valid? If not, why not?
```c++
    string s;
    cout << s[0] << endl;
```

This code was dereferencing and printing the first item stored in `s`. Since `s` is empty, such operation is invalid, a.k.a. **undefined behavior**. 

## Exercise 3.10
> Write a program that reads a string of characters including punctuation and writes what was read but with the punctuation removed.
```c++
    for (string s; getline(cin, s); cout << endl)
        for (auto &c : s) if (!ispunct(c)) cout << c;
```

## Exercise 3.11
> Is the following range `for` legal? If so, what is the type of `c`?
```c++
    const string s = "Keep out!";
    for (auto &c : s){ /*... */ }
```

Depending on the code within for loop body. For example:
```c++
    cout << c;  // legal.
    c = 'X';    // illegal.
```
The type of `c` is `const char&`. 

## Exercise 3.12
> Which, if any, of the following `vector` definitions are in error? For those that are legal, explain what the definition does. For those that are not legal, explain why they are illegal.
```c++
    vector<vector<int>> ivec;         // legal(c++11), vectors.
    vector<string> svec = ivec;       // illegal, different type.
    vector<string> svec(10, "null");  // legal, vector have 10 strings: "null".
```

## Exercise 3.13
> How many elements are there in each of the following vectors? What are the values of the elements?
```c++
    vector<int> v1;                 // size: 0,  value: {}
    vector<int> v2(10);             // size: 10, value: {0, 0, ..., 0}
    vector<int> v3(10, 42);         // size: 10, value: {42, 42, ..., 42}
    vector<int> v4{ 10 };           // size: 1,  value: {10}
    vector<int> v5{ 10, 42 };       // size: 2,  value: {10, 42}
    vector<string> v6{ 10 };        // size: 10, value: {"", "", ..., ""}
    vector<string> v7{ 10, "hi" };  // size: 10, value: {"hi", "hi", ..., "hi"}
```

## Exercise 3.14
> Write a program to read a sequence of `int`s from `cin` and store those values in a `vector`.
```c++
    vector<int> vec;
    for (int i; cin >> i; vec.push_back(i));
```

## Exercise 3.15
> Repeat the previous program but read `string`s this time.
```c++
    vector<string> vec;
    for (string s; cin >> s; vec.push_back(s));
```

## Exercise 3.16
> Write a program to print the size and contents of the `vector`s from [Exercise 3.13](#exercise-313). Check whether your answers to that exercise were correct. If not, restudy § 3.3.1 (p. 97) until you understand why you were wrong.
```c++
template <typename T>
void check_and_print(const vector<T> &vec){
    cout << "size: " << vec.size() << "  value: [ ";
    for (auto &x : vec) cout << x << ",";
    cout << "\b ]\n\n";
}
```

## Exercise 3.17
> Read a sequence of words from `cin` and store the values a `vector`. After you've read all the words, process the `vector` and change each word to uppercase. Print the transformed elements, eight words to a line.
```c++
    vector<string> vec;
    for (string word; cin >> word; vec.push_back(word));
    for (auto &s : vec) for (auto &c : s) c = toupper(c);
    
    for (decltype(vec.size()) i = 0, sz = vec.size(); i != sz; cout << endl)
        for (int j = 0; j != 8 && i != sz; ++j, ++i) cout << vec[i] << " ";
```

## Exercise 3.18
> Is the following program legal? If not, how might you fix it?
```c++
    vector<int> ivec;
    ivec[0] = 42;
```
The program is illegal, and we should fix it as follows:
```c++
    vector<int> ivec { 42 };
```

## Exercise 3.19
> List three ways to define a `vector` and give it ten elements, each with the value 42. Indicate whether there is a preferred way to do so and why.
```c++
    vector<int> ivec1(10, 42); // This way is better.
    vector<int> ivec2 { 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
    vector<int> ivec3;
    for (int i = 0; i != 10; ++i) ivec3.push_back(42);
```

## Exercise 3.20
> Read a set of integers into a `vector`. Print the sum of each pair of adjacent elements. Change your program so that it prints the sum of the first and last elements, followed by the sum of the second and second-to-last, and so on.
* PART 1.
```c++
    // Read a set of integers into a vector.
    vector<int> ivec;
    for (int i; cin >> i; ivec.push_back(i));
    // Print the sum of each pair of adjacent elements.
    for (int i = 1; i != ivec.size(); ++i)
        cout << ivec[i - 1] + ivec[i] << " ";
```
* PART 2.
```c++
    // Print the sum of the first and last elements, and so on.
    for (int i = 0, j = ivec.size() - 1; i <= j; ++i, --j)
        cout << ivec[i] + ivec[j] << " ";
```

## Exercise 3.21
> Redo the [Exercise 3.16](#exercise-316) using iterators.
```c++
template <typename T>
void check_and_print(const vector<T> &vec){
    cout << "size: " << vec.size() << "  value: [";
    for (auto it = vec.cbegin(); it != vec.cend(); ++it) cout << *it;
    cout << "\b ]\n\n";
}
```

## Exercise 3.22
> Revise the loop that printed the first paragraph in `text` to instead change the elements in `text` that correspond to the first paragraph to all uppercase. After you've updated `text`, print its contents.
```c++
    for (auto it = text.begin(); it != text.end(); ++it){
        for (auto &c : *it) c = toupper(c);
        cout << *it << " ";
    }
```

## Exercise 3.23
> Write a program to create a `vector` with ten `int` elements. Using an iterator, assign each element a value that is twice its current value. Test your program by printing the `vector`.
```c++
    vector<int> v {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto it = v.begin(); it != v.end(); ++it) *it *= 2;
    for (auto i : v) cout << i << " ";
```
## Exercise 3.24
> Redo the [Exercise 3.20](#exercise-320) using iterators.
* PART 1.
```c++
    // Read a set of integers into a vector.
    vector<int> ivec;
    for (int i; cin >> i; ivec.push_back(i));
    // Print the sum of each pair of adjacent elements.
    for (auto it = ivec.cbegin(); it + 1 != v.cend(); ++it)
        cout << *it + *(it + 1) << " ";
```
* PART 2.
```c++
    // Print the sum of the first and last elements, and so on.
    for (auto lt = ivec.cbegin(), rt = ivec.cend() - 1; lt <= rt; ++lt, --rt)
        cout << *lt + *rt << " ";
```

## Exercise 3.25
> Rewrite the grade clustering program from § 3.3.3 (p. 104) using iterators instead of subscripts.
```c++
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while (cin >> grade){
        if (grade <= 100)
            ++*(scores.begin() + grade / 10);
    }
```

## Exercise 3.26
> In the binary search program on page 112, why did we write `mid = beg + (end - beg) / 2;` instead of `mid = (beg + end) / 2;`?
1. `beg + (end - beg) / 2` works even if you are using pointers, as long as `end - beg` doesn't overflow.
    ```c++
        int *beg = ..., *end = ...;
        int *mid = beg + (end - beg) / 2; // works as expected.
        int *mid = (beg + end) / 2;       // type error, won't compile.
    ```
2. `beg + (end - beg) / 2` won't overflow if `beg` and `end` are large positive numbers. With signed operands, overflow is undefined.
    ```c++
        int beg = 0x7ffffffe, end = 0x7fffffff;
        int mid = beg + (end - beg) / 2; // works as expected.
        int mid = (beg + end)  / 2;      // overflow... undefined.
    ```
    Note that `end - beg` may overflow, but only if `beg < 0` or `end < 0`.
3. For unsigned operands, `beg + (end - beg) / 2` will never overflow as long as `end >= beg`.
    ```c++
        unsigned beg = 0xfffffffeu, end = 0xffffffffu;
        unsigned mid = beg + (end - beg) / 2; // works as expected
        unsigned mid = (beg + end) / 2;       // mid = 0x7ffffffe
    ```
4. Finally, you often want to round towards the `beg` element.
    ```c++
        int beg = -3, end = 0;
        int mid = beg + (end - beg) / 2; // -2, closer to beg
        int mid = (beg + end) / 2;       // -1, surprise!
    ```

## Exercise 3.27
> Assuming `txt_size` is a function that takes no arguments and returns an `int` value, which of the following definitions are illegal? Explain why.
```c++
unsigned buf_size = 1024;

int ia[buf_size];   // illegal, The dimension must be a constant expression.
int ia[4 * 7 - 14]; // legal
int ia[txt_size()]; // illegal, The dimension must be a constant expression.
char st[11] = "fundamental";  // illegal, no space for null terminator.
```

## Exercise 3.28
> What are the values in the following arrays?
```c++
string sa[10];      // all elements are empty strings
int ia[10];         // all elements are 0

int main() {
    string sa2[10]; // all elements are empty strings
    int ia2[10];    // all elements are undefined
}
```

## Exercise 3.29:
> List some of the drawbacks of using an array instead of a `vector`.

1. Size is fixed at compiling time.
2. No API as that of vector.
3. Bug prone.

## Exercise 3.30
> Identify the indexing errors in the following code:
```c++
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
      ia[ix] = ix;
```

When `ix` equal to 10, the expression `ia[ix]` becomes an **Undefined Behavior**, as it is trying to dereference an element out of range.

## Exercise 3.31
> Write a program to define an array of ten `int`s. Give each element the same value as its position in the array.
```c++
    int arr[10];
    for (auto i = 0; i != 10; ++i) arr[i] = i;
```

## Exercise 3.32
> Copy the array you defined in the previous exercise into another array. Rewrite your program to use `vector`s.
* PART 1.
```c++
    int arr[10];
    for (auto i = 0; i != 10; ++i) arr[i] = i;
    int arr2[10];
    for (auto i = 0; i != 10; ++i) arr2[i] = arr[i];
```
* PART 2.
```c++
    vector<int> v(10);
    for (int i = 0; i != 10; ++i) v[i] = i;
    vector<int> v2(v);
```

## Exercise 3.33
> What would happen if we did not initialize the scores array in the program on page 116?

If so, values of array are undefined. 

## Exercise 3.34
> Given that `p1` and `p2` point to elements in the same array, what does the following code do? Are there values of `p1` or `p2` that make this code illegal?
```c++
p1 += p2 - p1;
```
 * It moves `p1` with the offset `p2 - p1`. After this statement, `p1` and `p2` points to the same address. 
 * Any legal value p1, p2 make this code legal.

## Exercise 3.35
> Using pointers, write a program to set the elements in an array to zero.
```c++
    int arr[10];
    for (auto p = begin(arr); p != end(arr); ++p) *p = 0;
```

## Exercise 3.36
> Write a program to compare two arrays for equality. Write a similar program to compare two `vector`s.
* Compare two arrays.
```c++
template <typename T>
bool isEqual(const T * const pb1, const T * const pe1, const T * const pb2, const T * const pe2){
    if ((pe1 - pb1) != (pe2 - pb2)) return false;
    for (auto i = pb1, j = pb2; i != pe1 && j != pe2; ++i, ++j)
        if (*i != *j) return false;
    return true;
}
```
* Compare two `vector`s.
```c++
template <typename T>
bool isEqual(const vector<T> lhs, const vector<T> rhs){
    return lhs == rhs;
}
```

## Exercise 3.37
> What does the following program do?
```c++
const char ca[] = { 'h', 'e', 'l', 'l', 'o' };
const char *cp = ca;
while (*cp) {
    cout << *cp << endl;
    ++cp;
}
```

This code will print all characters in `ca`, afterwards as no `\0` appended, **Undefined Behavior** would happen. For most cases, the while loop here won't be terminated as expected and many rubbish would be printed out. 

## Exercise 3.38
> In this section, we noted that it was not only illegal but meaningless to try to add two pointers. Why would adding two pointers be meaningless?

It simply does not make sense to add two addresses, but if you are sure you want to add 2 memory locations adresses, just add then as unsigned integer values (using typecast).

## Exercise 3.39
> Write a program to compare two `string`s. Now write a program to compare the values of two C-style character strings.
* Compare two `string`s.
```c++
void compare_and_print(const string s1, const string s2){
    if (s1 == s2)
        cout << s1 << " = " << s2 << endl;
    else if (s1 > s2)
        cout << s1 << " > " << s2 << endl;
    else
        cout << s1 << " > " << s2 << endl;
}
```
* Compare the values of two C-style character strings.
```c++
void compare_and_print(const char *cs1, const char *cs2){
    auto cmp = strcmp(cs1, cs2);
    if (cmp == 0) 
        cout << cs1 << " = " << cs2 << endl;
    else if (cmp > 0)
        cout << cs1 << " > " << cs2 << endl;
    else
        cout << cs1 << " < " << cs2 << endl;
}
```

## Exercise 3.40
> Write a program to define two character arrays initialized from string literals. Now define a third character array to hold the concatenation of the two arrays. Use `strcpy` and `strcat` to copy the two arrays into the third.
```c++
    const char *cs1 = "Hello ", *cs2 = "World!";
    const size_t sz = strlen(cs1) + strlen(cs2) + 1;
    char cs3[sz];

    strcpy(cs3, cs1);           // cs3 = "Hello "
    strcat(cs3, cs2);           // cs3 = "Hello World!"
    cout << cs3 << endl;
```

## Exercise 3.41
> Write a program to initialize a `vector` from an array of `int`s.
```c++
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> vec(begin(arr), end(arr));
```

## Exercise 3.42
> Write a program to copy a `vector` of `int`s into an array of `int`s.
```c++
    vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int arr[10];
    for (int i = 0; i != 10; ++i) arr[i] = vec[i];
```

## Exercise 3.43
> Write three different versions of a program to print the elements of `ia`. One version should use a range `for` to manage the iteration, the other two should use an ordinary `for` loop in one case using subscripts and in the other using pointers. In all three programs write all the types directly. That is, do not use a type alias, `auto`, or `decltype` to simplify the code.
```c++
    int ia[3][4] = { 
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
```
* PART 1: Range `for`.
```c++
    for (const int (&row)[4] : ia){
        for (const int &col : row) cout << col << " ";
        cout << endl;
    }

```
* PART 2: Ordinary `for` using subscripts.
```c++
    for (size_t i = 0; i != 3; ++i){
        for (size_t j = 0; j != 4; ++j) cout << ia[i][j] << " ";
        cout << endl;
    }
        
```
* PART 3: Ordinary `for` using pointers.
```c++
    for (const int (*row)[4] = ia; row != end(ia); ++row){
        for (const int *col = *row; col != end(*row); ++col) cout << *col << " ";
        cout << endl;
    }
```

## Exercise 3.44
> Rewrite the programs from the previous exercises using a type alias for the type of the loop control variables.
```c++
    using int_4d = int[4];
```
* PART 1: Range `for` using type alias.
```c++
    for (const int_4d &row : ia){
        for (const int &col : row) cout << col << " ";
        cout << endl;
    }

```
* PART 2: Ordinary `for` using subscripts.
```c++
    for (size_t i = 0; i != 3; ++i){
        for (size_t j = 0; j != 4; ++j) cout << ia[i][j] << " ";
        cout << endl;
    }
        
```
* PART 3: Ordinary `for` using pointers and using type alias.
```c++
    for (const int_4d *row = ia; row != end(ia); ++row){
        for (const int *col = *row; col != end(*row); ++col) cout << *col << " ";
        cout << endl;
    }
```

## Exercise 3.45
> Rewrite the programs again, this time using `auto`.
* PART 1: Range `for` using `auto`.
```c++
    for (const auto &row : ia){
        for (const auto &col : row) cout << col << " ";
        cout << endl;
    }

```
* PART 2: Ordinary `for` using subscripts.
```c++
    for (auto i = 0; i != 3; ++i){
        for (auto j = 0; j != 4; ++j) cout << ia[i][j] << " ";
        cout << endl;
    }
        
```
* PART 3: Ordinary `for` using pointers and using `auto`.
```c++
    for (const auto *row = ia; row != end(ia); ++row){
        for (const auto *col = *row; col != end(*row); ++col) cout << *col << " ";
        cout << endl;
    }
```