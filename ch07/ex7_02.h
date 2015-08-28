//
//  ex7_02.h
//  Exercise 7.2
//
//  Created by pezy on 14/11/8.
//

#ifndef CP5_ex7_02_h
#define CP5_ex7_02_h

#include <string>

struct Sales_data {
    std::string isbn() const { return bookNo; };
    Sales_data& combine(const Sales_data&);
    
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

#endif
