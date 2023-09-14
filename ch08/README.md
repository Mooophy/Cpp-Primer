# Chapter 8. The IO Library

## [Exercise 8.1](ex08_01.cpp)

## [Exercise 8.2](ex8_02.cpp)

## Exercise 8.3:
>What causes the following while to terminate?
```cpp
while (cin >> i) /*  ...    */
```

putting `cin` in an error state cause to terminate. such as `eofbit`, `failbit` and `badbit`.

## [Exercise 8.4](ex8_04.cpp)
## [Exercise 8.5](ex8_05.cpp)
## [Exercise 8.6](ex8_06.cpp)
## [Exercise 8.7](ex8_07.cpp)
## [Exercise 8.8](ex8_08.cpp)
## [Exercise 8.9](ex8_09.cpp)
## [Exercise 8.10](ex8_10.cpp)
## [Exercise 8.11](ex8_11.cpp)

## Exercise 8.12:
>Why didn’t we use in-class initializers in PersonInfo?

Cause we need a aggregate class here. so it should have no in-class initializers.

## [Exercise 8.13](ex8_13.cpp)

## Exercise 8.14:
>Why did we declare entry and nums as const auto &?

- cause they are all class type, not the built-in type. so **reference** more effective.
- output shouldn't change their values. so we added the `const`.
