##Exercise 1.12
> What does the following for loop do? What is the final value
of sum?
```cpp
int sum = 0;
for (int i = -100; i <= 100; ++i)
sum += i;
```

the loop sums the numbers from -100 to 100. the final value of sum is zero.

##Exercise 1.13
> Rewrite the exercises from § 1.4.1 (p. 13) using for loops.

Ex1.9:
```cpp
#include <iostream>

int main()
{
	int sum = 0;
	for (int i=50; i<=100; ++i)
	    sum += i;

	std::cout << "the sum is: " << sum << std::endl;

	return 0;
}
```

Ex1.10:
```cpp
#include <iostream>

int main()
{
	for (int i=10; i>=0; --i)
	  std::cout << i << std::endl;

	return 0;
}
```

Ex1.11:
```cpp
#include <iostream>

int main()
{
  int val_small = 0, val_big = 0;
  std::cout << "please input two integers:";
  std::cin >> val_small >> val_big;

  if (val_small > val_big)
  {
    int tmp = val_small;
    val_small = val_big;
    val_big = tmp;
  }

  for (int i=val_small; i<=val_big; ++i)
    std::cout << i << std::endl;

  return 0;
}
```

##Exercise 1.14
> Compare and contrast the loops that used a for with those
using a while. Are there advantages or disadvantages to using either form?

If you need a pattern which is using a variable in a condition and incrementing that variable in the
body. You should use `for` loop. Else the `while` loop is more simple.

Want to know more? look at [this](http://stackoverflow.com/questions/1600282/guideline-while-vs-for)

##Exercise 1.15
> Write programs that contain the common errors discussed in
the box on page 16. Familiarize yourself with the messages the compiler
generates.

**JUST READ IT!**
