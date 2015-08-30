/*
=================================================================================

C++ Primer 5th Exercise Answer Source Code

Sales_data

If you have questions, try to connect with me: pezy<urbancpz@gmail.com>

=================================================================================
*/

#ifndef CP5_ex14_45_h
#define CP5_ex14_45_h

#include <string>
#include <iostream>

class Sales_data {
    friend std::istream& operator>>(std::istream&, Sales_data&);
    friend std::ostream& operator<<(std::ostream&, const Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);

public:
    Sales_data(const std::string &s, unsigned n, double p):bookNo(s), units_sold(n), revenue(n*p){ }
    Sales_data() : Sales_data("", 0, 0.0f){ }
    Sales_data(const std::string &s) : Sales_data(s, 0, 0.0f){ }
    Sales_data(std::istream &is);

    Sales_data& operator=(const std::string&);
    Sales_data& operator+=(const Sales_data&);
    explicit operator std::string() const { return bookNo; }
    explicit operator double() const { return avg_price(); }

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
