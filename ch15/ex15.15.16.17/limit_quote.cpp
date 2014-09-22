#include "limit_quote.h"


void Limit_quote::debug() const
{
	Quote::debug();
    std::cout //<< "data members of this class:\n"
              << "max_qty= " << quantity << " "
              << "discount= " << discount<< " ";
}
