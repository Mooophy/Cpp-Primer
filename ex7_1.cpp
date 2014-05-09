//! @Alan
//!
//! Exercise 7.1:
//! Write a version of the transaction-processing program from § 1.6 (p. 24)
//! using the Sales_data class you defined for the exercises in § 2.6.1 (p. 72).
//!

#include <iostream>
#include <string>


using namespace std;

struct wy_Sales_data
{
    std::string bookNo;
    unsigned units_sold = 1;
    double revenue = 5.7;
};

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
                total.units_sold ++;
                total.revenue +=5.7;
            }
            else
            {
                cout<<total.bookNo<<":\ntotal sold="<<total.units_sold
                      <<"\ntotal revenue="<<total.revenue
                        <<std::endl;

                total = trans;
            }
        }

        cout<<total.bookNo<<":\ntotal sold="<<total.units_sold
              <<"\ntotal revenue="<<total.revenue
                <<std::endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }

    return 0;
}

