//! @Alan
//!
//! Exercise 9.13:
//! How would you initialize a vector<double> from a list<int>?
//! From a vector<int>?
//! Write code to check your answers.
//!
#include <iostream>
#include <string>
#include <vector>
#include <list>
using std::list;using  std::vector;using std::cout;using std::endl;

int main()
{
   list<int> ilst(5, 1);
	vector<int> ivc(5, 2);
	vector<double> dvc (ilst.begin(),ilst.end());//from list<int>  to  vector<double>
	for (auto i : ilst)
		cout << i;
	cout << endl;
	for (auto t : dvc)
		cout << t;
	cout << endl;
	vector<double> dvc2(ivc.begin(), ivc.end());//from vector<int>   to  vector<double>
	for (auto i : ivc)
		cout << i;
	cout << endl;
	for (auto t : dvc2)
		cout << t;
    return 0;
}
