# Chapter 9. Sequential Containers

## Exercise 9.1:
>Which is the most appropriate—a vector, a deque, or a list—for the following program tasks?
Explain the rationale for your choice.
If there is no reason to prefer one or another container, explain why not.

>- (a) Read a fixed number of words, inserting them in the container alphabetically as they are entered. We’ll see in the next chapter that associative containers are better suited to this problem.
>- (b) Read an unknown number of words. Always insert new words at the back. Remove the next value from the front.
>- (c) Read an unknown number of integers from a file. Sort the numbers and then print them to standard output.

- (a) `std::set` is the best. now, we can select `vector` or `deque`, better than `list`, cause we don't need insert or delete elements in the middle.
- (b) `deque`.
>If the program needs to insert or delete elements at the front and the back, but not in the middle, use a deque
- (c) `vector`, no need that insert or delete at the front or back. and
>If your program has lots of small elements and space overhead matters, don’t
use list or forward_list.

## Exercise 9.2:
>Define a list that holds elements that are deques that hold ints.

```cpp
std::list<std::deques<int>> ldi;
```

## Exercise 9.3:
>What are the constraints on the iterators that form iterator ranges?

two iterators, `begin` and `end`:
- they refer to elements of the same container.
- It is possible to reach `end` by repeatedly incrementing `begin`.

## Exercise 9.4:
>Write a function that takes a pair of iterators to a vector<int> and an int value. Look for that value in the range and return a bool indicating whether it was found.

```cpp
bool find(vector<int>::iterator beg, vector<int>::iterator end, int value)
{
    for (auto iter = beg; iter != end; ++iter)
        if (*iter == value) return true;
    return false;
}
```

## Exercise 9.5:
>Rewrite the previous program to return an iterator to the requested element. Note that the program must handle the case where the element is not found.

```cpp
vector<int>::iterator find(vector<int>::iterator beg, vector<int>::iterator end, int value)
{
    for (auto iter = beg; iter != end; ++iter)
        if (*iter == value) return iter;
    return end;
}
```

## Exercise 9.6:
>What is wrong with the following program? How might you correct it?

```cpp
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
while (iter1 < iter2) /*ERROR: operator< cannot be used in list*/
```

Fixed:
```cpp
while(iter1 != iter2)
```

## Exercise 9.7:
>What type should be used as the index into a vector of ints?

    vector<int>::size_type

## Exercise 9.8:
>What type should be used to read elements in a list of strings? To write them?

    list<string>::iterator || list<string>::const_iterator // read
    list<string>::iterator // write

## Exercise 9.9:
>What is the difference between the `begin` and `cbegin` functions?

`cbegin` is a const member that returns the container’s **const_iterator** type.

`begin` is nonconst and returns the container’s **iterator** type.

## Exercise 9.10:
>What are the types of the following four objects?
```cpp
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();
auto it3 = v1.cbegin(), it4 = v2.cbegin();
```

`it1` is `vector<int>::iterator`

`it2`,`it3` and `it4` are `vector<int>::const_iterator`

## Exercise 9.11:
>Show an example of each of the six ways to create and initialize a vector. Explain what values each vector contains.

```cpp
vector<int> vec;    // 0
vector<int> vec(10);    // 0
vector<int> vec(10,1);  // 1
vector<int> vec{1,2,3,4,5}; // 1,2,3,4,5
vector<int> vec(other_vec); // same as other_vec
vector<int> vec(other_vec.begin(), other_vec.end()); // same as other_vec
```

## Exercise 9.12:
>Explain the differences between the constructor that takes a container to copy and the constructor that takes two iterators.

we can use the constructor that takes two iterators to copy a **subsequence** of a container. But the constructor that takes a container to copy should copy whole container.

## [Exercise 9.13](ex9_13.cpp)
## [Exercise 9.14](ex9_14.cpp)
## [Exercise 9.15](ex9_15.cpp)
## [Exercise 9.16](ex9_16.cpp)

## Exercise 9.17:
>Assuming c1 and c2 are containers, what (if any) constraints does the following usage place on the types of c1 and c2?

First, ther must be the identical container and same type holded.
Second,the type holded must support relational operation. (@Mooophy)

Both c1 and c2 are the containers except the unordered associative containers.(@pezy)

## [Exercise 9.18](ex9_18.cpp)
## [Exercise 9.19](ex9_19.cpp)
## [Exercise 9.20](ex9_20.cpp)

## Exercise 9.21:
>Explain how the loop from page 345 that used the return from insert to add elements to a list would work if we inserted into a vector instead.

It's the same.
>The first call to `insert` takes the `string` we just read and puts it in front of the element denoted by `iter`. The value returned by `insert` is an iterator referring to this new element. We assign that iterator to `iter` and repeat the `while`, reading another word. As long as there are words to insert, each trip through the `while` inserts a new element ahead of `iter` and reassigns to `iter` the location of the newly inserted element. That element is the (new) first element. Thus, each iteration inserts an element ahead of the first element in the `vector`.

## Exercise 9.22:
>Assuming `iv` is a `vector` of `int`s, what is wrong with the following program? How might you correct the problem(s)?
```cpp
vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;
while (iter != mid)
    if (*iter == some_val)
        iv.insert(iter, 2 * some_val);
```

It's a endless loop. `iter` never equal `mid`.

FIXED: (changed the `while` loop)
```
while (iter++ != mid)
```

## Exercise 9.23:
>In the first program in this section on page 346, what would
the values of val, val2, val3, and val4 be if c.size() is 1?

same value that equal to the first element's.

## [Exercise 9.24](ex9_24.cpp)
