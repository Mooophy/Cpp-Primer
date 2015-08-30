/***************************************************************************
*  @file       main.cpp
*  @author     Yue Wang
*  @date       26  Feb 2014
*              Aug 2015
*  @remark     This code is for the exercises from C++ Primer 5th Edition
*  @note
***************************************************************************/
//
// Exercise 16.60:
// Explain how make_shared (§ 12.1.1, p. 451) works.
//
//  make_shared shoudl be a variadic template function that forwards all arguments to
//  underlying constructors that allocate and initializes an object in dynamic memory and
//  , at last, build a shared_ptr by wrapping the raw pointer.
//
// Exercise 16.61:
// Define your own version of make_shared.
//

#include <iostream>
#include <memory>
#include <string>

namespace ch16 //to differ from std::make_shared
{
    template <typename T, typename ... Args>
    auto make_shared(Args&&... args) -> std::shared_ptr<T>
    {
        return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
    }
}

struct Foo
{
    explicit Foo(int b) : bar(b){ }
    int bar;
};

int main()
{
    auto num = ch16::make_shared<int>(42);
    std::cout << *num << std::endl;

    auto str = ch16::make_shared<std::string>(10, 'c');
    std::cout << *str << std::endl;

    auto foo = ch16::make_shared<Foo>(99);
    std::cout << foo->bar << std::endl;
    
    return 0;
}
