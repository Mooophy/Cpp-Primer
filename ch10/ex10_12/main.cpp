//! @Alan
//! Exercise 10.12:
//! Write a function named compareIsbn that compares the isbn() members of two Sales_data objects.
//! Use that function to sort a vector that holds Sales_data objects.
//!

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <wy_sales_data.h>

inline bool 
compareIsbn(const wy_Sales_data &sd1, const wy_Sales_data &sd2)
{
    return sd1.isbn().size() < sd2.isbn().size();
}


int main()
{
    wy_Sales_data d1("aa"), d2("aaaa"), d3("aaa"), d4("z"), d5("aaaaz");
    std::vector<wy_Sales_data> v ={d1,d2,d3,d4,d5};

    //! @note   the elements the iterators pointing to
    //!         must match the parameters of the predicate.
    std::sort(v.begin(), v.end(), compareIsbn);

    for(const auto &element : v)
        std::cout << element.isbn() << " ";
    std::cout <<"\n";

    return 0;
}
