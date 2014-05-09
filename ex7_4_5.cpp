//! @Alan
//!
//! Exercise 7.4:
//! Write a class named Person that represents the name and address of a person.
//! Use a string to hold each of these elements.
//!
//! Exercise 7.5:
//! Provide operations in your Person class to return the name and address.
//! Should these functions be const? Explain your choice.
//!
//  Since all these functions don't change the arguments, being const member make
//  it more useful.
//!

#include <iostream>
#include <string>

using namespace std;

struct Person
{
    std::string name;
    std::string address;

    std::string getName(void) const {return this->name;}
    std::string getAddress(void) const {return this->address;}
};

int main()
{
    return 0;
}
