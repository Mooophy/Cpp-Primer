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

#ifndef SCREEN_H
#define SCREEN_H

#include <string>

class Screen {
public:
    typedef std::string::size_type pos;

	// Action is a type that can point to a member function of Screen
    // that returns a reference to a Screen and takes no arguments
	using Action = Screen&(Screen::*)();

    // constructor: build screen of given size containing all blanks
    Screen(pos ht = 0, pos wd = 0): contents(ht * wd, ' '), cursor(0), 
                                    height(ht), width(wd) { }
	friend int main();
	// data is a static member that returns a pointer to member
	static const std::string Screen::*data() 
	    { return &Screen::contents; }

	char get_cursor() const { return contents[cursor]; }
    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
private:
    std::string contents;
    pos cursor;
    pos height, width;

public:
	// cursor movement functions 
	// beware: these functions don't check whether the operation is valid
    Screen& home() { cursor = 0; return *this; }
    Screen& forward() { ++cursor; return *this; }
    Screen& back() { --cursor; return *this; }
    Screen& up() { cursor += height; return *this; }
    Screen& down() {cursor -= height; return *this; }

    // specify which direction to move; enum see XREF(enums)
    enum Directions { HOME, FORWARD, BACK, UP, DOWN };
    Screen& move(Directions);
private:
    static Action Menu[];      // function table
};

char Screen::get(pos r, pos c) const // declared as inline in the class
{
    pos row = r * width;      // compute row location
    return contents[row + c]; // return character at the given column
}

inline
Screen& Screen::move(Directions cm)
{
    // run the element indexed by cm on this object
    return (this->*Menu[cm])(); // Menu[cm] points to a member function
}

#endif

