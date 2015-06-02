//
//  ex5_21.cpp
//  Exercise 5.21
//
//  Created by pezy on 11/9/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief   Revise the program from the exercise in 5.5.1(p. 191)
//           so that it looks only for duplicated words that start with an uppercase letter. 
//  @See     Exercise 5.20
//  @frank67 Rewrite using the 'continue' statement. See #250

#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <string>
using std::string;

int main()
{
	string str_read, str_prev;

	while ( cin >> str_read ) {
		if ( !isupper(str_read[0]) )
			continue;
		else if ( str_prev == str_read ) {
			cout << str_read << " occurs twice in succession." << endl;
			str_read="";
			break;
			}
			else str_prev = str_read;
	}

	if( !str_read.empty() )
		cout << "no word was repeated." << endl;

	return 0;
}
