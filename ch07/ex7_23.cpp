//
//  ex7_23.cpp
//  Exercise 7.23
//
//  Created by pezy on 11/14/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//

//#include "ex7_23.h"
#include "ex7_24.h"

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

Screen& Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}
