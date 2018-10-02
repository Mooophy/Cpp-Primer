// sum the numbers from 50 to 100 (use while)

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

auto sum(int lo, int hi)
{
    int sum = 0;
    while (lo < hi) sum += lo++;
    return sum;
}

int main()
{
    cout << "sum is: " << sum(50, 100+1) <<endl;
    return 0;
}
