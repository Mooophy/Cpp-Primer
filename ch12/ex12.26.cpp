/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     @Yue Wang @gupenghu
 *  @date       29.11.2014
 *  @remark
 ***************************************************************************/

//!
//! Exercise 12.26:
//! Rewrite the program on page 481 using an allocator.
//!

#include <iostream>
#include <memory>
int main()
{
    //! create a allocator object and use it to handle string.
    //! create a movable pointer to the address p points
    std::allocator<std::string> alloc;
    std::string* const p = alloc.allocate(5);
    std::string* p_movable = p;

    //! constuct each object using copy constructor
    std::cout << "enter 4 times\n";
    for(std::string word ;std::cin >> word and p_movable != p + 3; ++p_movable)
        alloc.construct(p_movable,word);

    //! move the movable pointer back home
    p_movable = p;

    //! print the strings constructed.
    for( ;  p_movable != p + 3; ++p_movable){
        std::cout << *p_movable <<"\n";
        alloc.destroy(p_movable);
    }

    //! free the allocated memory.
    alloc.deallocate(p, 5);
    std::cout << "exit normally\n";
    return 0;
}
//! output
//!
//enter 4 times
//ss
//ss
//ss
//ss
//ss
//ss
//ss
//exit normally
