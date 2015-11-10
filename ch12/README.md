# Chapter 12. Dynamic Memory

## Exercise 12.1:
>How many elements do b1 and b2 have at the end of this code?
```cpp
StrBlob b1;
{
    StrBlob b2 = { "a", "an", "the" };
    b1 = b2;
    b2.push_back("about");
}
```

At the end of this code,
 * `b1` holds 4 elements;
 * `b2` has been destroyed automatically. So it's meaningless to say how many elements in `b2`.

## Exercise 12.2

[StrBlob](ex12_02.h) | [TEST](ex12_02_TEST.cpp)

## Exercise 12.3:
>Does this class need const versions of push_back and pop_back? If so, add them. If not, why aren’t they needed?

You can certainly do this if you want to, but there doesn't seem to be any
logical reason. The compiler doesn't complain because this doesn't modify
data (which is a pointer) but rather the thing data points to, which is
perfectly legal to do with a const pointer. by David Schwartz.

-----

Discussion over this exercise on [Stack Overflow](http://stackoverflow.com/questions/20725190/operating-on-dynamic-memory-is-it-meaningful-to-overload-a-const-memeber-functi)

Discussion over this exercise more on [douban](http://www.douban.com/group/topic/61573279/)(chinese)

## Exercise 12.4:
>In our check function we didn’t check whether i was greater than zero. Why is it okay to omit that check?

Because the type of `i` is `std::vector<std::string>::size_type` which
is an `unsigned`.When any argument less than 0 is passed in, it will convert
to a number greater than 0. In short `std::vector<std::string>::size_type`
will ensure it is a positive number or 0.

## Exercise 12.5:
>We did not make the constructor that takes an initializer_list explicit (7.5.4, p. 296). Discuss the pros and cons of this design choice.

[@Mooophy](https://github.com/Mooophy):

keyword `explicit` prevents automatic conversion from an `initializer_list` to `StrBlob`.
This design choice would easy to use but hard to debug.

[@pezy](https://github.com/pezy):

**Pros**

- The compiler will not use this constructor **in an automatic conversion**.
- We can realize clearly which class we have used.

**Cons**

- We always uses the constructor to construct **a temporary StrBlob object**.
- cannot use the copy form of initialization with an explicit constructor. not easy to use.

## [Exercise 12.6](ex12_06.cpp)
## [Exercise 12.7](ex12_07.cpp)

## Exercise 12.8:
>Explain what if anything is wrong with the following function.
```cpp
bool b() {
    int* p = new int;
    // ...
    return p;
}
```

The p will convert to a bool , which means that the dynamic memory allocated has no chance to be freed. As a result, memory leakage will occur.

## Exercise 12.9:
>Explain what happens in the following code:
```cpp
int *q = new int(42), *r = new int(100);
r = q;
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;
```

- to `q` and `r`:

Memory leakage happens. Because after `r = q` was executed, no pointer points to the int `r` had pointed to. It implies that no chance to free the memory for it.

- to `q2` and `r2`:

It's safe. Because after 'r2 = q2', the reference count belongs to r2 reduce to 0 and the reference count belongs to q2 increase to 2, then the memory allocated by r2 will be released automatically.

## [Exercise 12.10](ex12_10.cpp)
## [Exercise 12.11](ex12_11.cpp)
## [Exercise 12.12](ex12_12.cpp)
## [Exercise 12.13](ex12_13.cpp)
## [Exercise 12.14](ex12_14.cpp)
## [Exercise 12.15](ex12_15.cpp)
## [Exercise 12.16](ex12_16.cpp)
## [Exercise 12.17 and 12.18](ex12_17_18.cpp)
## Exercise 12.19 [Header](ex12_19.h)|[Implementation](ex12_19.cpp)
## [Exercise 12.20](ex12_20.cpp)
## Exercise 12.21:
>We could have written StrBlobPtr’s deref member as follows:
```cpp
std::string& deref() const
{ return (*check(curr, "dereference past end"))[curr]; }
```
Which version do you think is better and why?

The original one is better, because it's more readable.

## Exercise 12.22 [Header](ex12_22.h)|[Implementation](ex12_22.cpp)
## [Exercise 12.23](ex12_23.cpp)
## [Exercise 12.24](ex12_24.cpp)

## Exercise 12.25:
>Given the following new expression, how would you delete pa?
```cpp
int *pa = new int[10];
```

```cpp
delete [] pa;
```

## [Exercise 12.26](ex12_26.cpp)
## Exercise 12.27 [Header](ex12_27_30.h)|[Implementation](ex12_27_30.cpp)|[Test](ex12_27_30_TEST.cpp)

## [Exercise 12.28](ex12_28.cpp)

## Exercise 12.29:
>We could have written the loop to manage the interaction with the user as a do while (5.4.4, p. 189) loop. Rewrite the loop to use a do while. Explain which version you prefer and why.

```cpp
do {
    std::cout << "enter word to look for, or q to quit: ";
    string s;
    if (!(std::cin >> s) || s == "q") break;
    print(std::cout, tq.query(s)) << std::endl;
} while ( true );
```

I prefer `do while`, because it looks clearer.

## Exercise 12.30 [Header](ex12_27_30.h)|[Implementation](ex12_27_30.cpp)|[Test](ex12_27_30_TEST.cpp)

## Exercise 12.31:
>What difference(s) would it make if we used a vector instead of a set to hold the line numbers? Which approach is better? Why?

`vector` doesn't guarantee that elements being held are unique, so `set` is a better choice for this case.

## Exercise 12.32 [Header](ex12_32.h)|[Implementation](ex12_32.cpp)|[Test](ex12_32_TEST.cpp)
## Exercise 12.33 [Header](ex12_33.h)|[Implementation](ex12_33.cpp)|[Test](ex12_33_TEST.cpp)
