//
//  ex14_13.cpp
//  Exercise 14.13
//
//  Created by pezy on 3/9/15.
//  Substraction and compound-substraction operations added by hoeselm on 4/10/16.
//
//  @Brief implementation of class Sales_data
//  @See ex14_13.h

#include "ex14_13.h"

Sales_data::Sales_data(std::istream &is) : Sales_data()
{
    is >> *this;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}


Sales_data& Sales_data::operator-=(const Sales_data &rhs)
{
    units_sold -= rhs.units_sold;
    revenue -= rhs.revenue;
    return *this;
}

std::istream& operator>>(std::istream &is, Sales_data &item)
{
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    if (is)
        item.revenue = price * item.units_sold;
    else
        item = Sales_data();
    return is;
}

std::ostream& operator<<(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum -= rhs;
    return sum;
}
