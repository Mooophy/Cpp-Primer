//
//  ex8_06.cpp
//  Exercise 8.6
//
//  Created by pezy on 11/27/14.
//
//  @Brief  Rewrite the bookstore program from ¡ì7.1.1 (p.256) to read its transactions from a file. 
//          Pass the name of the file as an argument to main (¡ì6.2.5, p.218). 
//  @See    ex7_26.h (use the Sales_data)
//  @Run    give a parameter: "../data/book.txt"
//  @Output 0-201-78345-X 5 110
//          0-201-78346-X 9 839.2 

#include <fstream>
#include <iostream>

#include "../ch07/ex7_26.h"
using std::ifstream; using std::cout; using std::endl; using std::cerr;

int main(int argc, char **argv)
{
    ifstream input(argv[1]);
    
    Sales_data total;
    if (read(input, total))
    {
        Sales_data trans;
        while (read(input, trans))
        {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }
    
    return 0;
}
