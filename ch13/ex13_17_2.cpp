//
//  ex13_17.cpp
//  Exercise 13.17
//
//  Created by pezy on 1/15/15.
//  Copyright (c) 2015 pezy. All rights reserved.
//
//  Write versions of numbered and f corresponding to the previous three exercises
//  and check whether you correctly predicted the output.
//
//  For 13.15

#include <iostream>

class numbered {
public:
    numbered() {
        mysn = unique++;
    }

    numbered(const numbered& n) {
        mysn = unique++;
    }

    int mysn;
    static int unique;
};

static int unique = 10;

void f(numbered s) {
    std::cout << s.mysn << std::endl;
}

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
}

// output
// 13
// 14
// 15
