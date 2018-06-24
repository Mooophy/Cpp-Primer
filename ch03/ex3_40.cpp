// more discuss: https://github.com/Mooophy/Cpp-Primer/pull/241

#include <iostream>
#include <cstring>

int main() {
  const char cStr1[]{"Hello"};
  const char cStr2[]{"world"};
  const size_t new_size = strlen(cStr1) + strlen(" ") + strlen(cStr2) + 1;

  /** CONSTEXPR ver.
   *  constexpr char cStr1[]{"Hello"};
   *  constexpr char cStr2[]{"world"};
   *  constexpr size_t new_size = __builtin_strlen(cStr1) + __builtin_strlen(" ") + __builtin_strlen(cStr2) + 1;
   **/
  char cStr3[new_size];

  strcpy(cStr3, cStr1);
  strcat(cStr3, " ");
  strcat(cStr3, cStr2);

  std::cout << cStr3 << std::endl;
  return 0;
}
