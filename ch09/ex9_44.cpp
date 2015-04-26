//
//  ex9_44.cpp
//  Exercise 9.44
//
//  Created by pezy on 12/4/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Rewrite the previous function using an index and replace.
//  @See    9.43

#include <iostream>
#include <string>

using std::cout; using std::endl; using std::string; using std::prev;

void Replace(string& s, string const& oldVal, string const& newVal)
{
    for ( string::size_type i = 0; i != s.size(); ++i )
        if ( s.substr( i, oldVal.size() ) == oldVal ) {
            s.replace( i, oldVal.size(), newVal );
            i += newVal.size() - 1;
        }
}

int main()
{
    string str{"To drive straight thru is a foolish, tho courageous act."};
    Replace( str, "tho", "though" );
    Replace( str, "thru", "through" );
    cout << str << endl;
}
