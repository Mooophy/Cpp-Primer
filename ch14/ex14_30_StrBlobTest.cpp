#include "ex14_30_StrBlob.h"
#include <iostream>

int main()
{
    StrBlob sb1{ "a", "b", "c" };
    StrBlob sb2 = sb1;

    sb2[2] = "b";

    if (sb1 > sb2) {
        for (ConstStrBlobPtr iter = sb1.cbegin(); iter != sb1.cend(); ++iter)
            std::cout << *iter << " ";
        std::cout << std::endl;
    }

    ConstStrBlobPtr iter(sb2);
    std::cout << iter->size() << std::endl;
}
