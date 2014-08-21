//!@Alan
//!
//!Exercise 3.25:
//!Rewrite the grade clustering program from § 3.3.3 (p. 104) using
//!iterators instead of subscripts.
//!

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    unsigned grade;
    vector<unsigned> scores(11,0);

    cout<<"Please Enter:\n";
    while(cin>>grade)
    {
        //! note the () used here.
        (*(scores.begin() + grade/10)) ++;

        cout<<"the vecotr=\n";
        for(vector<unsigned>::iterator it = scores.begin(); it != scores.end(); it++)
        {
            cout<<*it
                  <<std::endl;
        }
    }

    return 0;
}
