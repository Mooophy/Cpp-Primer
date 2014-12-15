# Chapter 11. Associative Containers

## Exercise 11.1:
>Describe the differences between a map and a vector.

A `map` is a collection of key-value pairs. we can get a value **lookup by key** efficiently.

A `vector` is a collection of objects, and every object has an **associated index**, which gives access to that object.

## Exercise 11.2:
>Give an example of when each of list, vector, deque, map, and set might be most useful.

- list : a to-do list. always need insert or delete the elements anywhere.
- vector : save some important associated data, always need query elements by index.
- deque : message handle. FIFO.
- map : dictionary.
- set : bad_checks.

## [Exercise 11.3 and 11.4](ex11_3_4.cpp)

## Exercise 11.5:
>Explain the difference between a map and a set. When might you use one or the other?

- `set` : the element type is the **key type**.
- `map` : we should use a key-value pair, such as `{key, value}` to indicate that the items together from one element in the map.

I use `set` when i just need to store the `key`, In other hand, I　would like use `map` when i need to store a key-value pair.

## Exercise 11.6:
>Explain the difference between a set and a list. When might you use one or the other?

`set` is unique and order, but `list` is neither. using which one depend on whether the elements are unique and order to store.

## [Exercise 11.7](ex11_7.cpp)
## [Exercise 11.8](ex11_8.cpp)
## [Exercise 11.9 and 11.10](ex11_9_10.cpp)
## [Exercise 11.11](ex11_11.cpp)
## [Exercise 11.12 and 11.13](ex11_12_13.cpp)
## [Exercise 11.14](ex11_14.cpp)
