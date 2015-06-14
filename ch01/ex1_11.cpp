// Print each number in the range specified by two integers.
#include <iostream>
int main()
{
        int n1 = 0, n2 = 0;
        std::cout << "enter two numbers " << std::endl;
        std::cin >> n1 >> n2;
        while ( ++n1 < n2 )
        {
                std::cout << n1 << std::endl;
        }
        --n1; // remove the effect of ++n1
        while ( n1 > ++n2 )
        {
                std::cout << n2 << std::endl;
        }
        return 0;
}
