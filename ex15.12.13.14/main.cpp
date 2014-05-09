/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       22  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 15.12:
//! Is it ever useful to declare a member function as both override and final?
//! Why or why not?
//  Sure. override means overriding the same name virtual function in base class.
//  final means preventing any overriding this virtual function by any derived classes
//  that are more lower at the hierachy .
//!
//! Exercise 15.13:
//! Given the following classes, explain each print function:
//! If there is a problem in this code, how would you fix it?
//!
//! Exercise 15.14:
//! Given the classes from the previous exercise and the following objects,
//! determine which function is called at run time:
//!


#include <iostream>
#include <string>

#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"


class base
{
public:
   std::string name() { return basename; }
   virtual void print(std::ostream &os) { os << basename; }
   //!     ~~~~~^^^^^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   //!  The print here just output the basename of the base.
private:
   std::string basename = "base\n";
};

class derived : public base
{
public:
   void print(std::ostream &os) { base::print(os); os << " derived\n " << i; }
   //!  ^^^^^                     ^^^^^^    --  added to fix this problem
   //!  this print wanted to call the print from the base class.
   //!  however,the class scope base:: was omitted.As a result
   //!  it will cause an infinit recursion.


private:
   int i;
};


void print_debug(const Quote& q);
double print_total (std::ostream& os, const Quote& item, size_t n);
int main()
{
    //! ex15.14
    base bobj;
    base *bp1 = &bobj;
    base &br1 = bobj;
    derived dobj;
    base *bp2 = &dobj;
    base &br2 = dobj;

    //! a.  this is an object, so compile tiem.
    //bobj.print(std::cout);

    //! b.  this is an object, so compile tiem.
    //dobj.print(std::cout);

    //! c.  function name is not virtual , so no dynamic
    //!     binding happens.so conpile time
    //std::cout << bp1->name();

    //! d.  function name is not virtual , so no dynamic
    //!     binding happens.so conpile time
    //std::cout << bp2->name();

    //! e.  run time
    //br1.print(std::cout);

    //! f.  run time
    br2.print(std::cout);


    return 0;
}

double print_total(std::ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);

    os << "ISBN:" << item.isbn()
       << "# sold: " << n << " total due: " << ret << std::endl;

    return ret;
}


void print_debug(const Quote &q)
{
    q.debug();
}





