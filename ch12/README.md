# Chapter 12. Dynamic Memory

## Exercise 12.1:
>How many elements do b1 and b2 have at the end of this code?
```cpp
StrBlob b1;
{
    StrBlob b2 = {"a", "an", "the"};
    b1 = b2;
    b2.push_back("about");
}
```

b2 is destroyed, but the elements in b2 must not be destroyed.

so b1 and b2 both have 4 elements.

## [Exercise 12.2](ex12_02.h)
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

## [Exercise 12.6](ex12_06.h)
## [Exercise 12.7](ex12_07.h)

## Exercise 12.8:
>Explain what if anything is wrong with the following function.
```cpp
bool b() {
    int* p = new int;
    // ...
    return p;
}
```

The p will convert to a bool ,which means that the dynamic memory allocated has no chance to be freed. As a result, memory leakage will occur.

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

no memory leakages. As `r2 = q2` was executed, the count of the object `r2` had pointer to went to `0`, which freed the corresponding memory.
