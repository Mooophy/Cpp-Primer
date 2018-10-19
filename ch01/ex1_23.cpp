#include <iostream>
#include "include/Sales_item.h"

int main()
{
    Sales_item currItem, valItem;
    if (cin >> currItem)
    {
        int cnt = 1;
        while (cin >> valItem)
        {
            if (valItem.isbn() == currItem.isbn())
            {
                ++cnt;
            }
            else
            {
                cout << currItem << " occurs " << cnt << " times " << std::endl;
                currItem = valItem;
                cnt = 1;
            }
        }
        cout << currItem << " occurs "<< cnt << " times " << std::endl;
    }
    return 0;
}
