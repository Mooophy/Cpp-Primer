//! @Alan
//!
//! Exercise 7.11:
//! Add constructors to your Sales_data class and write a program
//! to use each of the constructors.
//!
//! Exercise 7.12:
//! Move the definition of the Sales_data constructor that takes an
//! istream into the body of the Sales_data class.
//  ?1   How to access a non member function  within a constructor?
//  ?2   Is it a good practise to use a non member function for constructor?
//!
//! Exercise 7.13:
//! Rewrite the program from page 255 to use the istream constructor.
//!


#include <iostream>
#include <string>


struct wy_Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    //!
    //! @brief  Exercise 7.11
    //! @note   constructors
    //!
    wy_Sales_data() = default;                                  //default

    wy_Sales_data(const std::string &str) : bookNo(str) {}      //with bookNo

    wy_Sales_data(const std::string &str, unsigned uni, double prc) :
        bookNo(str), units_sold(uni), revenue(uni * prc){}      //with all

    //!
    //! \brief  Exercise 7.12
    //! \attention moved from outside of the class body
    //!
    wy_Sales_data(std::istream &is)
    {
        double price;
        is >> this->bookNo >> this->units_sold >> price;
        this->revenue = price * this->units_sold;
    }


    std::string isbn(void) const {return this->bookNo;}
    wy_Sales_data &combine (const wy_Sales_data &sd);
};

wy_Sales_data add    (const wy_Sales_data &lhs, const wy_Sales_data &rhs);
std::istream &read   (std::istream &is,    wy_Sales_data &sd);
std::ostream &print  (std::ostream &os, const wy_Sales_data &sd);


//!
//! \brief  Exercise 7.13
//! \note   using the istream constructor
//!
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

//!
//! @brief  Exercise 7.11
//! @note   definition for constructor
//! @attention  moved into the class body for ex7.12
//!
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
