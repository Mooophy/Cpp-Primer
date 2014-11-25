//
//  ex7_31.h
//  Exercise 7.31
//
//  Created by pezy on 11/17/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//

#ifndef CP5_ex7_31_h
#define CP5_ex7_31_h

class Y;

class X {
    Y* y = nullptr;
};

class Y {
    X x;
};

#endif
