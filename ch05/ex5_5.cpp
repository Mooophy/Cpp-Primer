#include <iostream>
#include <vector>
#include <string>
using std::vector; using std::string; using std::cout; using std::endl; using std::cin;

int main()
{
    vector<string> scores = { "F", "D", "C", "B", "A", "A++" };
    for (int g; cin >> g;)
    {
        string letter;
        if (g < 60)
        {
            letter = scores[0];
        }
        else
        {
            letter = scores[(g - 50) / 10];
            if (g != 100)
                letter += g % 10 > 7 ? "+" : g % 10 < 3 ? "-" : "";
            cout << letter << endl;
        }
    }

    return 0;
}
