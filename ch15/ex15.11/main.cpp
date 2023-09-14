/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       22  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 15.11:
// Add a virtual debug function to your Quote class hierarchy that displays
// the data members of the respective classes.
//

#include <iostream>
#include <string>

#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"

void print_debug(const Quote& q);
double print_total (std::ostream& os, const Quote& item, size_t n);
int main()
{
    Quote q("aaa", 10.60);
    Bulk_quote bq("bbb", 111, 10, 0.3);
    Limit_quote lq("ccc", 222, 10, 0.3);

    /** @note   dynamic binding!
     */
    Quote* r = &q;
    r->debug();
	std::cout << "\n";
    r = &bq;
    r->debug();
	std::cout << "\n";
    r = &lq;
    r->debug();
	std::cout << "\n";


    std::cout << "====================\n";

    /** @note   dynamic binding!
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
