//! @Alan
//!
//! Exercise 7.23:
//! Write your own version of the Screen class.
//!
//! Exercise 7.24:
//! Give your Screen class three constructors:
//! a default constructor;
//! a constructor that takes values for height and width and initializes the contents
//! to hold the given number of blanks;
//! and a constructor that takes values for height, width, and a character to use as
//! the contents of the screen.
//!
//!
//!
//! Exercise 7.25:
//! Can Screen safely rely on the default versions of copy and assignment?
//! If so, why? If not, why not?
//!
//  The class below can rely on it. It goes in Section 7.1.5:"..the synthesized versions
//  are unlikely to work correctly for classes that allocate resources that reside outside
//  the class objects themselves. " and "Moreover, the synthesized versions for copy, assignment,
//  and destruction work correctly for classes that have vector or string members. " Hence
//  the class below which used only built-in type and strings can rely on the default
//  version of copy and assignment.
//!

#include <iostream>
#include <string>

class wyScreen
{
public:
    typedef std::string::size_type pos;

    //!  constructs:
    wyScreen() = default;
	wyScreen(const pos h, const pos w) : height(h), width(w), contents(h * w, ' ') { }
	wyScreen(const pos h, const pos w, const char c) : height(h), width(w), contents(h * w, c){ }

private:
    pos cursor = 0;
    pos height = 0, width = 0;

    std::string contents;
};

int main()
{
    return 0;
}

