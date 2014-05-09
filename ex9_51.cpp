//! @Alan
//!
//! Exercise 9.51:
//! Write a class that has three unsigned members representing year,
//! month, and day. Write a constructor that takes a string representing
//! a date. Your constructor should handle a variety of date formats,
//! such as January 1, 1900, 1/1/1900, Jan 1, 1900, and so on.
//!

#include <iostream>
#include <string>
#include <vector>

class wy_Date
{
public:
    wy_Date(const std::string &s);
    unsigned year;
    unsigned month;
    unsigned day;
};

int main()
{
    wy_Date d("99/21/3871");

    std::cout << d.day <<" "
                 <<d.month <<" "
                   <<d.year <<" ";

    return 0;
}

wy_Date::wy_Date(const std::string &s)
{
    unsigned format = 0;

    //! 1/1/1900
    if(s.find_first_of("/") != std::string::npos)
        format = 0x10;

    //! Jan 1, 1900
    if(s.find_first_of(",") >= 4 && s.find_first_of(",") != std::string::npos)
        format = 0x01;

    switch (format)
    {

    //! format = 1/1/1900
    case    0x10:
        day     = std::stoi( s.substr(0, s.find_first_of("/")));
        month   = std::stoi( s.substr(s.find_first_of("/") + 1, s.find_first_of("/") - s.find_last_of("/")));
        year    = std::stoi( s.substr(s.find_last_of("/")  + 1, 4));
        break;



    //! format = January 1, 1900  or Jan 1, 1900
    case    0x01:
        day     = std::stoi( s.substr(s.find_first_of("1234567890"), s.find_first_of(",") - s.find_first_of("1234567890" )));

        if( s.find("Jan") < s.size() )  month = 1;
        if( s.find("Feb") < s.size() )  month = 2;
        if( s.find("Mar") < s.size() )  month = 3;
        if( s.find("Apr") < s.size() )  month = 4;
        if( s.find("May") < s.size() )  month = 5;
        if( s.find("Jun") < s.size() )  month = 6;
        if( s.find("Jul") < s.size() )  month = 7;
        if( s.find("Aug") < s.size() )  month = 8;
        if( s.find("Sep") < s.size() )  month = 9;
        if( s.find("Oct") < s.size() )  month =10;
        if( s.find("Nov") < s.size() )  month =11;
        if( s.find("Dec") < s.size() )  month =12;

        year    = std::stoi( s.substr(s.find_last_of(" ") + 1,4));
        break;
    }



}
