#include <vector>
#include <iterator>
#include <iostream>

using std::vector; using std::cout; using std::cin; using std::endl;

int main()
{
  vector<unsigned> scores(11, 0);
  unsigned grade;
  while (cin >> grade)
    if (grade <= 100)
      ++(*(scores.begin() + grade/10));

  for (auto score : scores)
    cout << score << " ";
  cout << endl;

  return 0;
}
