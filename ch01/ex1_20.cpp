#include <iostream>
#include "include/Sales_item.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    for (Sales_item item; cin >> item; cout << item << endl);
    return 0;
}
