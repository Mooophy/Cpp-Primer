//AUTHOR YASH PARSANA
//DATE 11-05-2021
//CALCULATOR To calculate a mortgage payment

#include<iostream>
using std::cin;
using std::cout; 
using std::endl;

float po(float r,int n)
{
    float ans=1;

    for(int z=1;z<=n;z++)
    {
        ans*=r;
    }
    return ans;
}
int main()
{
    float p_amount,rate; // FLOAT TAKES HALF SPACE AS COMPARE TO DOUBLE AND HERE HAVE NO REQUIREMENT OF DOUBLE
    int year; 

    cout<<"Please Enter principal Amount : ";
    cin>>p_amount;
    cout<<endl<<"Please Enter rate of interest : ";
    cin>>rate;
    cout<<endl<<"Please Enter duration (in year) : ";
    cin>>year;
    cout<<endl;

    int n=year*12;

    rate=rate/1200;

    float temp=po(1+rate,n);

    float payment=(p_amount*rate*temp)/(temp-1);

    cout<<"Your monthly payment is : "<<payment<<endl;

    

    
    return 0;
}