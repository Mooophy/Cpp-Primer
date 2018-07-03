//
//  ex8_04.cpp
//  Exercise 8.4
//
//  Created by pezy on 11/9/14.
//
//  @Brief  Write a function to open a file for input and read its contents into a vector of strings, 
//          storing each line as a separate element in the vector. 

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using std::vector; using std::string; using std::ifstream; using std::cout; using std::endl;

void ReadFileToVec(const string& fileName, vector<string>& vec)
{
    ifstream ifs(fileName);
    if (ifs)
    {
        string buf;
        while (std::getline(ifs, buf))
            vec.push_back(buf);
    }
}

int main()
{
    vector<string> vec;
    vector<string>::iterator the_iterator;
    string str;
    ReadFileToVec("../data/book.txt", vec);
    the_iterator = vec.begin();
    while(the_iterator != vec.end())
    {
        str = *the_iterator;
        cout<<str<<endl;
        the_iterator++;
    }
    return 0;
}
