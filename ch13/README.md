# Chapter 13. Copy Control

## Exercise 13.1:
>What is a copy constructor? When is it used?

A copy constructor is a constructor which first parameter is a **reference** to the class type and any additional parameters have **default values**.

When copy initialization happens and that copy initialization requires either the copy constructor or the move constructor.

- Define variables using an `=`
- Pass an object as an argument to a parameter of nonreference type
- Return an object from a function that has a nonreference return type
- Brace initialize the elements in an array or the members of an aggregate class
- Some class types also use copy initialization for the objects they allocate.

## Exercise 13.2:
> Explain why the following declaration is illegal:
```cpp
Sales_data::Sales_data(Sales_data rhs);
```

If declaration like that, the call would never succeed to call the copy constructor, `Sales_data rhs` is an argument to a parameter, thus, we'd need to use the copy constructor to copy the argument, but to copy the argument, we'd need to call the copy constructor, and so on indefinitely.

## Exercise 13.3:
>What happens when we copy a `StrBlob`? What about `StrBlobPtrs`?

```cpp
// added a public member function to StrBlob and StrBlobPrts
long count() {
    return data.use_count(); // and wptr.use_count();
}

// test codes in main()
StrBlob str({"hello", "world"});
std::cout << "before: " << str.count() << std::endl; // 1
StrBlob str_cp(str);
std::cout << "after: " << str.count() << std::endl;  // 2

ConstStrBlobPtr p(str);
std::cout << "before: " << p.count() << std::endl; // 2
ConstStrBlobPtr p_cp(p);
std::cout << "after: " << p.count() << std::endl; // 2
```

when we copy a `StrBlob`, the `shared_ptr` member's use_count add one.

when we copy a `StrBlobPrts`, the `weak_ptr` member's use_count isn't changed.(cause the count belongs to `shared_ptr`)

## Exercise 13.4:
>Assuming Point is a class type with a public copy constructor, identify each use of the copy constructor in this program fragment:
```cpp
Point global;
Point foo_bar(Point arg) // 1. Pass an object as an argument to a parameter of nonreference type
{
    Point local = arg, *heap = new Point(global); // 2.3. copy initialization
    *heap = local; // 4. Define variables using an `=`
    Point pa[ 4 ] = { local, *heap }; // 5. Brace initialize the elements in an array
    return *heap; // 6. Return an object from a function that has a nonreference return type
}
```

## [Exercise 13.5](ex13_05.h)
