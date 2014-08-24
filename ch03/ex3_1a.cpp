// use `using` for 1.4.1

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  int sum = 0, val = 1;
  // keep executing the while as long as val is less than or equal to 10
  while (val <= 10)
  {
    sum += val;
    ++val;
  }
  cout << "Sum of 1 to 10 inclusive is " << sum << endl;
  return 0;
}
