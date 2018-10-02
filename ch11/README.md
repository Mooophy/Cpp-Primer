# Chapter 11. Associative Containers

## Exercise 11.1:
>Describe the differences between a map and a vector.

`map` is an associative container whereas `vector` is a sequence container

## Exercise 11.2:
>Give an example of when each of list, vector, deque, map, and set might be most useful.

- list : anytime when a doubly-linked list is required.
- vector : anytime when a dynamic array is required.
- deque : [An answer from SO](http://stackoverflow.com/questions/3880254/why-do-we-need-deque-data-structures-in-the-real-world).
- map : dictionary.
- set : when to keep elements sorted and unique.

## [Exercise 11.3 and 11.4](ex11_3_4.cpp)

## Exercise 11.5:
>Explain the difference between a map and a set. When might you use one or the other?

[A nice answer on SO](http://stackoverflow.com/questions/16286714/advantages-of-stdset-vs-vectors-or-maps)

## Exercise 11.6:
>Explain the difference between a set and a list. When might you use one or the other?

[list vs set](http://stackoverflow.com/questions/2302681/c-stl-list-vs-set)

## [Exercise 11.7](ex11_7.cpp)
## [Exercise 11.8](ex11_8.cpp)
## [Exercise 11.9 and 11.10](ex11_9_10.cpp)
## [Exercise 11.11](ex11_11.cpp)
## [Exercise 11.12 and 11.13](ex11_12_13.cpp)
## [Exercise 11.14](ex11_14.cpp)

## Exercise 11.15:
>What are the mapped_type, key_type, and value_type of a map from int to vector< int >?

- mapped_type : vector< int >
- key_type : int
- value_type : std::pair< const int, vector<int> >

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
## Exercise 11.18:
>Write the type of map_it from the loop on page 430 without using auto or decltype.

```cpp
std::map<std::string, size_t>::const_iterator;
```
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
    ++word_count.insert({ word, 0 }).first->second;
```
This code can be explained like this pseudocode:
```python
while reading into word
    if word_count has key word:
        word_count[word] += 1
    else:
        word_count[word] = 0
        word_count[word] += 1
```

## Exercise 11.22:
>Given a `map<string, vector<int>>`, write the types used as an argument and as the return value for the version of insert that inserts one element.

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

Say the code has been changed like below:
```cpp
const string& transform(const string &s, const map<string, string> &m)
{
    return m[s];
}
```
The above code won't compile because the subscript operator might insert an element (when the element with the key s is not found), and we may use subscript only on a map that is not const.

## Exercise 11.35:
>In buildMap, what effect, if any, would there be from rewriting `trans_map[key] = value.substr(1);` as `trans_map.insert({ key, value.substr(1) })`?

- use subscript operator: if a word does appear multiple times, our loops will put the **last** corresponding phrase into trans_map
- use `insert`: if a word does appear multiple times, our loops will put the **first** corresponding phrase into trans_map

## Exercise 11.36:
>Our program does no checking on the validity of either input file. In particular, it assumes that the rules in the transformation file are all sensible.
What would happen if a line in that file has a key, one space, and then the end of the line? Predict the behavior and then check it against your version of the program.

If so, a key-value pair will be `{key, " "}`(" ".size() !> 1), which cannot be added into the map. As a result, the key would not be replaced with any string.

## Exercise 11.37:
>What are the advantages of an unordered container as compared to the ordered version of that container? What are the advantages of the ordered version?

[A summary](http://www.cs.fsu.edu/~lacher/courses/COP4531/fall13/lectures/containers2/slide04.html)

## [Exercise 11.38](ex11_38.cpp)
