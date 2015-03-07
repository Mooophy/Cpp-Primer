##Exercise 5.1
>What is a null statement? When might you use a null statement?

null statement is the empty statement. like this:
```cpp
; // null statement
```

I might use a null statement when the **language requires a statement but the program's logic does not. For example:
```cpp
// read until we hit end-of-file or find an input equal to sought
while (cin >> s && s != sought)
    ; // null statement.
```

##Exercise 5.2
>What is a block? When might you might use a block?

block is a (possiby empty) sequence of statements and declarations surrounded by a pair of curly braces.

I might use a block when the language requires a single statement but the logic of our program needs more than one. For example:
```cpp
while (val <= 10)
{
    sum += val;
    ++val;
}
```

##Exercise 5.3
>Use the comma operator (§ 4.10, p. 157) to rewrite the while loop from § 1.4.1 (p. 11)
so that it no longer requires a block.
Explain whether this rewrite improves or diminishes the readability of this code.

```cpp
#include <iostream>
int main()
{
    int sum = 0, val = 1;
    while (val <= 10)
        sum += val, ++val;
    std::cout << "Sum of 1 to 10 inclusive is "
              << sum << std::endl;

    return 0;
}
```

This rewrite diminishes the readability of the code. The comma operator always guarantees the order and discards the front result.
But there are no meaning in this example, however, also are incomprehensible.

##Exercise 5.4
>Explain each of the following examples, and correct anyproblems you detect.
- (a) while (string::iterator iter != s.end()) { /* . . . */ }
- (b) while (bool status = find(word)) { /* . . . */ }
if (!status) { /* . . . */ }

(a) iter point at nothing. invalid.
```cpp
std::string::iterator iter = s.begin();
    while (iter != s.end()) { /* . . . */ }
```

(b) The if statement is not in the while's block. so the `status` is invalid. And if find(word) return true, it will go through the while block. we should declare the status before while.
```cpp
bool status;
while ((status = find(word))) {/* ... */}
if (!status) {/* ... */}
```  

In fact, the judge `!status` is unnecessary. If the `status=false`, we leave the while, and `!status` is always true.

##[Exercise 5.5](ex5_5.cpp)
##[Exercise 5.6](ex5_6.cpp)
##Exercise 5.7
>Correct the errors in each of the following code fragments:
```cpp
(a) if (ival1 != ival2) ival1 = ival2
    else ival1 = ival2 = 0;
(b) if (ival < minval) minval = ival;
    occurs = 1;
(c) if (int ival = get_value())
    cout << "ival = " << ival << endl;
    if (!ival)
    cout << "ival = 0\n";
(d) if (ival = 0)
    ival = get_value();
```

```cpp
(a) if (ival1 != ival2) ival1 = ival2; // lost semicolon.
    else ival1 = ival2 = 0;
(b) if (ival < minval)
    {
        minval = ival;
        occurs = 1;
    }
(c) if (int ival = get_value())
        cout << "ival = " << ival << endl;
    else if (!ival)
        cout << "ival = 0\n";
(d) if (ival == 0)
    ival = get_value();
```

##Exercise 5.8
>What is a “dangling else”? How are else clauses resolved in C++?

Colloquial term used to refer to the problem of how to process nested if statements in which there are more ifs than elses. In C++, an else is always paired with the closest preceding unmatched if.

##[Exercise 5.9](ex5_9.cpp)
##[Exercise 5.10](ex5_10.cpp)
##[Exercise 5.11](ex5_11.cpp)
##[Exercise 5.12](ex5_12.cpp)

##Exercise 5.13
>Each of the programs in the highlighted text on page 184 contains a common programming error. Identify and correct each error.
```cpp
(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case 'a': aCnt++;
        case 'e': eCnt++;
        default: iouCnt++;
    }
(b) unsigned index = some_value();
    switch (index) {
        case 1:
            int ix = get_value();
            ivec[ ix ] = index;
            break;
        default:
            ix = ivec.size()-1;
            ivec[ ix ] = index;
    }
(c) unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1, 3, 5, 7, 9:
            oddcnt++;
            break;
        case 2, 4, 6, 8, 10:
            evencnt++;
            break;
    }
(d) unsigned ival=512, jval=1024, kval=4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
```

```cpp
(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case 'a': aCnt++; break;
        case 'e': eCnt++; break;
        case 'i':
        case 'o':
        case 'u': iouCnt++; break;
    }
(b) unsigned index = some_value();
    int ix;
    switch (index) {
        case 1:
            ix = get_value();
            ivec[ ix ] = index;
            break;
        default:
            ix = static_cast<int>(ivec.size())-1;
            ivec[ ix ] = index;
    }
(c) unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1: case 3: case 5: case 7: case 9:
            oddcnt++;
            break;
        case 2: case 4: case 6: case 8: case 0:
            evencnt++;
            break;
    }
(d) const unsigned ival=512, jval=1024, kval=4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
```

## Exercise 5.14
>Write a program to read strings from standard input looking for duplicated words. The program should find places in the input where one word is followed immediately by itself. Keep track of the largest number of times a single repetition occurs and which word is repeated. Print the maximum number of duplicates, or else print a message saying that no word was repeated. For example, if the input is
```sh
how now now now brown cow cow
```
the output should indicate that the word now occurred three times.

- [concise solution](ex5_14.cpp)
- [easy to understand](ex5_14_1.cpp)


##Exercise 5.15
>Explain each of the following loops. Correct any problems you detect.
```cpp
(a) for (int ix = 0; ix != sz; ++ix) { /* ... */ }
    if (ix != sz)
    // . . .
(b) int ix;
    for (ix != sz; ++ix) { /* ... */ }
(c) for (int ix = 0; ix != sz; ++ix, ++sz) { /*...*/ }
```

```cpp
(a) int ix;
    for (ix = 0; ix != sz; ++ix)  { /* ... */ }
    if (ix != sz)
    // . . .
(b) int ix;
    for (; ix != sz; ++ix) { /* ... */ }
(c) for (int ix = 0; ix != sz; ++ix) { /*...*/ }
```

##Exercise 5.16
>The while loop is particularly good at executing while some condition holds; for example, when we need to read values until end-of-file. The for loop is generally thought of as a **step loop**: An index steps through a range of values in a collection. Write an idiomatic use of each loop and then rewrite each using the other loop construct. If you could use only one loop, which would you choose? Why?

```cpp
// while idiomatic
int i;
while ( cin >> i )
    // ...

// same as for
for (int i = 0; cin >> i;)
    // ...

// for idiomatic
for (int i = 0; i != size; ++i)
    // ...

// same as while
int i = 0;
while (i != size)
{
    // ...
    ++i;
}
```

I prefer `for` to `while` in such cases, because it's terse. More importantly, object i won't pollute the external scope after it goes out of the loop. It's a little bit easier to add new code into the external scope, since it reduces the possibility of naming conflicts .That is, a higher maintainability. Of course, this way makes the code a bit harder to read. ([@Mooophy](https://github.com/Mooophy))

##[Exercise 5.17](ex5_17.cpp)

##Exercise 5.18
>Explain each of the following loops. Correct any problems you detect.
```cpp
(a) do { // added bracket.
        int v1, v2;
        cout << "Please enter two numbers to sum:" ;
        if (cin >> v1 >> v2)
            cout << "Sum is: " << v1 + v2 << endl;
    }while (cin);
(b) int ival;
    do {
        // . . .
    } while (ival = get_response()); // should not declared in this scope.
(c) int ival = get_response();
    do {
        ival = get_response();
    } while (ival); // ival is not declared in this scope.
```

##[Exercise 5.19](ex5_19.cpp)
##[Exercise 5.20](ex5_20.cpp)
##[Exercise 5.21](ex5_21.cpp)

##Exercise 5.22
>The last example in this section that jumped back to begin could be better written using a loop. Rewrite the code to eliminate the goto.
```cpp
// backward jump over an initialized variable definition is okay  
begin:
    int sz = get_size();
    if (sz <= 0) {
        goto begin;
    }
```

use `for` to replace `goto`:
```cpp
for (int sz = get_size(); sz <=0; sz = get_size())
    ; // should not remove.
```

##[Exercise 5.23](ex5_23.cpp)
##[Exercise 5.24](ex5_24.cpp)
##[Exercise 5.25](ex5_25.cpp)
