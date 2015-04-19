#include <iostream>
#include <string>
#include<stdexcept>
using std::string;
using std::cin;
using std::cout;
using std::endl;


int main () {
    int a=0, b=0;
    cout<<"Please input two integers: ";
    while (cin>>a>>b) {
        try{
            if (b==0) {
                throw std::runtime_error("One of the two integers is 0.");}
            cout<<static_cast <double>(a)/b<<endl;
        }
        catch (std::runtime_error err)
            {cout<<err.what();
                cout<<"\nDo you want to try it again? Yes or No\n";
                string a={};
                cin>>a;
                if (a.empty()||a[0]=='N') {
                    break;
                }
            }
    }
    return 0;
}
