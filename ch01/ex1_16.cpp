#include <iostream>

int main()
{
  int limit = 0, sum = 0, value = 0;
  std::cout << "How many integers would you like to enter?";
  std::cin >> limit;

  // assume we don't know what is EOF(End-Of-File).
  while (std::cin >> value && (--limit != 0))
    sum += value;

  std::cout << sum + value << std::endl;

  return 0;
}
