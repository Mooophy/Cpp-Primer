/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/ 

#include <string>
#include <iostream>

class Screen {
public:
    typedef std::string::size_type pos;
	Screen() = default;  // needed because Screen has another constructor
	// cursor initialized to 0 by its in-class initializer
    Screen(pos ht, pos wd, char c): height(ht), width(wd), 
	                                contents(ht * wd, c) { }
	friend class Window_mgr;
    Screen(pos ht = 0, pos wd = 0): 
       cursor(0), height(ht), width(wd), contents(ht * wd, ' ') { }
    char get() const              // get the character at the cursor
	    { return contents[cursor]; }       // implicitly inline
    inline char get(pos ht, pos wd) const; // explicitly inline
	Screen &clear(char = bkground);
private:
	static const char bkground = ' ';
public:
    Screen &move(pos r, pos c);      // can be made inline later
    Screen &set(char);
    Screen &set(pos, pos, char);
    // display overloaded on whether the object is const or not
    Screen &display(std::ostream &os) 
                  { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const
                  { do_display(os); return *this; }
private:
     // function to do the work of displaying a Screen
     void do_display(std::ostream &os) const {os << contents;}
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

Screen &Screen::clear(char c) 
{
	contents = std::string(height*width, c);
	return *this;
}

inline                   // we can specify inline on the definition
Screen &Screen::move(pos r, pos c)
{
    pos row = r * width; // compute the row location
    cursor = row + c;    // move cursor to the column within that row
    return *this;        // return this object as an lvalue
}

char Screen::get(pos r, pos c) const // declared as inline in the class
{
    pos row = r * width;      // compute row location
    return contents[row + c]; // return character at the given column
}

inline Screen &Screen::set(char c) 
{ 
    contents[cursor] = c; // set the new value at the current cursor location
    return *this;         // return this object as an lvalue
}
inline Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;  // set specified location to given value
	return *this;                  // return this object as an lvalue
}

