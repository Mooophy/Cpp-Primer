#include <iostream>
#include "include/Sales_item.h"

int main()
{
  Sales_item currItem, valItem;
  if (std::cin >> currItem)
  {
    int cnt = 1;
    while (std::cin >> valItem)
    {
      if (compareIsbn(valItem, currItem))
        ++cnt;
      else 
      {
        std::cout << currItem.isbn() << " occurs "
                  << cnt << " times " << std::endl;
        currItem = valItem;
        cnt = 1;
      }
    }
    
    std::cout << currItem.isbn() << " occurs "
              << cnt << " times " << std::endl;
  }
  return 0;
}

