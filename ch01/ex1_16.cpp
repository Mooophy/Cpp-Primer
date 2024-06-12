#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int sum = 0,i;
    while(cin>>i) sum+=i;//For EOF enter "/0"
    cout << "Sum is: " << sum << endl;
    return 0;
}
