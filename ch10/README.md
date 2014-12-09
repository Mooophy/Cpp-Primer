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
