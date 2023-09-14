//
//  ex7_01.cpp
//  Exercise 7.1
//
//  Created by pezy on 14/10/30.
//
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl; using std::string;

struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double unit_price = 0.0;
    double revenue = 0.0;
};

int main()
{
    Sales_data total;
    if (cin >> total.bookNo >> total.units_sold >> total.unit_price)
    {
        total.revenue = total.units_sold * total.unit_price;
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> trans.unit_price) 
        {
            trans.revenue = trans.units_sold * trans.unit_price;
            if (total.bookNo == trans.bookNo) 
            {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
                total.unit_price = total.revenue / total.units_sold;
            }
            else
            {
                cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << total.unit_price << endl;
                total = trans;
            }
        }
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << total.unit_price << endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
