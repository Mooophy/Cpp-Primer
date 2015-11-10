# Chapter 9. Sequential Containers

## Exercise 9.1:
>Which is the most appropriate—a vector, a deque, or a list—for the following program tasks?Explain the rationale for your choice.If there is no reason to prefer one or another container, explain why not.

>- (a) Read a fixed number of words, inserting them in the container alphabetically as they are entered. We’ll see in the next chapter that associative containers are better suited to this problem.
>- (b) Read an unknown number of words. Always insert new words at the back. Remove the next value from the front.
>- (c) Read an unknown number of integers from a file. Sort the numbers and then print them to standard output.

- (a) Within the three options, `std::list` is the best one. To keep sorted alphabetically, each inserting into vector takes theta(n) time complexity, whereas that of list (essentially doubly linked list) takes only O(n). Hence theoretically list has better performance.  
- (b) `deque`. If the program needs to insert or delete elements at the front and the back, but not in the middle, use a deque
- (c) `vector`, no need that insert or delete at the front or back. and If your program has lots of small elements and space overhead matters, don’t use list or forward_list.

## Exercise 9.2:
>Define a list that holds elements that are deques that hold ints.

```cpp
std::list<std::deque<int>> a_list_of_deque_of_ints;
```

## Exercise 9.3:
>What are the constraints on the iterators that form iterator ranges?

two iterators, `begin` and `end`:
- they refer to elements of the same container.
- It is possible to reach `end` by repeatedly incrementing `begin`.

## Exercise 9.4:
>Write a function that takes a pair of iterators to a vector<int> and an int value. Look for that value in the range and return a bool indicating whether it was found.

```cpp
auto contains(vector<int>::const_iterator first, vector<int>::const_iterator last, int value)
{
    for(; first != last; ++first)
        if(*first == value) return true;
    return false;
}
```

## Exercise 9.5:
>Rewrite the previous program to return an iterator to the requested element. Note that the program must handle the case where the element is not found.

```cpp
auto find(vector<int>::const_iterator first, vector<int>::const_iterator last, int value)
{
    for(; first != last; ++first)
        if(*first == value) return first;
    return last;
}
```

## Exercise 9.6:
>What is wrong with the following program? How might you correct it?

```cpp
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
while (iter1 < iter2)
```

Fixed:
```cpp
while(iter1 != iter2)
```
#### note:
operator `<` is not implemented in `std::list`, because `std::list` is essetially a doubly linked list. Addresses of nodes of linked list are not necessarily continuous.  
## Exercise 9.7:
>What type should be used as the index into a vector of ints?

    vector<int>::size_type

## Exercise 9.8:
>What type should be used to read elements in a list of strings? To write them?

    list<string>::const_iterator // to read
    list<string>::iterator // to write

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

-----

[@shidenggui](https://github.com/shidenggui):

The question example codes have an error in `gcc 4.8`:
>**error**: inconsistent deduction for ‘auto’: ‘__gnu_cxx::__normal_iterator<int*, std::vector<int> >’ and then ‘__gnu_cxx::__normal_iterator<const int*, std::vector<int> >’ auto it1 = v1.begin(), it2 = v2.begin();

the correct codes should be:
```cpp
auto it1 = v1.begin();
auto it2 = v2.begin(), it3 = v1.cbegin(), it4 = v2.cbegin();
```

-----

`it1` is `vector<int>::iterator`

`it2`, `it3` and `it4` are `vector<int>::const_iterator`

## Exercise 9.11:
>Show an example of each of the six ways to create and initialize a vector. Explain what values each vector contains.

```cpp
vector<int> vec;    // 0
vector<int> vec(10);    // 0
vector<int> vec(10, 1);  // 1
vector<int> vec{ 1, 2, 3, 4, 5 }; // 1, 2, 3, 4, 5
vector<int> vec(other_vec); // same as other_vec
vector<int> vec(other_vec.begin(), other_vec.end()); // same as other_vec
```

## Exercise 9.12:
>Explain the differences between the constructor that takes a container to copy and the constructor that takes two iterators.

- The constructor that takes another container as an argument (excepting array) assumes the container type and element type of both containers are identical. It will also copy all the elements of the received container into the new one:
```cpp
list<int> numbers = { 1, 2, 3, 4, 5 };
list<int> numbers2(numbers);        // ok, numbers2 has the same elements as numbers
vector<int> numbers3(numbers);      // error: no matching function for call...
list<double> numbers4(numbers);     // error: no matching function for call...
```
- The constructor that takes two iterators as arguments does not require the container types to be identical. Moreover, the element types in the new and original containers can differ as long as it is possible to convert the elements we’re copying to the element type of the container we are initializing.
It will also copy only the object delimited by the received iterators.
```cpp
list<int> numbers = { 1, 2, 3, 4, 5 };
list<int> numbers2(numbers.begin(), numbers.end);        // ok, numbers2 has the same elements as numbers
vector<int> numbers3(numbers.begin(), --numbers.end());  // ok, numbers3 is { 1, 2, 3, 4 }
list<double> numbers4(++numbers.beg(), --numbers.end());        // ok, numbers4 is { 2, 3, 4 }
forward_list<float> numbers5(numbers.begin(), numbers.end());   // ok, number5 is { 1, 2, 3, 4, 5 }
```


## [Exercise 9.13](ex9_13.cpp)
## [Exercise 9.14](ex9_14.cpp)
## [Exercise 9.15](ex9_15.cpp)
## [Exercise 9.16](ex9_16.cpp)

## Exercise 9.17:
>Assuming c1 and c2 are containers, what (if any) constraints does the following usage place on the types of c1 and c2?

First, there must be the identical container and same type holded.
Second, the type held must support relational operation. (@Mooophy)

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

**Problems:**

1. It's a endless loop. `iter` never equal `mid`.
2. mid will be invalid after the `insert`.(see [issue 133](https://github.com/Mooophy/Cpp-Primer/issues/133))

**FIXED**:

```cpp
// cause the reallocation will lead the iterators and references
// after the insertion point to invalid. Thus, we need to call reserver at first.

#include <iostream>
#include <vector>

void double_and_insert(std::vector<int>& v, int some_val)
{
    auto mid = [&]{ return v.begin() + v.size() / 2; };
    for (auto curr = v.begin(); curr != mid(); ++curr)
        if (*curr == some_val)
            ++(curr = v.insert(curr, 2 * some_val));
}

int main()
{
    std::vector<int> v{ 1, 9, 1, 9, 9, 9, 1, 1 };
    double_and_insert(v, 1);

    for (auto i : v) 
        std::cout << i << std::endl;
}
```

The complete test codes, check [this](ex9_22.cpp).

## Exercise 9.23:
>In the first program in this section on page 346, what would
the values of val, val2, val3, and val4 be if c.size() is 1?

same value that equal to the first element's.

## [Exercise 9.24](ex9_24.cpp)

## Exercise 9.25:
>In the program on page 349 that erased a range of
elements, what happens if elem1 and elem2 are equal? What if elem2 or both elem1 and elem2 are the off-the-end iterator?

if elem1 and elem2 are equal, nothing happened.

if elem2 is the off-the-end iterator, it would delete from elem1 to the end.

if both elem1 and elem2 are the off-the-end iterator, nothing happened too.

## [Exercise 9.26](ex9_26.cpp)
## [Exercise 9.27](ex9_27.cpp)

## Exercise 9.28:
>Write a function that takes a forward_list<string> and two additional string arguments. The function should find the first string and insert the second immediately following the first. If the first string is not found, then insert the second string at the end of the list.

```cpp
void find_and_insert(forward_list<string> &list, string const& to_find, string const& to_add)
{
    auto prev = list.before_begin();
    for (auto curr = list.begin(); curr != list.end(); prev = curr++)
    {
        if (*curr == to_find)
        {
            list.insert_after(curr, to_add);
            return;
        }
    }
    list.insert_after(prev, to_add);
}
```

## Exercise 9.29:
>Given that vec holds 25 elements, what does
vec.resize(100) do? What if we next wrote vec.resize(10)?

```cpp
vec.resize(100);    // adds 75 elements of value 0 to the back of vec
vec.resize(10);     // erases 90 elements from the back of vec
```

## Exercise 9.30:
>What, if any, restrictions does using the version of resize
that takes a single argument place on the element type?

If the container holds elements of a class type and resize adds elements
we **must supply an initializer** or the element type must have a **default constructor**.

## Exercise 9.31 [use list](ex9_31_1.cpp) | [use forward_list](ex9_31_2.cpp)
## [Exercise 9.32](ex9_32.cpp)
## [Exercise 9.33](ex9_33.cpp)
## [Exercise 9.34](ex9_34.cpp)

## Exercise 9.35:
>Explain the difference between a vector’s capacity and its size.

The **size** of a container is the number of **elements** it already holds;

The **capacity** is how many elements it can hold before more **space** must be allocated.

## Exercise 9.36:
>Can a container have a capacity less than its size?

cannot.

## Exercise 9.37:
>Why don’t list or array have a capacity member?

`list` does not hold elements contiguously. `array` has the fixed size statically.

## [Exercise 9.38](ex9_38.cpp)

## Exercise 9.39:
>Explain what the following program fragment does:
```cpp
vector<string> svec;
svec.reserve(1024);
string word;
while (cin >> word)
    svec.push_back(word);
svec.resize(svec.size()+svec.size()/2);
```

The `while` loop will read words from `cin` and store them in out vector. Even if we initially reserved 1024 elements, if there are more words read from `cin`, our vector's capacity will be automatically increased (most implementations will double the previous capacity) to accommodate them.

And now comes the catch. `resize()` is different from `reserve()`. In this case `resize()` will add another `svec.size()/2` value initialized elements to `svec`. If this exceeds `svec.capacity()` it will also automatically increase it to accommodate the new elements.

## Exercise 9.40:
>If the program in the previous exercise reads 256 words, what is its likely capacity after it is resized? What if it reads 512? 1, 000? 1, 048?

read | size | capacity
------ | ------ | ------
256 | 384 | 1024
512 | 768 | 1024
1000 | 1500 | 2000(clang is 2048)
1048 | 1572 | 2048

## [Exercise 9.41](ex9_41.cpp)

## Exercise 9.42:
>Given that you want to read a character at a time into a string, and you know that you need to read at least 100 characters, how might you improve the performance of your program?

Use member `reserve(120)` to allocate enough space for this string. (@Mooophy)

## [Exercise 9.43](ex9_43.cpp)

## [Exercise 9.44](ex9_44.cpp)
## [Exercise 9.45](ex9_45.cpp)
## [Exercise 9.46](ex9_46.cpp)
## Exercise 9.47 [find_first_of](ex9_47_1.cpp) | [find_first_not_of](ex9_47_2.cpp)
## Exercise 9.48:
>Given the definitions of name and numbers on page 365,
what does numbers.find(name) return?

string::npos

## [Exercise 9.49](ex9_49.cpp)
## [Exercise 9.50](ex9_50.cpp)
## [Exercise 9.51](ex9_51.cpp)
## [Exercise 9.52](ex9_52.cpp)
