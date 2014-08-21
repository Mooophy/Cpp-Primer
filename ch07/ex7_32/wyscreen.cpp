#include "wyscreen.h"

inline wyScreen &wyScreen::move(const pos r, const pos c)
{
    cursor = r * width + c;
    return *this;
}

inline wyScreen &wyScreen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline wyScreen &wyScreen::set(wyScreen::pos r, wyScreen::pos col, char ch)
{
    contents[r*width + col] = ch;
    return *this;
}
