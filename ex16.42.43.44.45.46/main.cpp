/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       07  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 16.42:
//! Determine the type of T and of val in each of the following calls:
//!     template <typename T> void g(T&& val);
//!     int i = 0; const int ci = i;
//!     (a) g(i);
//  since i is lvalue, T is deduced as int&, val is int& && collapsing to int&
//!     (b) g(ci);
//  since ci is lvaue, T is deduced as const int&, val is const int& && collapsing to const int&
//!     (c) g(i * ci);
//  since i * ci is rvalue, T is deduced as int&&, val is int&& && colapsing to int&&
//!
//! Exercise 16.43:
//! Using the function defined in the previous exercise, what would the template
//! parameter of g be if we called g(i = ci)?
//      (i = ci) returns lvalue refering to the object i.
//      Hence T is deduced as int& val is int& && .
//      any change on val changes the object i.
//!
//! Exercise 16.44:
//! Using the same three calls as in the first exercise, determine the types for T
//! if g’s function parameter is declared as T (not T&&).
//                                           ^
//      g(i);       --  T is deduced as int
//      g(ci);      --  T is deduced as int, const is ignored.
//      g(i * ci);  --  T is deduced as int, (i * ci) returns rvalue which is copied to
//                      T
//! What if g’s function parameter is const T&?
//                                    ^^^^^^^^
//      g(i)        --  T is deduced as int  , val : const int&
//      g(ci)       --  T is deduced as int  , val : const int&
//      g(i * ci)   --  T is deduced as int&&, val : const int&& & collapse to const int&
//!
//! Exercise 16.45:
//! Given the following template, explain what happens if we call g on a literal value
//! such as 42. What if we call g on a variable of type int?
//!     template <typename T> void g(T&& val) { vector<T> v; }
//!
//! Discussion on SO:
//  http://stackoverflow.com/questions/21624016/when-a-lvalue-is-passed-to-t-what-will-happen
//!
//!     relevant section from textbook:
//! When we pass an lvalue (e.g., i) to a function parameter that is an rvalue reference to a
//! template type parameter (e.g, T&&), the compiler deduces the template type parameter as the
//! argument’s lvalue reference type. So, when we call f3(i), the compiler deduces the type of
//! T as int&, not int.
//!         --  P.688
//!
//! In this case, when calling on a literal value,say 42. int&& && will collapse to int&&. At last
//! T is deduced as int. Hence std::vector<T> is instantiated as std::vector<int> which is legal.
//!
//! When calling on a variable int. T will be deduced as int&. int & && will collapse to int&.
//! std::vector<int&> is not legal. The reason why int& can't be element of a vector can be found at:
//  http://stackoverflow.com/questions/922360/why-cant-i-make-a-vector-of-references
//!
//! Exercise 16.46:
//! Explain this loop from StrVec::reallocate in § 13.5 (p. 530):
//!
//!         for (size_t i = 0; i != size(); ++i)
//!             alloc.construct(dest++, std::move(*elem++));
//!
//! In each iteration, the dereference operator * returns a lvalue which is changed to rvalue by
//! std::move ,becasue the member function construct takes rvalue reference rather than lvalue
//! reference.
//!




#include <iostream>
#include <vector>
#include <string>

template <typename T>
void g(T&& val)
{
    std::vector<T> v;
}

int main()
{
    std::allocator a;
    a.construct
}
