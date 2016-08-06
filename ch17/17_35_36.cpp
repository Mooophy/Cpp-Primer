//@Squawk09

//17.35 
//Write a version of the program from page 758, that printed the square root of 2 but this time print hexadecimal digints in uppercase
#include <iostream>
#include<iomanip>
#include <math.h>
using namespace std;

int main()
{
	cout <<"default format: " << 100 * sqrt(2.0) << '\n'
		<< "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
		<< "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
		<< "hexidecimal: " << uppercase << hexfloat << 100 * sqrt(2.0) << '\n'
		<< "use defaults: " << defaultfloat << 100 * sqrt(2.0)
		<< "\n\n";
}

//17.36
//Modify the program from the previous exercise to print the various floating-point values so that they line up in a column.
#include <iostream>
#include<iomanip>
#include <math.h>
using namespace std;

int main()
{
	cout <<left<<setw(15) << "default format:" <<setw(25)<< right<< 100 * sqrt(2.0) << '\n'
	<< left << setw(15) << "scientific:" << scientific << setw(25) << right << 100 * sqrt(2.0) << '\n'
	<< left << setw(15) << "fixed decimal:" << setw(25) << fixed << right << 100 * sqrt(2.0) << '\n'
	<< left << setw(15) << "hexidecimal:" << setw(25) << uppercase << hexfloat << right << 100 * sqrt(2.0) << '\n'
	<< left << setw(15) << "use defaults:" << setw(25) << defaultfloat << right << 100 * sqrt(2.0)
	<< "\n\n";
}
