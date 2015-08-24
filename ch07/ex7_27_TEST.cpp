//
//  ex7_27_TEST.cpp
//  Test of Exercise 7.27
//
//  Created by pezy on 11/14/14.
//

#include "ex7_27.h"

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n";

    return 0;
}
