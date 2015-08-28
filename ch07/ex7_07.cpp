//
//  ex7_07.cpp
//  Exercise 7.7
//
//  Created by pezy on 11/8/14.
//

#include "ex7_06.h"

int main()
{
    Sales_data total;
    if (read(std::cin, total))
    {
        Sales_data trans;
        while (read(std::cin, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    
    return 0;
}
