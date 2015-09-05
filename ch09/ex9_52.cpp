//
//  ex9_52.cpp
//  Exercise 9.52 
//
//  Created by pezy on 12/5/14.
//
//  @Brief  Use a stack to process parenthesized expressions. 
//          When you see an open parenthesis, note that it was seen. 
//          When you see a close parenthesis after an open parenthesis, 
//          pop elements down to and including the open parenthesis off the stack. 
//          push a value onto the stack to indicate that a parenthesized expression was replaced. 

#include <stack>
#include <string>
#include <iostream>

using std::string; using std::cout; using std::endl; using std::stack;

int main()
{
    string expression{ "This is (pezy)." };
    bool bSeen = false;
    stack<char> stk;
    for (const auto &s : expression)
    {
        if (s == '(') { bSeen = true; continue; }
        else if (s == ')') bSeen = false;
        
        if (bSeen) stk.push(s);
    }
    
    string repstr;
    while (!stk.empty())
    {
        repstr += stk.top();
        stk.pop();
    }
    
    expression.replace(expression.find("(")+1, repstr.size(), repstr);
    
    cout << expression << endl;
    
    return 0;
}
