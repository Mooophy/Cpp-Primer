#include <iostream>
using std::cout; using std::cin; using std::endl;

int main()
{
//    Exercise 4.22: Extend the program that assigned high pass, pass, and fail
//    grades to also assign low pass for grades between 60 and 75 inclusive. Write
//    two versions: One version that uses only conditional operators; the other
//    should use one or more if statements. Which version do you think is easier
//    to understand and why?
    
    for(unsigned int grade=0;cin>>grade;){
        string res=(grade<60)?
                  "fail":grade>=60 && grade<=75?
                              "low pass":(grade>90)?"high pass":"pass";
        cout<<res<<endl;;
    }

    return 0;
    
    for (unsigned g; cin >> g; )
    {
        // conditional operators
        auto result = g > 90 ? "high pass" : g < 60 ? "fail" : g < 75 ? "low pass" : "pass";
        cout << result << endl;

        // if statements
        if (g > 90)         cout << "high pass";
        else if (g < 60)    cout << "fail";
        else if (g < 75)    cout << "low pass";
        else                cout << "pass";
        cout << endl;
    }

    return 0;
}
