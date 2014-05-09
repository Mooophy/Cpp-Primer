/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       26  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//!
//! Exercise 16.60:
//! Explain how make_shared (§ 12.1.1, p. 451) works.
//!
//  make_shared shoudl be a variadic template member which forward all of fun's arguments to
//  the underlying functions that allocate and initializes an object in dynamic memory and
//  return a shared_ptr.
//!
//! Exercise 16.61:
//! Define your own version of make_shared.
//!


#include <iostream>
#include <memory>

//! ex 16.61 my version makeshared
template <typename T, typename ... Args>
std::shared_ptr<T> wy_make_shared(Args&&...);

int main()
{
    auto p = wy_make_shared<int>(42);
    std::cout << *p  << std::endl;

    auto p2= wy_make_shared<std::string>(10,'c');
    std::cout << *p2  << std::endl;

}

template <typename T, typename ... Args>
inline std::shared_ptr<T>
wy_make_shared(Args&&... args)
{
    std::shared_ptr<T> ret( new T(std::forward<Args>(args)...));
    return ret;
}
