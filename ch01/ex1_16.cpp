#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int sum = 0;
    for (int i = 0; cin >> i; sum += i);
    cout << "Sum is: " << sum << endl;
    return 0;
}
