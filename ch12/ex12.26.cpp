/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Alan.W
 *  @date       26  DEC 2013
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
    std::string word;
    while(std::cin >> word && p_movable != p + 3)
    {
        alloc.construct(p_movable,word);
        ++p_movable;
    }

    //! move the movable pointer back home
    p_movable = p;

    //! print the strings constructed.
    while(p_movable != p + 3){
        std::cout << *p_movable <<"\n";
        alloc.destroy(p_movable);
        ++p_movable；
    }

    //! free the allocated memory.
    alloc.deallocate(p, 5);



    return 0;
}
