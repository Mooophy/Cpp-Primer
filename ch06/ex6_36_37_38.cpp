//! @Alan
//!
//! Exercise 6.36:
//! Write the declaration for a function that returns a reference to an array of ten strings,
//! without using either a trailing return, decltype, or a type alias.
//!
//! Exercise 6.37:
//! Write three additional declarations for the function in the previous exercise.
//! One should use a type alias,
//! one should use a trailing return,
//! and the third should use decltype.
//! Which form do you prefer and why?
//  typedef.
//  Because it's easy to understand and seems similar in C which I got a bit more experience.
//!
//! Exercise 6.38:
//! Revise the arrPtr function on to return a reference to the array.
//!


#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;


//!
//! @brief  Exercise 6.38
//! @note   a function that returns a reference to an array
//!
int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};
decltype(even)& arrRef(int i)
{
    return (i%2)? odd : even;
}

//!
//! @brief  Exercise 6.37
//! @param  using decltype
//!
string arrStr[10];
decltype(arrStr)& func4(int i);


//!
//! @brief  Exercise 6.37
//! @note   using a trailing alias
//!
auto func3(int i) -> string (&)[10];

//!
//! @brief  Exercise 6.37
//! @note   using a type alias
//!
typedef string arrStrT[10];
arrStrT& func2(int i);

//!
//! @brief  Exercise 6.36
//! @note   a function that returns a reference to an array of ten strings
//!
string (&func(int i))[10];


int main()
{

}
