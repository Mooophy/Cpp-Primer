#include <iostream>
#include "include/Sales_item.h"

int main()
{
  Sales_item item, sum;
  while (std::cin >> item)
  {
    if (item.isbn() != sum.isbn())
    {
      if (!sum.isbn().empty())
        std::cout << sum << std::endl;
      sum = item;
    }
    else
      sum += item;
  }

 std::cout << sum << std::endl;

  return 0;
}
