// sum the numbers from 50 to 100 (use while)

#include <iostream>

auto sum(int lo, int hi)
{
    int sum = 0;
    while (lo <= hi) sum += lo++;
    return sum;
}

int main()
{
    std::cout << "Sum of 50 to 100 inclusive is: " << sum(50, 100) << std::endl;
    return 0;
}
