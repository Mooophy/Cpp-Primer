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
