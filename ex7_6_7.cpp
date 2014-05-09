//! @Alan
//!
//! Exercise 7.6:
//! Define your own versions of the add, read, and print functions.
//!
//! Exercise 7.7:
//! Rewrite the transaction-processing program you wrote for the exercises in § 7.1.2 (p. 260)
//! to use these new functions.
//!

#include <iostream>
#include <string>

using namespace std;

struct wy_Sales_data
{
    std::string bookNo;
    unsigned units_sold = 1;
    double revenue = 5.7;

    std::string isbn(void) const {return this->bookNo;}

    wy_Sales_data &combine (const wy_Sales_data &sd);
};


//!
//! \brief add, read and print nonmember for Exercise 7.6
//!
wy_Sales_data add(const wy_Sales_data &lhs, const wy_Sales_data &rhs);
//!                                         ^^^^^
//! @attention This function returns a new wy_Sales_data boject. No
//!            write operation on the argument rhs.Thus a const was
//!            placed here.


istream &read   (istream &is,    wy_Sales_data &sd);
//!                          ^^^^
//! @attention Write operation is on the object sd reference to.
//!            Thus no const can be placed here.
//!


ostream &print  (ostream &os, const wy_Sales_data &sd);
//!                           ^^^^^
//! @attention no wirte opertion on the object, so const was placed.
//!

int main()
{
    wy_Sales_data total;

    if(read(cin,total) && total.bookNo.size()>1)
    {
        wy_Sales_data trans;

        while(read(cin, trans) && trans.bookNo.size()>1)
        {
            if(total.isbn() == trans.isbn())
            {
                total = add(total,trans);
            }
            else
            {
                print(cout,total);
                cout<<"\n";
                //!   ^^^^
                //! @attention As mentioned in the C++ primer, no format should be implemented
                //!            within class.Thus a "\n" was used here to format.
                //!

                total = trans;
            }
        }
        print(cout,total);
        cout<<"\n";
    }
    else
    {
        cerr << "No data?!" << endl;
    }

    return 0;
}

wy_Sales_data &wy_Sales_data::combine(const wy_Sales_data &sd)
{
    this->revenue += sd.revenue;
    this->units_sold += sd.units_sold;

    return *this;
}

//!
//! \brief add, read and print nonmember definitions for Exercise 7.6
//!
istream &read(istream &is, wy_Sales_data &sd)
{
    double price;
    is >> sd.bookNo >> sd.units_sold >> price;
    sd.revenue = price * sd.units_sold;

    return is;
}
ostream &print(ostream &os, const wy_Sales_data &sd)
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
