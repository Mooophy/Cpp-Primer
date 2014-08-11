/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       02  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 16.9:
//! What is a function template? What is a class template?
//  A function template is a formula from which we can generate type-specific
//  versions of that function.
//!
//  A class template is a blueprint for generating classes. Class templates
//  differ from function templates in that the compiler cannot deduce the
//  template parameter type(s) for a class template. Instead, as we’ve seen
//  many times, to use a class template we must supply additional information
//  inside angle brackets following the template’s name (§ 3.3, p. 97).
//!
//! Exercise 16.10:
//! What happens when a class template is instantiated?
//  The compiler uses these template arguments to instantiate a specific
//  class from the template.
//!
//! Exercise 16.11:
//! The following definition of List is incorrect. How would you fix it?
//  as commented below.
//!


#include <iostream>
#include <vector>
#include <list>
#include <string>


template <typename elemType> class ListItem;

template <typename elemType> class List
{
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType>& operator=(const List<elemType> &);
    ~List();
    void insert(ListItem<elemType> *ptr, elemType value);
    //!                 ^^^^^^^^^^  -- template is not a type
    //!                             the type must be provided

private:
    ListItem<elemType> *front, *end;
    //!      ^^^^^^^^ -- template is not a type
    //!                 the type must be provided
};


int main()
{

    return 0;
}

