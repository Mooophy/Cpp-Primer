#include <iostream>
using namespace std;
int main()
{
    int sum = 0;
    for (int i = 0; cin >> i; sum += i);
    cout << "Sum is: " << sum << endl;
    return 0;
}
