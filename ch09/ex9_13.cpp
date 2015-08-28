// @author @shbling @Yue Wang
//
// Exercise 9.13:
// How would you initialize a vector<double> from a list<int>?
// From a vector<int>?
// Write code to check your answers.
//
#include <iostream>
#include <string>
#include <vector>
#include <list>

using std::list; using std::vector; using std::cout; using std::endl;

int main()
{
    list<int> ilst(5, 4);
    vector<int> ivc(5, 5);

    // from list<int> to vector<double>
    vector<double> dvc(ilst.begin(), ilst.end());
    for (auto i : ilst) cout << i << " ";
    cout << endl;
    for (auto d : dvc) cout << d << " ";
    cout << endl;

    // from vector<int> to vector<double>
    vector<double> dvc2(ivc.begin(), ivc.end());
    for (auto i : ivc) cout << i << " ";
    cout << endl;
    for (auto d : dvc2) cout << d << " ";

    return 0;
}
