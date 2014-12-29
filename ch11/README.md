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

## Exercise 11.15:
>What are the mapped_type, key_type, and value_type of a map from int to vector<int>?

- mapped_type : vector<int>
- key_type : int
- value_type : std::pair<int, vector<int>>

## Exercise 11.16:
>Using a map iterator write an expression that assigns a value to an element.

```cpp
std::map<int, std::string> map;
map[25] = "Alan";
std::map<int, std::string>::iterator it = map.begin();
it->second = "Wang";
```

## Exercise 11.17:
>Assuming c is a multiset of strings and v is a vector
of strings, explain the following calls. Indicate whether each call is legal:

```cpp
copy(v.begin(), v.end(), inserter(c, c.end())); // legal
copy(v.begin(), v.end(), back_inserter(c)); // illegal, no `push_back` in `set`.
copy(c.begin(), c.end(), inserter(v, v.end())); // legal.
copy(c.begin(), c.end(), back_inserter(v)); // legal.
```
## [Exercise 11.18](ex11_18.cpp)
## Exercise 11.19:
>Define a variable that you initialize by calling begin() on the multiset named bookstore from 11.2.2 (p. 425).
Write the variable’s type without using auto or decltype.

```cpp
using compareType = bool (*)(const Sales_data &lhs, const Sales_data &rhs);
std::multiset<Sales_data, compareType> bookstore(compareIsbn);
std::multiset<Sales_data, compareType>::iterator c_it = bookstore.begin();
```
## [Exercise 11.20](ex11_20.cpp)
## Exercise 11.21:
>Assuming word_count is a map from string to size_t and word is a string, explain the following loop:
```cpp
while (cin >> word)
    ++word_count.insert({word, 0}).first->second;
```

```cpp
++ (word_count.insert({word, 0}).first->second)
```
## Exercise 11.22:
>Given a map<string, vector<int>>, write the types used as an argument and as the return value for the version of insert that inserts one element.

```cpp
std::pair<std::string, std::vector<int>>    // argument
std::pair<std::map<std::string, std::vector<int>>::iterator, bool> // return
```

## [Exercise 11.23](ex11_23.cpp)
## [Exercise 11.24 ~ 11.26](ex11_24_25_26.cpp)
## [Exercise 11.27 ~ 11.30](ex11_27_28_29_30.cpp)
## [Exercise 11.31](ex11_31.cpp)
## [Exercise 11.32](ex11_32.cpp)
## [Exercise 11.33](ex11_33.cpp)

## Exercise 11.34:
>What would happen if we used the subscript operator instead of find in the transform function?

In gcc 4.8.3, will report error:
```cpp
error: passing ‘const std::map<std::basic_string<char>, std::basic_string<char> >’ as ‘this’ argument of ‘std::map<_Key, _Tp, _Compare, _Alloc>::mapped_type& std::map<_Key, _Tp, _Compare, _Alloc>::operator[](const key_type&) [with _Key = std::basic_string<char>; _Tp = std::basic_string<char>; _Compare = std::less<std::basic_string<char> >; _Alloc = std::allocator<std::pair<const std::basic_string<char>, std::basic_string<char> > >; std::map<_Key, _Tp, _Compare, _Alloc>::mapped_type = std::basic_string<char>; std::map<_Key, _Tp, _Compare, _Alloc>::key_type = std::basic_string<char>]’ discards qualifiers [-fpermissive]
     auto key = m[s];
                   ^
```
Because std::map's operator is not declared as **const**,but m is declared as a  reference to  std::map with **const**.If insert new pair,it will cause error.
## Exercise 11.35:
>In buildMap, what effect, if any, would there be from rewriting `trans_map[key] = value.substr(1);` as `trans_map.insert({key, value.substr(1)})`?

- use subscript operator: if a word does appear multiple times, our loops will put the **last** corresponding phrase into trans_map
- use `insert`: if a word does appear multiple times, our loops will put the **first** corresponding phrase into trans_map

## Exercise 11.36:
>Our program does no checking on the validity of either input file. In particular, it assumes that the rules in the transformation file are all sensible.
What would happen if a line in that file has a key, one space, and then the end of the line? Predict the behavior and then check it against your version of the program.

we added a file that name "word_transformation_bad.txt" to folder `data`. the file only has a key, one space.

the program of 11.33 don't influenced by that.

## Exercise 11.37:
>What are the advantages of an unordered container as compared to the ordered version of that container? What are the advantages of the ordered version?

- the advantages of an unordered container:
    - useful when we have a key type for which there is no obvious ordering relationship among the elements
    - useful for applications in which the cost of maintaining the elements in order is prohibitive
- the advantages of the ordered version:
    - Iterators for the ordered containers access elements in order by key
    - we can directly define an ordered container that uses a our own class types for its key type.

## [Exercise 11.38](ex11_38.cpp)
