#include "limit_quote.h"

double Limit_quote::net_price(std::size_t n) const
{
  if (n > max_qty)
    return max_qty * price * discount + (n - max_qty) * price;
  else
    return n * discount *price;
}
