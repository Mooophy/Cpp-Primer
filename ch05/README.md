Chapter 5. Statements
=====================

## Exercise 5.1
> What is a null statement? When might you use a null statement?

* A null statement is a single semicolon:
```c++
; // null statement
```
* The null statement may be used as a placeholder when a statement is expected. For example:
```c++
// read until we hit end-of-file or find an input equal to sought
while (cin >> s && s != sought)
    ; // null statement.
```

## Exercise 5.2
> What is a block? When might you might use a block?

A block is a (possibly empty) sequence of statements and declarations surrounded by a pair of curly braces. It's used when multiple statements are needed.For example:
```c++
while (val <= 10) {
    sum += val;
    ++val;
}
```
Note that a block is not terminated by a semicolon.

## Exercise 5.3
> Use the comma operator (§ 4.10, p. 157) to rewrite the `while` loop from § 1.4.1 (p. 11) so that it no longer requires a block. Explain whether this rewrite improves or diminishes the readability of this code.
```c++
#include <iostream>
int main()
{
    int sum = 0, val = 1;
    while (val <= 10) sum += val, ++val;
    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
    return 0;
}
```
This rewritten version diminishes the readability. 

## Exercise 5.4
> Explain each of the following examples, and correct any problems you detect.
```c++
while (string::iterator iter != s.end()) { /* . . . */ }

while (bool status = find(word)) { /* . . . */ } if (!status) { /* . . . */ }
```

* Illegal declaration : `string::iterator iter != s.end()`
```c++
// corrrect it as:
auto iter = s.begin();
while (iter != s.end()) { /* . . . */ }
```
* Variable `status` is only declared inside scope of while condition.
```cpp
// corrrect it as:
bool status;
while (status = find(word)) { /* ... */ }
if (!status) { /* ... */ }
```

## Exercise 5.5
> Using an `if-else` statement, write your own version of the program to generate the letter grade from a numeric grade.
```c++
    vector<string> scores = { "F", "D", "C", "B", "A", "A++" };
    for (int g; cin >> g; ){
        string letter;
        if (g < 60){
            letter = scores[0];
        } else {
            letter = scores[(g - 50) / 10];
            if (g != 100)
                letter += g % 10 > 7 ? "+" : g % 10 < 3 ? "-" : "";
        }
        cout << letter << endl;
    }
```

## Exercise 5.6
> Rewrite your grading program to use the conditional operator (§ 4.7, p. 151) in place of the `if–else` statement.
```c++
    vector<string> scores = { "F", "D", "C", "B", "A", "A++" };

    int grade = 0;
    while (cin >> grade)
    {
        string lettergrade = grade < 60 ? scores[0] : scores[(grade - 50) / 10];
        lettergrade += (grade == 100 || grade < 60) ? "" : 
                                   (grade % 10 > 7) ? "+" : 
                                   (grade % 10 < 3) ? "-" : "";
        cout << lettergrade << endl;
    }
```

## Exercise 5.7
> Correct the errors in each of the following code fragments:
```c++
    if (ival1 != ival2) 
        ival1 = ival2                    // ival1 = ival2;
    else ival1 = ival2 = 0;

    if (ival < minval)                   // if (ival < minval) { 
        minval = ival;                   //     minval = ival;
        occurs = 1;                      //      occurs = 1;
                                         //    }

    if (int ival = get_value())
        cout << "ival = " << ival << endl;
    if (!ival)                           // else / else if (!val)
        cout << "ival = 0\n";

    if (ival = 0)                        // ival == 0
        ival = get_value();
```

## Exercise 5.8
> What is a "dangling `else`"? How are `else` clauses resolved in C++?

Colloquial term used to refer to the problem of how to process nested `if` statements in which there are more `if`s than `else`s. In C++, each `else` is matched with the closest preceding unmatched `if`.

## Exercise 5.9
> Write a program using a series of `if` statements to count the number of vowels in text read from `cin`.
```c++
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;
    while (cin >> ch){
        if      (ch == 'a') ++aCnt;
        else if (ch == 'e') ++eCnt;
        else if (ch == 'i') ++iCnt;
        else if (ch == 'o') ++oCnt;
        else if (ch == 'u') ++uCnt;
    }
```

## Exercise 5.10
> There is one problem with our vowel-counting program as we've implemented it: It doesn't count capital letters as vowels. Write a program that counts both lower- and uppercase letters as the appropriate vowel -- that is, your program should count both `'a'` and `'A'` as part of `aCnt`, and so forth.
```c++
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;
    while (cin >> ch)
        switch (ch)
        {
            case 'a':
            case 'A': ++aCnt; break;
            case 'e':
            case 'E': ++eCnt; break;
            case 'i':
            case 'I': ++iCnt; break;
            case 'o':
            case 'O': ++oCnt; break;
            case 'u':
            case 'U': ++uCnt; break;
        }
```

## Exercise 5.11
> Modify your vowel-counting program so that it also counts the number of blank spaces, tabs, and newlines read.
```c++
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tabCnt = 0, newLineCnt = 0;
    char ch;
    while (cin >> std::noskipws >> ch)
        switch (ch)
        {
            case 'a':
            case 'A':  ++aCnt;       break;
            case 'e':
            case 'E':  ++eCnt;       break;
            case 'i':
            case 'I':  ++iCnt;       break;
            case 'o':
            case 'O':  ++oCnt;       break;
            case 'u':
            case 'U':  ++uCnt;       break;
            case ' ':  ++spaceCnt;   break;
            case '\t': ++tabCnt;     break;
            case '\n': ++newLineCnt; break;
        }
```

## Exercise 5.12
> Modify our vowel-counting program so that it counts the number of occurences of the following two-character sequences: `ff`, `fl`, and `fi`.
```c++
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tabCnt = 0, newLineCnt = 0, ffCnt = 0, flCnt = 0, fiCnt = 0;
    char ch, pre_ch = '\0';
    while (cin >> std::noskipws >> ch) {
        switch (ch)
        {
            case 'a':
            case 'A':  ++aCnt; break;
            case 'e':
            case 'E':  ++eCnt; break;
            case 'i':  if (pre_ch == 'f') ++fiCnt;
            case 'I':  ++iCnt; break;
            case 'o':
            case 'O':  ++oCnt; break;
            case 'u':
            case 'U':  ++uCnt;       break;
            case ' ':  ++spaceCnt;   break;
            case '\t': ++tabCnt;     break;
            case '\n': ++newLineCnt; break;
            case 'f': if (pre_ch == 'f') ++ffCnt; break;
            case 'l': if (pre_ch == 'f') ++flCnt; break;
        }
        pre_ch = ch;
    }
```

## Exercise 5.13
> Each of the programs in the highlighted text on page 184 contains a common programming error. Identify and correct each error.
```c++
    /* Error: should have a break statement */
    unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case 'a': aCnt++;  // case 'a': aCnt++; break;
        case 'e': eCnt++;  // case 'e': eCnt++; break;
        default: iouCnt++; // default: iouCnt++; break;
    }

    /* Error: control bypass an explicitly initialized variable ix */
    unsigned index = some_value();
    // int ix;
    switch (index) {
        case 1:
            int ix = get_value(); // ix = get_value();
            ivec[ ix ] = index;
            break;
        default:
            ix = ivec.size() - 1;
            ivec[ ix ] = index;
    }

    /* Error: case label syntax error */
    unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1, 3, 5, 7, 9:
            oddcnt++;       // oddCnt++;
            break;
        case 2, 4, 6, 8, 10:
            evencnt++;      // evenCnt++;
            break;
    }

    /* Error: case label must be a constant expression */
    unsigned ival = 512, jval = 1024, kval = 4096; 
    // const unsigned ival = 512, jval = 1024, kval = 4096;
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
> Write a program to read `string`s from standard input looking for duplicated words. The program should find places in the input where one word is followed immediately by itself. Keep track of the largest number of times a single repetition occurs and which word is repeated. Print the maximum number of duplicates, or else print a message saying that no word was repeated. For example, if the input is
> 
> `how now now now brown cow cow`
>
> the output should indicate that the word now occurred three times.
```c++
    int count = 0, max_count = 0;
    string duplicate;
    for (string s, pre_s; cin >> s; pre_s = s){
        if (s == pre_s) ++count; else count = 1;
        if (count > max_count){
            duplicate = pre_s;
            max_count = count;
        }
    }
```

## Exercise 5.15
> Explain each of the following loops. Correct any problems you detect.
```c++
for (int ix = 0; ix != sz; ++ix) { /* ... */ }
// int ix;
// for (ix = 0; ix != sz; ++ix) { /* ... */ }
if (ix != sz)
    // ...

int ix;
for (ix != sz; ++ix) { /* ... */ }
// for (; ix != sz; ++ix) { /* ... */ }

for (int ix = 0; ix != sz; ++ix, ++sz) { /*...*/ }
// for (int ix = 0; ix != sz; ++ix) { /* ... */ }
```

## Exercise 5.16
> The `while` loop is particularly good at executing while some condition holds; for example, when we need to read values until end-of-file. The `for` loop is generally thought of as a *step loop*: An index steps through a range of values in a collection. Write an idiomatic use of each loop and then rewrite each using the other loop construct. If you could use only one loop, which would you choose? Why?
```c++
// while idiomatic
int i;
while (cin >> i){ /* ... */ }

// same as for
for (int i; cin >> i; ){ /* ... */ }

// for idiomatic
for (int i = 0; i != size; ++i){ /* ... */ }

// same as while
int i = 0;
while (i != size){ 
    /* ... */ 
    ++i;
    }
```

I prefer `for` to `while` in such cases, because it's terse. More importantly, object `i` won't pollute the external scope after it goes out of the loop. It's a little bit easier to add new code into the external scope, since it reduces the possibility of naming conflicts .That is, a higher maintainability. Of course, this way makes the code a bit harder to read. ([@Mooophy](https://github.com/Mooophy))

## Exercise 5.17
> Given two `vector`s of `int`s, write a program to determine whether one `vector` is a prefix of the other. For `vector`s of unequal length, compare the number of elements of the smaller `vector`. For example, given the `vector`s containing `0`, `1`, `1` and `2` and `0`, `1`, `1`, `2`, `3`, `5`, `8`, respectively your program should return `true`.
```c++
bool isPrefix(const vector<int> &lhs, const vector<int> &rhs){
    if (lhs.size() > rhs.size()) return isPrefix(rhs, lhs);
    for (auto i = 0; i != lhs.size(); ++i) if (lhs[i] != rhs[i]) return false;
    return true;
}
```

## Exercise 5.18
> Explain each of the following loops. Correct any problems you detect.
* Error: it required block between `do` and `while`.
```c++
    do
        int v1, v2;
        cout << "Please enter two numbers to sum:";
        if (cin >> v1 >> v2)
            cout << "Sum is: " << v1 + v2 << endl;
    while (cin);
```
- Correct it.
```c++
    do {
        int v1, v2;
        cout << "Please enter two numbers to sum:" ;
        if (cin >> v1 >> v2)
        cout << "Sum is: " << v1 + v2 << endl;
    } while (cin);
```
---
* Error: can't be defined inside the condition.
```c++
    do {
        // ...
    } while (int ival = get_response());
```
* Correct it.
```c++
    int ival;
    do {
        // ...
    } while (ival = get_response());
```
---
* Error: `ival` used in the condition; can't be defined inside the `do`
```c++
    do {
        int ival = get_response();
    } while (ival);
```
* Correct it.
```c++
    int ival;
    do {
        ival = get_response();
    } while (ival);
```

## Exercise 5.19
> Write a program that uses a `do while` loop to repetitively request two `string`s from the user and report which `string` is less than the other.
```c++
    string rsp;
    do {
        cout << "Input two strings: ";
        string str1, str2;
        cin  >> str1 >> str2;
        cout << (str1 <= str2 ? str1 : str2) 
             << " is less than the other. " << "\n\n"
             << "More? Enter yes or no: ";
        cin  >> rsp;
    } while (!rsp.empty() && tolower(rsp[0]) == 'y');
```

## Exercise 5.20
> Write a program to read a sequence of `string`s from the standard input until either the same word occurs twice in succession or all the words have been read. Use a `while` loop to read the text one word at a time. Use the `break` statement to terminate the loop if a word occurs twice in succession. Print the word if it occurs twice in succession, or else print a message saying that no word was repeated.
```c++
    string buf, pre;
    while (cin >> buf)
        if (buf == pre) break; else pre = buf;
    if (cin.eof()) cout << "no word was repeated.\n";
    else           cout << buf << " occurs twice in sucession.\n";
```

## Exercise 5.21
> Revise the program from the [Exercise 5.20](#exercise-520) so that it looks only for duplicated words that start with an uppercase letter.
```c++
    string buf, pre;
    while (cin >> buf && !buf.empty()){
        if (!isupper(buf[0])){
            pre = "";
            continue;
        }
        if (buf == pre) break; else pre = buf;
    }
    if (cin.eof()) cout << "no word was repeated.\n";
    else           cout << buf << " occurs twice in sucession.\n";
```

## Exercise 5.22
> The last example in this section that jumped back to begin could be better written using a loop. Rewrite the code to eliminate the goto.
```c++
    // backward jump over an initialized variable definition is okay  
    begin:
        int sz = get_size();
        if (sz <= 0) {
            goto begin;
        }
```
* use `for` to replace `goto`:
```c++
    for (int sz = get_size(); sz <=0; sz = get_size());
```
* use `do while` to replace `goto`:
```c++
    int sz;
    do {
        sz = get_size();
    } while (sz <= 0);
```

## Exercise 5.23
> Write a program that reads two integers from the standard input and prints the result of dividing the first number by the second.
```c++
    int i, j; 
    cin >> i >> j;
    cout << i / j << endl;
```

## Exercise 5.24
> Revise your program to throw an exception if the second number is zero. Test your program with a zero input to see what happens on your system if you don't `catch` an exception.
```c++
    int i, j;
    cin >> i >> j;
    if (j == 0) throw runtime_error("divisor is 0");
    cout << i / j << endl;
```

## Exercise 5.25
> Revise your program from the previous exercise to use a `try` block to `catch` the exception. The `catch` clause should print a message to the user and ask them to supply a new number and repeat the code inside the `try`.
```c++
    for (int i, j; cout << "Input two integers:\n", cin >> i >> j; cout << endl){
        try {
            if (j == 0) throw runtime_error("divisor is 0");
            cout << i / j << endl;
        } catch (runtime_error err) {
            cout << e.what() << "\nTry again? Enter y (yes) or n (no)\n";
            char c;
            cin >> c;
            if (cin.eof() || c == 'n') break;
        }
    }
```