//
//  ex12_20.cpp
//  Exercise 12.20
//
//  Created by pezy on 12/26/14.
//
//  Write a program that reads an input file a line at a time into
//  a StrBlob and uses a StrBlobPtr to print each element in that StrBlob.

#include "ex12_19.h"
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream ifs("../data/book.txt");
    StrBlob blob;
    for (std::string str; std::getline(ifs, str); )
        blob.push_back(str);
    for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incr())
        std::cout << pbeg.deref() << std::endl;
}
