/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       22  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 15.11:
//! Add a virtual debug function to your Quote class hierarchy that displays
//! the data members of the respective classes.
//!

#include <iostream>
#include <string>

#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"

void print_debug(const Quote& q);
double print_total (std::ostream& os, const Quote& item, size_t n);
int main()
{
    Quote q("aaa",10.60);
    Bulk_quote bq("bbb",111,10,0.3);
    Limit_quote lq("ccc",222,10,0.3);

    /** @note   Not dynamic binding!
     *  The codes below are not dynamic binding. The compiler has known what the
     *  r refering to at compile time. As a result, the virtual function debug of
     *  the subobject is called.
     */
    Quote& r = q;
    r.debug();
	std::cout << "\n";
    r = bq;
    r.debug();
	std::cout << "\n";
    r = lq;
    r.debug();
	std::cout << "\n";


    std::cout << "====================\n";

    /** @note   dynamic binding!
     *  The below will happen dynamic binding. The reason might be that while  print_debug
     *  compiling the compiler compile it independly from the rest codes. The compiler has
     *  no idea what the paramter q refering to. Thus compiler will leave the decision to
     *  run time. That is, dynamic binding.
     *
     *  Once dynamic binding happens, the corresponding vertual function in derived class will
     *  be called rather than that of the subobject inside the derived object.
     *
     *  Anyway, the reference is essentially an address being passed.
     *
     */
    print_debug(q);
	std::cout << "\n";
    print_debug(lq);
	std::cout << "\n";
    print_debug(bq);
	std::cout << "\n";

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





