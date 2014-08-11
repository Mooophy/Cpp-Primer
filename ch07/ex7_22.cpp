//! @Alan
//!
//! Exercise 7.22:
//! Update your Person class to hide its implementation.
//!

#include <iostream>
#include <string>

class Person
{
    //!friend
    friend std::istream &read(std::istream &is, Person &p);
    friend std::ostream &print(std::ostream &os, const Person &p);
public:
    //! constructors
    Person() = default;
    Person(const std::string &nm, const std::string &add) {this->name = nm; this->address = add;}
    Person(std::istream &);

    //! member functions
    std::string getName(void) const {return this->name;}
    std::string getAddress(void) const {return this->address;}

private:
    std::string name;
    std::string address;
};
//! friend
std::istream &read(std::istream &is, Person &p);
std::ostream &print(std::ostream &os, const Person &p);

int main()
{
    //Person p;
    //Person p("Alan","dd zz aa");
    Person p(std::cin);

    print(std::cout,p);

    return 0;
}

Person::Person(std::istream &is)
{
    read(is, *this);
}

std::ostream &print(std::ostream &os, const Person &p)
{
    os<<p.getName()<<" "<<p.address;
    return os;
}


std::istream &read(std::istream &is, Person &p)
{
    is>>p.name>>p.address;
    return is;
}
