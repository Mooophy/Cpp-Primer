//! @Alan
//!
//! Exercise 9.18:
//! Write a program to read a sequence of strings from the standard input into
//! a deque. Use iterators to write a loop to print the elements in the deque.
//!
//! Exercise 9.19:
//! Rewrite the program from the previous exercise to use a list.
//! List the changes you needed to make.
//!
//! Exercise 9.20:
//! Write a program to copy elements from a list<int> into two deques.
//! The even-valued elements should go into one deque and the odd ones into the other.
//!
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>

//! Exercise 9.18
void ex918(void);

//! Exercise 9.19
void ex919(void);

//! Exercise 9.20
void ex920(void);
int main()
{

    return 0;
}

//! Exercise 9.18
void ex918(void)
{
    std::string word;
    std::deque<std::string> dq;

    while(std::cin >> word && word.compare("quit"))
    {
        dq.push_back(word);
    }

    for(auto it = dq.begin(); it != dq.end(); ++it)
    {
        std::cout << *it;
    }
}

//! Exercise 9.19
void ex919(void)
{
    std::string word;
    std::list<std::string> l;
    while (std::cin >> word && word.compare("quit"))
    {
        l.push_back(word);
    }

    for(auto it = l.begin(); it != l.end(); ++it)
    {
        std::cout << *it;
    }
}

//! Exercise 9.20
void ex920(void)
{
    std::list<int> l {1,2,3,4,5,6,7,8,9,10,33,55,66,77,100 };
    std::deque<int> dq_odd, dq_even;

    for(auto it = l.begin(); it != l.end(); ++it)
    {
        if(*it%2 == 1)
        {
            dq_odd.push_back(*it);
        }
        else
        {
            dq_even.push_back(*it);
        }
    }
}
