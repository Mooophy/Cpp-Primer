// more discuss: https://github.com/Mooophy/Cpp-Primer/pull/241

#include <iostream>
#include <cstring>

int main() {
  const char cStr1[]{"Hello"};
  const char cStr2[]{"world"};
  const size_t new_size = strlen(cStr1) + strlen(" ") + strlen(cStr2) + 1;

  char cStr3[new_size];

  strcpy(cStr3, cStr1);
  strcat(cStr3, " ");
  strcat(cStr3, cStr2);

  std::cout << cStr3 << std::endl;
  return 0;
}
