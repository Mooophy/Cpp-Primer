//
//  ex8_07.cpp
//  Exercise 8.7
//
//  Created by pezy on 11/28/14.
//
//  @Brief  Revise the bookstore program from the previous section to write its output to a file.
//          Pass the name of that file as a second argument to main.
//  @See    ex8_06.cpp
//  @Run    give a parameter: "../data/book.txt ../data/out.txt"

#include <fstream>
#include <iostream>

#include "../ch07/ex7_26.h"
using std::ifstream; using std::ofstream; using std::endl; using std::cerr;

int main(int argc, char **argv)
{
    ifstream input(argv[1]);
    ofstream output(argv[2]);
    
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
                print(output, total) << endl;
                total = trans;
            }
        }
        print(output, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }
    
    return 0;
}
