#ifndef WY_SALES_DATA_H
#define WY_SALES_DATA_H

//! @Alan
//!
//! Exercise 7.41:
//! Rewrite your own version of the Sales_data class to use delegating constructors.
//! Add a statement to the body of each of the constructors that prints a message
//! whenever it is executed.
//! Write declarations to construct a Sales_data object in
//! every way possible. Study the output until you are certain you understand the order
//! of execution among delegating constructors.

#include <iostream>
#include <string>

class wy_Sales_data
{
    friend wy_Sales_data add    (const wy_Sales_data &lhs, const wy_Sales_data &rhs);
    friend std::istream &read   (std::istream &is,    wy_Sales_data &sd);
    friend std::ostream &print  (std::ostream &os, const wy_Sales_data &sd);

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

public:
    //! previous constructors:
    /*
    wy_Sales_data() = default;                                  //default
    //wy_Sales_data() : units_sold(0) , revenue(0){}
    wy_Sales_data(const std::string &str) : bookNo(str) {}      //with bookNo
    wy_Sales_data(const std::string &str, unsigned uni, double prc) :
        bookNo(str), units_sold(uni), revenue(uni * prc){}      //with all
    wy_Sales_data(std::istream &is)
    {
        double price;
        is >> this->bookNo >> this->units_sold >> price;
        this->revenue = price * this->units_sold;
    }
    */
    //! delegating constructors:
    wy_Sales_data(const std::string &str, unsigned uni, double prc) :
        bookNo(str), units_sold(uni), revenue(uni * prc){std::cout<<"The non delegating one\n";}      //non delegating

    wy_Sales_data() : wy_Sales_data("", 0,0.0)    {std::cout<<"The default one\n";}
    wy_Sales_data(const std::string &str) : wy_Sales_data(str, 0, 0.0){std::cout<<"that with the &str\n";}
    wy_Sales_data(std::istream &is) : wy_Sales_data("", 0,0.0)
    {
        double price;
        is >> this->bookNo >> this->units_sold >> price;
        this->revenue = price * this->units_sold;
        std::cout<<"that with the IO\n";
    }


    //! member functions:
    std::string isbn(void) const {return this->bookNo;}
    wy_Sales_data &combine (const wy_Sales_data &sd);

    inline double avgPrice() const {return units_sold ? revenue : 0;}
};

//! friend:
wy_Sales_data add    (const wy_Sales_data &lhs, const wy_Sales_data &rhs);
std::istream &read   (std::istream &is,    wy_Sales_data &sd);
std::ostream &print  (std::ostream &os, const wy_Sales_data &sd);



/*
wy_Sales_data::wy_Sales_data( std::istream &is)
{
    read(is,*this);
}
*/

wy_Sales_data &wy_Sales_data::combine(const wy_Sales_data &sd)
{
    this->revenue += sd.revenue;
    this->units_sold += sd.units_sold;

    return *this;
}

std::istream &read(std::istream &is, wy_Sales_data &sd)
{
    double price;
    is >> sd.bookNo >> sd.units_sold >> price;
    sd.revenue = price * sd.units_sold;

    return is;
}

std::ostream &print(std::ostream &os, const wy_Sales_data &sd)
{
    os << sd.isbn() << " "
       << sd.revenue << " "
       << sd.units_sold;

    return os;
}

wy_Sales_data add(const wy_Sales_data &lhs, const wy_Sales_data &rhs)
{
    wy_Sales_data sum =lhs;
    sum.combine(rhs);
    return sum;
}

#endif // WY_SALES_DATA_H
