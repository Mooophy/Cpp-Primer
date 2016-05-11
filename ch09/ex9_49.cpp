//
//  ex9_49.cpp
//  Exercise 9.49
//
//  Created by pezy on 12/5/14.
//
//  @Brief  A letter has an ascender if, as with d or f, part of the letter extends
//          above the middle of the line.
//          A letter has a descender if, as with p or g, part of the letter extends below the line.
//          Write a program that reads a file containing words and reports the longest word
//          that contains neither ascenders nor descenders.
//  
//  @Refactor  @Yue Wang Jun 2015
//
//  @Refactor  @Jarvis.shen 2016
//
include <iostream>
#include <fstream>
#include <string>

int main()
{
        std::ifstream in("in", std::ifstream::in);
        std::ofstream out("out", std::ofstream::out);

        if(in)
        {
                std::string as_de_cender("bdfgphjkly");
                std::string word;
                in >> word;

                std::string::size_type start = 0, end = 0;
                unsigned longest = 0;

                while((start = word.find_first_not_of(as_de_cender, end)) != std::string::npos)
                {
                        if((end = word.find_first_of(as_de_cender, start)) != std::string::npos)
                        {
                                longest = (end - start) > longest ? end - start : longest;
                        }
                        else
                        {
                                longest = (word.size() - start) > longest ? word.size() - start : longest;
                        }
                }

                out << longest;
                return 0;
        }
}

