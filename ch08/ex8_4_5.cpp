//! @Alan
//!
//! Exercise 8.4:
//! Write a function to open a file for input and read its contents into a vector
//! of strings, storing each line as a separate element in the vector.
//  Note: the txt file must be placed at the folder of the exe file rather than the
//  source file.
//!
//! Exercise 8.5:
//! Rewrite the previous program to store each word in a separate element.
//!
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::vector<std::string> &ex84(const std::string &fn, std::vector<std::string> &v);
std::vector<std::string> &ex85(const std::string &fn, std::vector<std::string> &v);

int main()
{
    std::vector<std::string> v;
    ex84("test.txt",v);
    std::cout << v[0] <<std::endl;


    std::vector<std::string> w;
    w = ex85("test.txt",w);

    for (std::vector<std::string>::iterator it = w.begin(); it != w.end();  ++it)
    {
        std::cout<<*it;
    }

    return 0;
}

std::vector<std::string> &ex85(const std::string &fn, std::vector<std::string> &v)
{
    std::string word;
    std::ifstream fin(fn);

    if(fin.is_open())
    {
        std::cout<<"opened\n";
    }
    else
    {
        std::cout<<"failed\n";
    }

    while(fin>>word)
    {
        v.push_back(word);
    }

    return v;
}


std::vector<std::string> &ex84(const std::string &fn, std::vector<std::string> &v)
{
    std::string line;
    std::ifstream fin(fn);

    if(fin.is_open())
    {
        std::cout<<"opened\n";
    }
    else
    {
        std::cout<<"failed\n";
    }

    while(std::getline(fin,line))
    {
        v.push_back(line);
    }

    return v;
}


