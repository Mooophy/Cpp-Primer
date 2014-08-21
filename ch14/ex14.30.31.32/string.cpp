/***************************************************************************
 *  @file       string.cpp
 *  @author     Alan.W
 *  @date       06  JAN 2014
 *  @remark
 ***************************************************************************/

#include "string.h"
#include <algorithm>
#include <iostream>



//! default constructor
String::String():
    elements    (nullptr),
    first_free  (nullptr),
    cap         (nullptr)
{}

//! constructor taking C-style string i.e. a char array terminated with'\0'.
String::String(const char *  const c)
{
    auto p = c;
    std::size_t len=0;
    while(*p++ != '\0') ++len;


    char* newData = alloc.allocate(len);

    std::uninitialized_copy(c, (c + len), newData);

    //! build the data structure
    elements = newData;
    cap = first_free = newData + len;
}

//! copy constructor
String::String(const String &s)
{
    char* newData = alloc.allocate(s.size());
    std::uninitialized_copy(s.begin(), s.end(), newData);

    //! build data structure
    elements = newData;
    cap = first_free = newData + s.size();

    std::cout << "Copy constructing......\n";
}

//! move constructor    -- 07.Jan.2014
String::String(String &&s) noexcept :
    elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;

    std::cout << "Move constructing......\n";
}

//! operator =  07 Jan 2014
String &String::operator =(const String &rhs)
{
    //! allocate and copy first for protection against self-assignment
    char* newData = alloc.allocate(rhs.size());
    std::uninitialized_copy(rhs.begin(), rhs.end(), newData);

    //! destroy and deallocate the lhs
    free();

    elements = newData;
    cap = first_free = newData + rhs.size();

    std::cout << "Assignmenting......\n";

    return *this;
}

//! move operator =  07 Jan 2014
String &String::operator =(String &&rhs) noexcept
{
    if(this != &rhs)
    {
        free();

        elements    = rhs.elements;
        first_free  = rhs.first_free;//! operator =  07 Jan 2014
        cap         = rhs.cap;

        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }

    std::cout << "Move Assigning......\n";

    return *this;
}

//! destructor
String::~String()
{
    free();
}



//! destory and deallocate
void String::free()
{
    if(elements)
    {
        //! destroy all elements
        std::for_each(&elements, &first_free, [&](const char* p){
            alloc.destroy(p);
        });

        alloc.deallocate(elements, cap - elements);
    }
}

//! added 10,jan.2014
std::ostream &operator <<(std::ostream &os, const String &s)
{
    for(char c : s )
    {
      std::cout << c;
    }


    return os;
}
