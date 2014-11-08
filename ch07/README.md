## [Exercise 7.1](ex7_01.cpp)
## [Exercise 7.2](ex7_02.h)
## [Exercise 7.3](ex7_03.cpp)
## [Exercise 7.4](ex7_04.h)
## [Exercise 7.5](ex7_05.h)
## [Exercise 7.6](ex7_06.h)
## [Exercise 7.7](ex7_07.cpp)
## Exercise 7.8

Define `read`'s Sales_data parameter as plain reference since it's intended to change the `revenue`'s value.

Define `print`'s Sales_data parameter as a reference to const since it isn't intended to change any member's value of this object.

## [Exercise 7.9](ex7_09.h)
## Exercise 7.10

```cpp
if(read(read(cin, data1), data2))
```

we can try to divide it like that:
```
std::istream &firstStep = read(cin, data1);
sdt::istream &secondStep = read(firstStep, data2);
if (secondStep)
```
the condition of the `if` statement would read two Sales_data object at one time.

## Exercise 7.11 [Header](ex7_11.h)|[CPP](ex7_11.cpp)
## [Exercise 7.12](ex7_12.h)
## [Exercise 7.13](ex7_13.cpp)
## Exercise 7.14
```cpp
Sales_data() : units_sold(0) , revenue(0){}
```

## [Exercise 7.15](ex7_15.h)
