//
//  ex8_08.cpp
//  Exercise 8.8
//
//  Created by pezy on 11/28/14.
//
//  @Brief  Revise the program from the previous exercise to append its output to its given file.
//          Run the program on the same output file at least twice to ensure that the data are preserved
//  @See    ex8_07.cpp
//  @Run    give a parameter: "../data/book.txt ../data/out.txt"

#include <fstream>
#include <iostream>

#include "../ch07/ex7_26.h"
using std::ifstream; using std::ofstream; using std::endl; using std::cerr;

int main(int argc, char **argv)
{
    ifstream input(argv[1]);
    ofstream output(argv[2], ofstream::app);
    
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
