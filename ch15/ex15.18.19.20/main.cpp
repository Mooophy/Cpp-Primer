/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       23  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 15.18:
// Given the classes from page 612 and page 613, and assuming each object
// has the type specified in the comments, determine which of these assignments
// are legal. Explain why those that are illegal aren’t allowed:
//
//     Base *p = &d1;  //  d1 has type Pub_Derv    --  legal   --right
//     p = &d2;        //  d2 has type Priv_Derv   --  illegal --right
//     p = &d3;        //  d3 has type Prot_Derv   --  illegal --right
//
//     p = &dd1;       //  dd1 has type Derived_from_Public    --  legal   --right
//     p = &dd2;       //  dd2 has type Derived_from_Private   --  illegal --right
//     p = &dd3;       //  dd3 has type Derived_from_Protected --  illegal --right
//
//      User code may use the derived-to-base conversion only if D inherits
//      publicly from B. User code may not use the conversion if D inherits
//      from B using either protected or private.
//
// Exercise 15.19:
// Assume that each of the classes from page 612 and page 613 has a member
// function of the form:
//
//          void memfcn(Base &b) { b = *this; }
//
// For each class, determine whether this function would be legal.
//
//  Member functions and friends of D can use the conversion to B regardless
//  of how D inherits from B. The derived-to-base conversion to a direct base
//  class is always accessible to members and friends of a derived class.
//  Hence, the 3 below are all legal:
//
//          Pub_Derv    --  legal   --right
//          Priv_Derv   --  legal   --right
//          Prot_Derv   --  legal   --right
//
//  Member functions and friends of classes derived from D may use the
//  derived-to-base conversion if D inherits from B using either public or
//  protected. Such code may not use the conversion if D inherits privately
//  from B.Hence:
//          Derived_from_Public    --  legal    --right
//          Derived_from_Private   --  illegal  --right
//          Derived_from_Protected --  legal    --right
//
// Exercise 15.20:
// Write code to test your answers to the previous two exercises.
//

#include <iostream>
#include <string>

#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"
#include "disc_quote.h"

class Base
{
public:
    void pub_mem();   // public member
protected:
    int prot_mem;     // protected member
private:
    char priv_mem;    // private member
};

struct Pub_Derv     : public    Base
{
    void memfcn(Base &b) { b = *this; }
};
struct Priv_Derv    : private   Base
{
    void memfcn(Base &b) { b = *this; }
};
struct Prot_Derv    : protected Base
{
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public      : public Pub_Derv
{
    void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Private     : public Priv_Derv
{
    //void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Protected   : public Prot_Derv
{
    void memfcn(Base &b) { b = *this; }
};

int main()
{
    Pub_Derv d1;
    Base *p = &d1;

    Priv_Derv d2;
    //p = &d2;

    Prot_Derv d3;
    //p = &d3;

    Derived_from_Public dd1;
    p = &dd1;

    Derived_from_Private dd2;
    //p =& dd2;

    Derived_from_Protected dd3;
    //p = &dd3;


    return 0;
}
