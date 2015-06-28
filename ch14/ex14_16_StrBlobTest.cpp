#include "ex14_16_StrBlob.h"
#include <iostream>

int main()
{
    StrBlob sb{ "Hello", "World", "Pezy" };

    for (ConstStrBlobPtr iter = sb.cbegin(); iter != sb.cend(); iter.incr()) {
        std::cout << iter.deref() << " ";
    }
    std::cout << std::endl;
}
