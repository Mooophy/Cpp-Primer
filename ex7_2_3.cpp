//! @Alan
//!
//! Exercise 7.2:
//! Add the combine and isbn members to the Sales_data class you wrote for
//! the exercises in § 2.6.2 (p. 76).
//!
//! Exercise 7.3:
//! Revise your transaction-processing program from § 7.1.1 (p. 256)
//! to use these members.
//!

#include <iostream>
#include <string>

using namespace std;

struct wy_Sales_data
{
    std::string bookNo;
    unsigned units_sold = 1;
    double revenue = 5.7;

    //!
    //! @brief   Exercise 7.2
    //! @note    combine and isbn members
    //!
    std::string isbn(void) const {return this->bookNo;}
    //! @attention         ^^^^^
    //  const placed following member function means to return a const this pointer.

    wy_Sales_data &combine (const wy_Sales_data &sd);
};
//!
//! @brief  Exercise 7.3
//! @note   ransaction-processing program revised.
//!
int main()
{
    wy_Sales_data total;

    if(cin>>total.bookNo && total.bookNo.size()>1)
    {
        wy_Sales_data trans;

        while(cin>>trans.bookNo && trans.bookNo.size()>1)
        {
            if(total.bookNo == trans.bookNo)
            {
                //! previous codes:
                //  total.units_sold ++;
                //  total.revenue +=5.7;

                total.combine(trans);
            }
            else
            {
                //! previous codes:
                //  cout<<total.bookNo

                cout<<total.isbn()
                   <<":\ntotal sold="<<total.units_sold
                  <<"\ntotal revenue="<<total.revenue
                 <<std::endl;

                total = trans;
            }
        }

        //! previous codes:
        //  cout<<total.bookNo

        cout<<total.isbn()
           <<":\ntotal sold="<<total.units_sold
          <<"\ntotal revenue="<<total.revenue
         <<std::endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }

    return 0;
}

//!
//! @brief   Exercise 7.2
//! @note    combine and isbn members,definitions.
//!
wy_Sales_data &wy_Sales_data::combine(const wy_Sales_data &sd)
{
    this->revenue += sd.revenue;
    this->units_sold += sd.units_sold;

    return *this;
}
