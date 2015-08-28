// @Yue Wang
//
// Exercise 6.25: Write a main function that takes two arguments.
// Concatenate the supplied arguments and print the resulting string.
//
// Exercise 6.26: Write a program that accepts the options presented
// in this section. Print the values of the arguments passed to main.
//

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    std::string str;
    for (int i = 1; i != argc; ++i)
        str += std::string(argv[i]) + " ";

    std::cout << str << std::endl;
    return 0;
}
