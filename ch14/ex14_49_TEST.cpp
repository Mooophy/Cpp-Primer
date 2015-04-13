#include "ex14_49.h"

int main()
{
    Date date(12, 4, 2015);
    if (static_cast<bool>(date))
        std::cout << date << std::endl;
}
