//@Squawk09

//17.37
//Use the unformatted version of getline to read a file a line at a time.
//Test your program by giving it a file that contains empty lines as well as lines that are
//longer than the character array that you pass to getline.

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//int main () {
//  ifstream myfile("F:\\Git\\Cpp-Primer\\ch17\\17_37_38\\test.txt");
//  if (myfile) cout << 1 << endl;
//  char sink [250];
//
//  while(myfile.getline(sink,250))
//  {
//    cout << sink << endl;
//  }
//  return 0;
//}

//17.38
//Extend your program from the previous exercise to print each word you read onto its own line.

//#include <iostream>
//#include <fstream>
//#include <iomanip>
//
//using namespace std;
//
//int main () {
//  ifstream myfile ("F:\\Git\\Cpp-Primer\\ch17\\17_37_38\\test.txt");
//  char sink [250];
//
//  while(myfile.getline(sink,250,' '))
//  {
//    cout << sink << endl;
//  }
//  return 0;
//}


int main()
{
	std::cout << "Standard Output!\n";
	std::cerr << "Standard Error!\n";
	std::clog << "Standard Log??\n";
}
