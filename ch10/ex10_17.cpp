// @pezy
//
// Exercise 10.17
// Rewrite exercise 10.12 from ¡ì 10.3.1 (p. 387) 
// to use a lambda in the call to sort instead of the compareIsbn function. 
//
// @See 7.26, 10.12

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../ch07/ex7_26.h"     // Sales_data class.

int main()
{
    Sales_data d1("aa"), d2("aaaa"), d3("aaa"), d4("z"), d5("aaaaz");
    std::vector<Sales_data> v{ d1, d2, d3, d4, d5 };

    std::sort(v.begin(), v.end(), [](const Sales_data &sd1, const Sales_data &sd2){
        return sd1.isbn().size() < sd2.isbn().size();
    });

    for(const auto &element : v)
        std::cout << element.isbn() << " ";
    std::cout << std::endl;

    return 0;
}
