//!Exercise 3.21: Redo the first exercise from § 3.3.3 (p. 105) using iterators.
//!stack overflow:http://stackoverflow.com/questions/20156798/can-i-handle-iterators-with-template

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<class t>
void wy_check_vector(vector<t>& _v);

int main()
{

    vector<int> v1;
    vector<int> v2(10);
    vector<string> svec(10, "null");

    wy_check_vector(v1);
    wy_check_vector(v2);
    wy_check_vector(svec);

    return 0;
}

template<class t>
void wy_check_vector(vector<t>& _v)
{
    if(_v.begin() == _v.end())
    {
        cout    <<  "\nthe vector is empty\n";
    }
    else
    {
        int i=0;
	
	//Don't forget the "typename" here!!
        for(typename vector<t>::iterator it = _v.begin();    it != _v.end();    it++)
        {
            cout << *it;
            i++;
        }
        cout << "\nthe size is : "
                <<i
                    <<"\n";
    }
}
