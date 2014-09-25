#include <iostream>
#include <initializer_list>

using namespace std;

int add(initializer_list<const int> il);

int main(void)
{
	int result = add({ 1, 2, 3, 4, 5 });
	
	cout << result << endl;

	return 0;
}

int add(initializer_list<const int> il)
{
	int sum = 0;
	for (auto a : il)
		sum += a;
	return sum;
}