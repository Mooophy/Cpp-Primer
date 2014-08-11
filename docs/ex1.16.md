##Exercise 1.16

> Write your own version of a program that prints the sum of a set of integers read from cin.

Many people confused about this exercise, such as [this](http://www.cplusplus.com/forum/beginner/104169/) and [this](http://stackoverflow.com/questions/17841424/how-to-write-this-while-loop-as-a-for-loop).

In my opinion, the exercise aim to write the program without "**END-OF-FILE**".

**BUT**, the [code](http://www.cplusplus.com/forum/beginner/104169/#msg561450) in first link is not correct.

The following are my own version:

```cpp
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
```

Watch out for "sum + value" in the `cout` line.
