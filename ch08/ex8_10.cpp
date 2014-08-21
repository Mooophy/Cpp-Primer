//! @Alan
//!
//! Exercise 8.10:
//! Write a program to store each line from a file in a vector<string>.
//! Now use an istringstream to read each element from the vector a word at a time.
//!
//!


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


std::vector<std::string> &ex84(const std::string &fn, std::vector<std::string> &v);
std::vector<std::string> &ex85(const std::string &fn, std::vector<std::string> &v);

//! Exercise 8.10
int main()
{
    std::vector<std::string> v;
    v = ex84("test.txt", v);
    for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it)
    {
        std::istringstream sfin(*it);
        std::string s;
        while(sfin>>s)
        {
            std::cout<<s;
        }

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


