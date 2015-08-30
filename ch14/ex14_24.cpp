#include "ex14_24.h"
#include <algorithm>

// constructor taking Size as days
// the argument must be within (0, 2^32)
Date::Date(Size days)
{
    // calculate the year
    Size y400 =  days/YtoD_400;
    Size y100 = (days - y400*YtoD_400)/YtoD_100;
    Size y4   = (days - y400*YtoD_400 - y100*YtoD_100)/YtoD_4;
    Size y    = (days - y400*YtoD_400 - y100*YtoD_100 - y4*YtoD_4)/365;
    Size d    =  days - y400*YtoD_400 - y100*YtoD_100 - y4*YtoD_4 - y*365;
    this->year = y400*400 + y100*100 + y4*4 + y;

    // check if leap and choose the months vector accordingly
    std::vector<Size>currYear
            = isLeapYear(this->year) ? monthsVec_l : monthsVec_n;

    // calculate day and month using find_if + lambda
    Size D_accumu = 0, M_accumu = 0;
    // @bug    fixed:  the variabbles above hade been declared inside the find_if as static
    //                 which caused the bug. It works fine now after being move outside.

    std::find_if(currYear.cbegin(), currYear.cend(), [&](Size m){

        D_accumu += m;
        M_accumu ++;

        if(d < D_accumu)
        {
            this->month =   M_accumu;
            this->day   =   d + m - D_accumu ;

            return true;
        }
        else
            return false;
    });
}

// construcotr taking iostream
Date::Date(std::istream &is, std::ostream &os)
{
    is >> day >> month >> year;

    if(is)
    {
        if(check(*this)) return;
        else
        {
            os << "Invalid input! Object is default initialized.";
            *this = Date();
        }
    }
    else
    {
        os << "Invalid input! Object is default initialized.";
        *this = Date();
    }

}

// copy constructor
Date::Date(const Date &d) :
    day(d.day), month(d.month), year(d.year)
{ }

// move constructor
Date::Date(Date&& d) NOEXCEPT :
    day(d.day), month(d.month), year(d.year)
{ std::cout << "copy moving"; }

// copy operator=
Date &Date::operator= (const Date &d)
{
    this->day   = d.day;
    this->month = d.month;
    this->year  = d.year;

    return *this;
}

// move operator=
Date &Date::operator =(Date&& rhs) NOEXCEPT
{
    if(this != &rhs)
    {
        this->day   = rhs.day;
        this->month = rhs.month;
        this->year  = rhs.year;
    }
    std::cout << "moving =";

    return *this;
}

// conver to days
Date::Size Date::toDays() const
{
    Size result = this->day;

    // check if leap and choose the months vector accordingly
    std::vector<Size>currYear
            = isLeapYear(this->year) ? monthsVec_l : monthsVec_n;

    // calculate result + days by months
    for(auto it = currYear.cbegin(); it != currYear.cbegin() + this->month -1; ++it)
        result += *it;

    // calculate result + days by years
    result += (this->year/400)      * YtoD_400;
    result += (this->year%400/100)  * YtoD_100;
    result += (this->year%100/4)    * YtoD_4;
    result += (this->year%4)        * YtoD_1;

    return result;
}

// member operators:   +=  -=

Date &Date::operator +=(Date::Size offset)
{
    *this = Date(this->toDays() + offset);
    return *this;
}

Date &Date::operator -=(Date::Size offset)
{
    if(this->toDays() > offset)
        *this = Date(this->toDays() - offset);
    else
        *this = Date();

    return *this;
}

// non-member operators:  <<  >>  -   ==  !=  <   <=  >   >=

std::ostream&
operator <<(std::ostream& os, const Date& d)
{
    os << d.day << " " << d.month << " " << d.year;
    return os;
}

std::istream&
operator >>(std::istream& is, Date& d)
{
    if(is)
    {
        Date input = Date(is, std::cout);
        if(check(input))    d = input;
    }
    return is;
}


int operator -(const Date &lhs, const Date &rhs)
{
    return lhs.toDays() - rhs.toDays();
}


bool operator ==(const Date &lhs, const Date &rhs)
{
    return (lhs.day   == rhs.day  ) &&
           (lhs.month == rhs.month) &&
           (lhs.year  == rhs.year )    ;
}


bool operator !=(const Date &lhs, const Date &rhs)
{
    return !(lhs == rhs);
}


bool operator < (const Date &lhs, const Date &rhs)
{
    return lhs.toDays() < rhs.toDays();
}


bool operator <=(const Date &lhs, const Date &rhs)
{
    return (lhs < rhs) || (lhs == rhs);
}


bool operator >(const Date &lhs, const Date &rhs)
{
    return !(lhs <= rhs);
}


bool operator >=(const Date &lhs, const Date &rhs)
{
    return !(lhs < rhs);
}


Date operator - (const Date &lhs, Date::Size rhs)
{                                       //  ^^^ rhs must not be larger than 2^32-1
    // copy lhs
    Date result(lhs);
    result -= rhs;

    return result;
}


Date operator + (const Date &lhs, Date::Size rhs)
{                                       //  ^^^ rhs must not be larger than 2^32-1
    // copy lhs
    Date result(lhs);
    result += rhs;

    return result;
}
