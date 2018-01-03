#include <iostream>
using std::cout; using std::cin; using std::endl;

int main()
{
    //conditional operator
    for(unsigned int grade=0;cin>>grade;){
        string res=(grade<60)?
                  "fail":grade>=60 && grade<=75?
                              "low pass":(grade>90)?"high pass":"pass";
        cout<<res<<endl;;
    }
    
    for (unsigned g; cin >> g; )
    {

        // if statements
        if (g > 90)         cout << "high pass";
        else if (g < 60)    cout << "fail";
        else if (g < 75)    cout << "low pass";
        else                cout << "pass";
        cout << endl;
    }

    return 0;
}
