//
//  ex8_05.cpp
//  Exercise 8.5
//
//  Created by pezy on 11/9/14.
//
//  @Brief  Rewrite the previous program to store each word in a separate element.
//  @See    ex8_04.cpp 

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
        while (ifs >> buf)
            vec.push_back(buf);
    }
}

int main()
{
    vector<string> vec;
    ReadFileToVec("../data/book.txt", vec);
    for (const auto &str : vec)
        cout << str << endl;
    return 0;
}
