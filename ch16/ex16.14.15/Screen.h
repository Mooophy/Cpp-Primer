//!
//! Exercise 16.14:
//! Write a Screen class template that uses nontype parameters to define the
//! height and width of the Screen.
//!

#ifndef SCREEN_H
#define SCREEN_H

#include <string>

template<unsigned H, unsigned W>
class Screen {
public:
    typedef std::string::size_type pos;
    Screen() = default; // needed because Screen has another constructor
    // cursor initialized to 0 by its in-class initializer
    Screen(char c):contents(ht * wd, c) { }
    char get() const              // get the character at the cursor
        { return contents[cursor]; }       // implicitly inline
    Screen &move(pos r, pos c);      // can be made inline later
private:
    pos cursor = 0;
    pos height = H, width = W;
    std::string contents;
};

#endif // SCREEN_H
