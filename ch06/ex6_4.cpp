#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

void fact(){
    
    int a=0;
    unsigned int result=1;
    cout<<"Please input a positive number: "<<endl;
    cin>>a;
    cout<<a;
    if (a>=0&&a<=33){
    while (a>=1) {
        result*=a--;
    }
        cout<<"!= "<<result<<endl;}
    else
            cout<<" is out of range."<<endl;
}

int main () {
    fact();
    return 0;
}

