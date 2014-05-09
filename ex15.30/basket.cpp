#include "basket.h"
double Basket::total_receipt(std::ostream &os) const
{
    double sum = 0.0;

    for(auto iter = items.cbegin(); iter != items.cend();
        iter = items.upper_bound(*iter))
        //!  ^^^^^^^^^^^^^^^^^^^^^^^^^^^
        //! @note   this increment moves iter to the first element with key
        //!         greater than  *iter.

    {
        sum += print_total(os, **iter, items.count(*iter));
    }                                   //! ^^^^^^^^^^^^^ using count to fetch
                                        //! the number of the same book.
    os << "Total Sale: " << sum << std::endl;
    return sum;
}
