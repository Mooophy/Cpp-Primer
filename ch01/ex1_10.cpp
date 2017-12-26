// prints the numbers from ten down to zero.(use while)

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int i = 10;
    while (i >= 0)
        cout << i-- << " ";
    cout << endl;
    return 0;
}
