#include <iostream>
#include "include/Sales_item.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main()
{
    Sales_item item1, item2;
    cin >> item1 >> item2;
    if (item1.isbn() == item2.isbn())
        cout << item1 + item2 << endl;
    else
        cerr << "Different ISBN." << endl;
}
