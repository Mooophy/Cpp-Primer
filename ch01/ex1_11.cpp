// Print each number in the range specified by two integers.

#include <iostream>

int main()
{
	int val_small = 0, val_big = 0;
	std::cout << "please input two integers:";
	std::cin >> val_small >> val_big;
	
	if (val_small > val_big) {
		std::swap(val_small,val_big);
	}
	
	int temp = val_small;	// preserve the value of val_small!
	while (temp <= val_big) {
		std::cout << temp++ << std::endl;
	}
	
	return 0;
}
