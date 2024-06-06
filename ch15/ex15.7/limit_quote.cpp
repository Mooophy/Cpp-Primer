#include "limit_quote.h"

double Limit_quote::net_price(std::size_t n) const
{
  if (n > max_qty)
    return (n - max_qty * discount) * price;
  else
    return n * price * (1 - discount);
}
