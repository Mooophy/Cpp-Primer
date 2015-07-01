#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main()
{   

    int n1, n2;
    double re;

    while (true) {

        try {

            cout << "Input two numbers: " << endl;
            cin >> n1 >> n2;

            if (n2 == 0)
                throw runtime_error("Zero denominator!!!!");

            re = static_cast<double>(n1) / n2;

        } catch (runtime_error err) {

            cout << err.what() << endl;
            continue;

        }

        break;

    }

    cout << re << endl;

    return 0;
}