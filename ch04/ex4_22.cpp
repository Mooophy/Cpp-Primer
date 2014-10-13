#include <iostream>

using std::cout; using std::cin; using std::endl;

int main()
{
  unsigned grade;
  while (cin >> grade)
  {
    // first version(only use conditional operators)
    cout << ((grade > 90) ? "high pass"
                          : (grade < 60) ? "fail"
                                         : (grade < 75) ? "low pass" : "pass");
    cout << endl;
    // second version(only use if statements)
    if (grade > 90) cout << "high pass";
    else if (grade < 60) cout << "fail";
    else if (grade < 75) cout << "low pass";
    else cout << "pass";
    cout << endl;
  }

  return 0;
}
