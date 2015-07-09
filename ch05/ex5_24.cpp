#include <iostream>
#include <stdexcept>

//
//  When a zero entered, the code below would crash with feedback as :
//  "Unhandled exception at 0x75834598 in just_for_cpp.exe: Microsoft C++ exception: std::runtime_error at memory location 0x0054F9F4."
//  
//  Tested on Windows 8.1 + Vs 2013
//

int main(void)
{
    int i, j;
    std::cin >> i >> j;
    if (j == 0)
        throw std::runtime_error("divisor is 0");
    std::cout << i / j << std::endl;

    return 0;
}
