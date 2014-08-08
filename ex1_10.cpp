// prints the numbers from ten down to zero.(use while)

#include <iostream>

int main()
{
	int val = 10;
	while (val >= 0)
	{
		std::cout << val << std::endl;
		--val;
	}
	
	return 0;
}
