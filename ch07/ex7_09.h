//
//  ex7_09.h
//  Exercise 7.9
//
//  Created by pezy on 11/8/14.
//
//
//  Revied by @Yue Wang Jun 2015
//

#ifndef CP5_ex7_09_h
#define CP5_ex7_09_h

#include <iostream>
#include <string>

class Person {
public:
  auto getName() const -> std::string const & { return name; };
  auto getAddress() const -> std::string const & { return address; };

  std::string name;
  std::string address;
};

std::istream &read(std::istream &is, Person &person) {
  return is >> person.name >> person.address;
}

std::ostream &print(std::ostream &os, const Person &person) {
  return os << person.name << " " << person.address;
}

#endif
