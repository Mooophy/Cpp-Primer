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
//  See 13.14, 13.15, 13.16

#include <iostream>

class numbered {
public:
    // 13.14
    numbered() {
        static int unique = 10;
        mysn = unique++;
    }

    // 13.15
    numbered(const numbered& n) {
        mysn = n.mysn + 1;
    }

    int mysn;
};

// 13.16
void f(const numbered& s) {
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
// 10
// 11
// 12
