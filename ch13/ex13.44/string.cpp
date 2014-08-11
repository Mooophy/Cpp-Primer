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
String::String(const char *  const c) :
    elements    (nullptr),
    first_free  (nullptr),
    cap         (nullptr)
{
    auto p = c;
    char* newData = alloc.allocate(sizeof(p));

    std::uninitialized_copy(p, (p + sizeof(p)), newData);

    //! build the data structure
    elements = newData;
    cap = first_free = newData + sizeof(c);
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
