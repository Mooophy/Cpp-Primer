#include <iostream>
#include "include/Sales_item.h"

int main()
{
  Sales_item total;
  if (std::cin >> total)
  {
    Sales_item trans;
    while (std::cin >> trans)
    {
      if (compareIsbn(total, trans))
        total += trans;
      else
      {
        std::cout << total << std::endl;
        total = trans;
      }
    }
    std::cout << total << std::endl;
  }
  else
  {
    std::cerr << "No data?!" << std::endl;
    return -1;
  }

  return 0;
}
