#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main () {
    int a=0, b=0;
    cout<<"Please input two integers: ";
    cin>>a>>b;
    cout<<static_cast <double>(a)/b<<endl;
    return 0;
}
