#ifndef ITEM_DATA_H
#define ITEM_DATA_H
#include <string>
#include <iostream>

using namespace std;

struct Book_data
{
    string book_no;
    unsigned sale_num;
    float price;
    double revenue;

  // Get input data from CLI
    int GetData()
    {
        cout << "Book No.: " << endl;
        cin >> book_no;
        cout << "sale num.: " << endl;
        cin >> sale_num;
        cout << "Book price.: " << endl;
        cin >> price;
        cout << "--------------------------------------------------------------" << endl;
        revenue = price * sale_num;

        if (book_no != "")
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

  // Show book sale data to CLI.
    int Show_data()
    {
        cout << "Book No.\tSold Number\tTotal\tAve. Price" << endl;
        cout << book_no << "\t\t" << sale_num << "\t\t" <<
            revenue << "\t" << revenue / sale_num << endl;
        cout << "================================================================" << endl;

        return 1;
    }

  // Set values to members of Book_data object
    int Set_data(Book_data src)
    {
        if (src.book_no != "")
        {
            book_no = src.book_no;
            price = src.price;
            sale_num = src.sale_num;
            revenue = src.revenue;

            return 1;
        }
        else
        {
            return 0;
        }
    }
};
#endif
