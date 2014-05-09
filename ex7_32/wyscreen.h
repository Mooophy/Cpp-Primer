//! @Alan
//!
//! Exercise 7.32:
//! Define your own versions of Screen and Window_mgr
//! in which clear is a member of Window_mgr and a friend of Screen.
//  steps:
//  First, define the Window_mgr class, which declares, but cannot
//  define, clear. Screen must be declared before clear can use the
//  members of Screen.
//
//  Next, define class Screen, including a friend declaration for clear.
//
//  Finally, define clear, which can now refer to the members in Screen.
//
#ifndef WYSCREEN_H
#define WYSCREEN_H

#include <iostream>
#include <string>


class wyScreen
{
    friend class wyScreen_mgr;

public:
    typedef std::string::size_type pos;


    //!  constructs:
    wyScreen() = default;
    wyScreen(const pos h, const pos w) : height(h), width(w), contents(" ", h * w) {  }
    wyScreen(const pos h, const pos w, char c) : height(h), width(w), contents(h * w, c){  }

    wyScreen &move(const pos r, const pos c);
    wyScreen &set(char c);
    wyScreen &set(pos r, pos col, char ch);

    wyScreen &display(std::ostream &os)
    {do_display(os);    return *this;}
    const wyScreen &display(std::ostream &os) const
    {do_display(os);    return *this;}

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    void do_display(std::ostream &os) const {os << contents;}
};

#endif // WYSCREEN_H
