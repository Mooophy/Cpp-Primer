#include "limit_quote.h"


void Limit_quote::debug() const
{
	Quote::debug();
    std::cout << "max_qty= " << this->max_qty << " "
              << "discount= " << this->discount<< " ";
}
