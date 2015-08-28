#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H

#include "quote.h"

class Limit_quote : public Quote
{
public:
    Limit_quote();
    Limit_quote(const std::string& b, double p, std::size_t max, double disc):
        Quote(b, p), max_qty(max), discount(disc)    {   }

    double net_price(std::size_t n) const override
    { return n * price * (n < max_qty ? 1 - discount : 1 ); }

    void debug() const override;

private:
    std::size_t max_qty     = 0;
    double      discount    = 0.0;
};

#endif // LIMIT_QUOTE_H
