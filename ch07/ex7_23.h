//
//  ex7_23.h
//  Exercise 7.23
//
//  Created by pezy on 11/14/14.
//

#ifndef CP5_ex7_23_h
#define CP5_ex7_23_h

#include <string>

class Screen {
    public:
        using pos = std::string::size_type;

        Screen() = default;
        Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c){ }

        char get() const { return contents[cursor]; }
        char get(pos r, pos c) const { return contents[r*width+c]; }

    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
};

#endif
