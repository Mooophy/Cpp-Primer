/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       23  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 15.21:
//! Choose one of the following general abstractions containing a family of
//! types (or choose one of your own). Organize the types into an inheritance
//! hierarchy:
//!     (a) Graphical file formats (such as gif, tiff, jpeg, bmp)
//!     (b) Geometric primitives (such as box, circle, sphere, cone)
//!     (c) C++ language types (such as class, function, member function)
//!
//! Exercise 15.22:
//! For the class you chose in the previous exercise, identify some of the
//! likely virtual functions as well as public and protected members.
//!

#include <iostream>
#include <string>

#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"
#include "disc_quote.h"

//! just for 2D shape
class Shape
{
public:
    typedef std::pair<double, double>    Coordinate;

    Shape() = default;
    Shape(const std::string& n) :
        name(n) { }

    virtual double area()       const = 0;
    virtual double perimeter()  const = 0;

    virtual ~Shape() = default;
private:
    std::string name;
};

class Rectangle : public Shape
{
public:
    Rectangle() = default;
    Rectangle(const std::string& n,
              const Coordinate& a,
              const Coordinate& b,
              const Coordinate& c,
              const Coordinate& d) :
        Shape(n), a(a), b(b), c(c), d(d) { }

    ~Rectangle() = default;

protected:
    Coordinate  a;
    Coordinate  b;
    Coordinate  c;
    Coordinate  d;
};

class Square : public Rectangle
{
public:
    Square() = default;
    Square(const std::string& n,
           const Coordinate& a,
           const Coordinate& b,
           const Coordinate& c,
           const Coordinate& d) :
        Rectangle(n,a,b,c,d) { }

    ~Square() = default;
};


int main()
{

    return 0;
}
