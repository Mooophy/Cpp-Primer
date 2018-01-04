#include <iostream>
using std::cout; using std::cin; using std::endl;

int main()
{
    for (unsigned g; cin >> g; )
    {
        // conditional operators
        auto result = g > 90 ? "high pass" : g < 60 ? "fail" : g < 75 ? "low pass" : "pass";
        cout << result << endl;

        // if statements
        if (g > 90)         cout << "high pass";
        else if (g < 60)    cout << "fail";
        else if (g < 75)    cout << "low pass";
        else                cout << "pass";
        cout << endl;
    }

    return 0;
}
