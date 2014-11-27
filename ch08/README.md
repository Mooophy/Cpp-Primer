# Chapter 8. The IO Library

## Exercise 8.1:
>Write a function that takes and returns an istream&. The function should read the stream until it hits end-of-file. The function should print what it reads to the standard output. Reset the stream so that it is valid before returning the stream.

```cpp
istream& func(istream &is)
{
    std::string buf;
    while (is >> buf);
    is.clear();
    return is;
}
```

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
