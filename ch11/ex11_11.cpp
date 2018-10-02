//
//  ex11_11.cpp
//  Exercise 11.11
//
//  Created by pezy on 12/15/14.
//  Refactored by Yue Wang Oct,2015
//
//  Redefine bookstore without using decltype.
//

#include "../ch07/ex7_26.h"
#include <set>

auto less(Sales_data const& lhs, Sales_data const& rhs)
{
    return lhs.isbn() < rhs.isbn();
}

int main()
{
    using Less = bool (*)(Sales_data const&, Sales_data const&);
    std::multiset<Sales_data, Less> bookstore(less);

    return 0;
}
