/***************************************************************************
 *  @file       string.h
 *  @author     Alan.W
 *  @date       06  JAN 2014
 *  @remark
 ***************************************************************************/
//!
//! Exercise 13.44:
//! Write a class named String that is a simplified version of the library string
//! class. Your class should have at least a default constructor and a constructor
//! that takes a pointer to a C-style string. Use an allocator to allocate memory
//! that your String class uses.
//!

#ifndef STRING_H
#define STRING_H

#include <memory>

/**
 * @brief std::string like class without template
 *
 *        design:
 *
 *        [0][1][2][3][unconstructed chars][unallocated memory]
 *        ^           ^                    ^
 *        elements    first_free           cap
 */
class String
{
public:
    //! Big 3
    String();

    //! constructor taking C-style string i.e. a char array terminated with'\0'.
    explicit String(const char * const c);

    ~String();




private:

    //! data members
    char* elements;
    char* first_free;
    char* cap;

    std::allocator<char> alloc;

    //! utillities for big 3
    void free();

};

#endif // STRING_H
