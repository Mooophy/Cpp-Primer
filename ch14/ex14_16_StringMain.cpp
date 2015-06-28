#include "ex14_16_String.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

void foo(String x)
{
    std::cout << x << std::endl;
}

void bar(const String& x)
{
    std::cout << x.c_str() << std::endl;
}

String baz()
{
    String ret("world");
    return ret;
}

int main()
{
    char text[] = "world";

    String s0;
    String s1("hello");
    String s2(std::move(s0));
    String s3 = s1;
    String s4(text);
    s2 = s1;

    if (s2 == s1)
        std::cout << "s2 == s1" << std::endl;

    foo(s1);
    bar(s1);
    foo("temporary");
    bar("temporary");
    String s5 = baz();

    std::vector<String> svec;
    //svec.push_back(s0);
    svec.push_back(s1);
    svec.push_back(s2);
    svec.push_back(s3);
    svec.push_back(s4);
    svec.push_back(baz());
    svec.push_back("good job");

    for (const auto &s : svec) {
        std::cout << s << std::endl;
    }

    std::cout << "Input a string: ";
    String s6;
    std::cin >> s6;
    std::cout << s6 << std::endl;
}
