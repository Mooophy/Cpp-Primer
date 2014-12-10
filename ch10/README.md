# Chapter 10. Generic Algorithms

##[Exercise 10.1 and 10.2](ex10_01_02.cpp)
##[Exercise 10.3 and 10.4](ex10_03_04.cpp)
##[Exercise 10.5](ex10_05.cpp)
##[Exercise 10.6](ex10_06.cpp)
##[Exercise 10.7](ex10_07.cpp)

## Exercise 10.8:
>We said that algorithms do not change the size of the containers over which they operate. Why doesn’t the use of back_inserter invalidate this claim?

Cause the `back_inserter` is a **insert iterator**, what iterator adaptor that generates an iterator that **uses a container operation** to add elements to a given container.

the algorithms don't change the size, but the iterator can change it by using the container operation.

##[Exercise 10.9](ex10_09.cpp)

## Exercise 10.10:
>Why do you think the algorithms don’t change the size of containers?

@Mooophy:
The aim of this design is to separate the algorithms and the operation provided by member function.

@pezy:
Cause the library algorithms operate on **iterators**, **not containers**. Thus, an algorithm **cannot (directly)** add or remove elements.

##[Exercise 10.11](ex10_11.cpp)
##[Exercise 10.12](ex10_12.cpp)
##[Exercise 10.13](ex10_13.cpp)

## Exercise 10.14:
>Write a lambda that takes two ints and returns their sum.

```cpp
auto add = [](int lhs, int rhs){return lhs + rhs;};
```

## Exercise 10.15:
>Write a lambda that captures an int from its enclosing function and takes an int parameter.
The lambda should return the sum of the captured int and the int parameter.

```cpp
int i = 42;
auto add = [i](int num){return i + num;};
```

##[Exercise 10.16](ex10_16.cpp)
##[Exercise 10.17](ex10_17.cpp)
##[Exercise 10.18 and 10.19](ex10_18_19.cpp)
##[Exercise 10.20 and 10.21](ex10_20_21.cpp)
##[Exercise 10.22](ex10_22.cpp)

## Exercise 10.23:
>How many arguments does bind take?
 
Assuming the function to be bound have `n` parameters, bind take `n + 1` parameters.
The additional one is for the function to be bound itself.
