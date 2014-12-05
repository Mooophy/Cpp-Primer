//
//  ex5_21.cpp
//  Exercise 5.21
//
//  Created by pezy on 11/9/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Revise the program from the exercise in 5.5.1(p. 191)
//          so that it looks only for duplicated words that start with an uppercase letter. 
//  @See    Exercise 5.20

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main()
{
    string read, tmp;
    while ( cin >> read )
        if (read == tmp && isupper(read[0])) break;
        else tmp = read;
    
    if (cin.eof()) cout << "no word was repeated." << endl;
    else cout << read << " occurs twice in succession." << endl;
    return 0;
}
