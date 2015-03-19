//
//  ex14_02.h
//  Exercise 14.2
//
//  Created by pezy on 3/9/15.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @See ex7_41.h
//  @Add overloaded input, output, addition, and compound-assignment operators

#ifndef CP5_ex14_02_h
#define CP5_ex14_02_h

#include <string>
#include <iostream>

class Sales_data {
    friend std::istream& operator>>(std::istream&, Sales_data&); // input
    friend std::ostream& operator<<(std::ostream&, const Sales_data&); // output
    friend Sales_data operator+(const Sales_data&, const Sales_data&); // addition

public:
    Sales_data(const std::string &s, unsigned n, double p):bookNo(s),units_sold(n),revenue(n*p){}
    Sales_data() : Sales_data("", 0, 0.0f){}
    Sales_data(const std::string &s) : Sales_data(s, 0, 0.0f){}
    Sales_data(std::istream &is);

    Sales_data& operator+=(const Sales_data&); // compound-assignment
    std::string isbn() const { return bookNo; }

private:
    inline double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::istream& operator>>(std::istream&, Sales_data&);
std::ostream& operator<<(std::ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);

inline double Sales_data::avg_price() const
{
    return units_sold ? revenue/units_sold : 0;
}

#endif
