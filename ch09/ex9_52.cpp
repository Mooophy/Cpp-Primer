//
//  ex9_52.cpp
//  Exercise 9.52
//
//  Created by pezy on 12/5/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Use a stack to process parenthesized expressions.
//          When you see an open parenthesis, note that it was seen.
//          When you see a close parenthesis after an open parenthesis,
//          pop elements down to and including the open parenthesis off the stack.
//          push a value onto the stack to indicate that a parenthesized expression was replaced.

#include <stack>
using std::stack;

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

int main()
{
    auto & expr = "This is (Mooophy(awesome)((((wooooooooo))))) and (ocxs) over";
    auto   repl = '#';
    auto   seen = 0;

    stack<char> stk;

    for (auto c : expr) {
        stk.push(c);
        if ( c == '(' ) ++seen; // open
        if ( seen && c == ')' ) { // pop elements down to the stack
            while ( stk.top() != '(' ) stk.pop();
            stk.pop(); // including the open parenthesis
            stk.push(repl); // push a value indicate it was replaced
            --seen; // close
        }
    }

    // Test
    string output;
    for ( ; !stk.empty(); stk.pop() ) output.insert(output.begin(), stk.top());
    cout << output << endl; // "This is # and # over"
}
