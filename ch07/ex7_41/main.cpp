//! @Alan
//!
//! Exercise 7.41:
//! Rewrite your own version of the Sales_data class to use delegating constructors.
//! Add a statement to the body of each of the constructors that prints a message
//! whenever it is executed. Write declarations to construct a Sales_data object in
//! every way possible. Study the output until you are certain you understand the order
//! of execution among delegating constructors.
//!
//!
#include <iostream>
#include <string>
#include <wy_sales_data.h>




int main()
{
    //wy_Sales_data s;
    //wy_Sales_data s("", 1, 0.5);
    //wy_Sales_data s("UUU");
    wy_Sales_data s(std::cin);

    return 0;
}
