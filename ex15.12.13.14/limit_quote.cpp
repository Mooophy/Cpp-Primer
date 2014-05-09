#include "limit_quote.h"


void Limit_quote::debug() const
{
    std::cout << "data members of this class:\n"
              << "max_qty= " << this->max_qty << " "
              << "discount= " << this->discount<< " \n";
}
