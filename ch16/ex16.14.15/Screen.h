//
// Exercise 16.14:
// Write a Screen class template that uses nontype parameters to define the
// height and width of the Screen.
//

#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>

template<unsigned H, unsigned W>
class Screen {
public:
    typedef std::string::size_type pos;
    Screen() = default; // needed because Screen has another constructor
    // cursor initialized to 0 by its in-class initializer
    Screen(char c):contents(H * W, c) { }
    char get() const              // get the character at the cursor
        { return contents[cursor]; }       // implicitly inline
    Screen &move(pos r, pos c);      // can be made inline later

    friend std::ostream & operator<< ( std::ostream &os , const Screen<H, W> & c ) 
    {
        unsigned int i, j;
        for( i=0 ;i<c.height; i++ )
        {
                os<<c.contents.substr(0, W)<<std::endl;
        }
        return os;
    }

    friend std::istream & operator>> ( std::istream &is , Screen &  c )
    {
            char a;
            is>>a;
            std::string temp(H*W, a);
            c.contents = temp;
            return is;
    }
private:
    pos cursor = 0;
    pos height = H, width = W;
    std::string contents;
};

template<unsigned H, unsigned W>
inline Screen<H, W>& Screen<H, W>::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}
#endif // SCREEN_H
