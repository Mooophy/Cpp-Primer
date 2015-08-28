// sum the numbers from 50 to 100 (use while)

#include <iostream>

int main()
{
    int sum = 0, curr = 50;
    while (curr != 101) sum += curr++;
    std::cout << "sum is: " << sum << std::endl;

    return 0;
}
