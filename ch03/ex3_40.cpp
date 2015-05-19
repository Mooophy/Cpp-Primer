// Warning: Visual Studio 2013 cannot support C99 VLA(http://en.wikipedia.org/wiki/Variable-length_array)
// please change compiler(such as gcc or clang) to run following codes.
// more discuss: https://github.com/Mooophy/Cpp-Primer/pull/241
// @pezy

#include <iostream>
#include <cstring>

int main()
{
    char cs1[] = "Hi";
    char cs2[] = "frank67";

    char cs3[strlen(cs1) + strlen(" ") + strlen(cs2) + 1];

    strcpy(cs3, cs1);
    strcat(cs3, " ");
    strcat(cs3, cs2);

    std::cout << cs3 << std::endl;
}
