#include <iostream>
#include "include/Sales_item.h"

int main()
{
    Sales_item temp;
    Sales_item books[20];   //it can recognize 20 different ISBN
    int counts[20]={0};     //transcaction counts for each book, initialize all to zeros
    int num=0;              //how many books (different ISBN) have entered?
    int i;                  //index

    std::cout<<"Enter the transactions, 20 books max: (EOF to quit)"<<std::endl;
    if(std::cin>>books[0])
    {
        counts[0]=1;
        num=1;
        while(std::cin>>temp)
        {
            for(i=0;i<num;i++)
                if(temp.isbn()==books[i].isbn())
                {
                    counts[i]++;
                    break;
                }
            if(i==num)
            {
                books[num]=temp;
                counts[num]=1;
                num++;
            }
        }
        for(i=0;i<num;i++)
            std::cout<<books[i].isbn()<<" has "<<counts[i]
                     <<" transcations."<<std::endl;
    }
    else
        std::cerr<<"No Input!"<<std::endl;
    return 0;
}
