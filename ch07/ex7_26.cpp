//! @Alan
//!
//! Exercise 7.26:
//! Define Sales_data::avg_price as an inline function.
//!
//!

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
    //! constructors:
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

    //! member functions:
    std::string isbn(void) const {return this->bookNo;}
    wy_Sales_data &combine (const wy_Sales_data &sd);

    inline double avgPrice() const {return units_sold ? revenue : 0;}
};

//! friend:
wy_Sales_data add    (const wy_Sales_data &lhs, const wy_Sales_data &rhs);
std::istream &read   (std::istream &is,    wy_Sales_data &sd);
std::ostream &print  (std::ostream &os, const wy_Sales_data &sd);


int main()
{
    std::cout << "Please enter the first book:\n";
    wy_Sales_data total(std::cin);
    while(true)
    {
        std::cout << "Please enter the next book:\n";
        wy_Sales_data trans(std::cin);

        if(total.isbn() == trans.isbn())
        {
            total = add(total, trans);
        }
        else
        {
            print(std::cout,total);
            std::cout<<"\n";
            total = trans;
        }
    }
    return 0;
}

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
