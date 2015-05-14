#include <iostream>
#include <cstring>

using std::cout; using std::endl;

const char cstr1[]="Hello";
const char cstr2[]="world!";

constexpr size_t calclen()
{
	return strlen(cstr1) + strlen(" ") + strlen(cstr2) +1; // lenght of the strings and the null terminator
}

int main()
{
	char hello[calclen()];
	// adding two C-style strings
	strcpy(hello, cstr1);
	strcat(hello, " ");
	strcat(hello, cstr2);

	cout << hello << endl;
	return 0;
}
