#ifndef QUOTE_H
#define QUOTE_H

#include <string>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &b, double p) :
        bookNo(b), price(p) { }

    std::string     isbn() const { return bookNo; }
    virtual double  net_price(std::size_t n) const { return n * price; }

    virtual ~Quote() = default;

private:
    std::string bookNo;

protected:
    double  price = 0.0;

};

#endif // QUOTE_H
