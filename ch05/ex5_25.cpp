#include <iostream>
#include <stdexcept>

using namespace std;

int main(void)
{
	int a, b;
	cout << "Enter two numbers :" << endl;

	while (cin >> a >> b)
	{
		try{
			if (b == 0)
				throw runtime_error("divisor is 0");
			cout << static_cast<double>(a) / b << endl;
			break;
		}
		catch (runtime_error err){
			cout << err.what()
				<< "\nTry again ? Enter y or n" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n')
				break;
			else
			{
				cout << "Enter two numbers :" << endl;
			}
		}
	}

	return 0;
}
