#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H

#include "quote.h"
class Disc_quote : public Quote
{
public:
    Disc_quote();
    Disc_quote(const std::string& b, double p, std::size_t q, double d) :
        Quote(b, p), quantity(q), discount(d)   { }

    virtual double net_price(std::size_t n) const override = 0;

protected:
    std::size_t quantity;
    double      discount;
};

#endif // DISC_QUOTE_H
