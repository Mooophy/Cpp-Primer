//!
//! @author @Yue Wang @shbling @pezy @zzzkl
//! @date   02.12.2014
//!
//! Exercise 10.14:
//! Write a lambda that takes two ints and returns their sum.
//!
//! Exercise 10.15:
//! Write a lambda that captures an int from its enclosing function
//! and takes an int parameter. The lambda should return the sum of
//! the captured int and the int parameter.
//!
//! Exercise 10.16:
//! Write your own version of the biggies function using lambdas.
//!

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


//! from ex 10.9
void elimdups(std::vector<std::string> &vs)
{
    std::sort(vs.begin(), vs.end());
    auto new_end = std::unique(vs.begin(),vs.end());
    vs.erase(new_end, vs.end());
}


void biggies(std::vector<std::string> &vs, std::size_t sz)
{
    using std::stable_sort;
    using std::string;
    using std::find_if;

    elimdups(vs);

    //! sort by size, but maintain alphabetical order for same size.
    stable_sort(vs.begin(), vs.end(),[](string const& lhs, string const& rhs){
        return lhs.size() < rhs.size();
    });

    //! get an iterator to the first one whose size() is >= sz
    auto wc = find_if(vs.begin(), vs.end(),[sz](string const& s){
            return s.size() > sz;
    });

    for(auto it = wc; it != vs.cend(); ++it)
        std::cout << *it << " ";
}


int main()
{
    //! ex10.14
    auto add = [](int lhs, int rhs){return lhs+rhs;};
    std::cout << "ex10.14: " << add(1,2) << std::endl;

    //! ex10.15
    int i = 42;
    auto lambda = [&i](int num){return i+num;};
    std::cout << "ex10.15: " << lambda(99) << std::endl;

    //! ex10.16
    std::vector<std::string> v
    {
        "1234","1234","1234","hi~", "alan", "alan"
    };
    std::cout << "ex10.16: ";
    biggies(v,3);
    std::cout << std::endl;

    return 0;
}
//! output :
//!
//ex10.14: 3
//ex10.15: 141
//ex10.16: 1234 alan
