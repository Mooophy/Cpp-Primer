#include "bulk_quote.h"

double Bulk_quote::net_price(std::size_t n) const
{
    return n * price * ( n >= min_qty ? 1 - discount : 1);
}

void Bulk_quote::debug() const
{
	Quote::debug();
    std::cout << "min_qty= " << this->min_qty << " "
              << "discount= " << this->discount<< " ";
}
