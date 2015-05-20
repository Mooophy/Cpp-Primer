// more discuss: https://github.com/Mooophy/Cpp-Primer/pull/241
// @frank67

#include <iostream>
#include <cstring>

const char cstr1[]="Hello";
const char cstr2[]="world!";

int main()
{
    constexpr size_t new_size = strlen(cstr1) + strlen(" ") + strlen(cstr2) +1;
    char cstr3[new_size];
    
    strcpy(cstr3, cstr1);
    strcat(cstr3, " ");
    strcat(cstr3, cstr2);
    
    std::cout << cstr3 << std::endl;
}
