#include "ex14_13.h"

int main()
{
  Sales_data s1("book1", 150, 10);
  Sales_data s2("book1", 200, 20);

  std::cout << s1 << std::endl;

  // Assignment
  s1 = s1 + s2;
  std::cout << s1 << std::endl;

  // Compound assignment
  s1 += s2;
  std::cout << s1 << std::endl;

  // Compound substraction
  s1 -= s2;
  std::cout << s1 << std::endl;

  // Substraction
  s1 = s1 - s2;
  std::cout << s1 << std::endl;
}
