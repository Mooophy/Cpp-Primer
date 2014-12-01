//! @Alan
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
//! Exercise 10.18:
//! Rewrite biggies to use partition instead of find_if.
//!
//! Exercise 10.19:
//! Rewrite the previous exercise to use stable_partition, which like
//! stable_sort maintains the original element order in the paritioned
//! sequence.
//!

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>



//! Exercise 10.14
auto sum = [](const int i1, const int i2 )
{   return i1 + i2;     };
//!                      ^
//! @note There is a ";" here, just like that used after a body of a class.


//! Exercise 10.15
void f()
{
    int i = 0;
    auto sum = [i](const int j)
    {
        return i + j;
    };
}

//! Exercise 10.16
void
wy_elimdups(std::vector<std::string> &vs);
void
wy_biggies(std::vector<std::string> &vs,const std::vector<std::string>::size_type sz);

//! Exercise 10.18
void
wy_biggies_partition(std::vector<std::string> &vs, const std::vector<std::string>::size_type sz);

//! Exercise 10.19
void
wy_biggies_STpartition(std::vector<std::string> &vs, const std::vector<std::string>::size_type sz);
int main()
{

    return 0;
}
void wy_elimdups(std::vector<std::string> &vs)
{
    for (auto element : vs)
        std::cout << element
                  <<" ";
    std::cout <<"\n";


    //! sort alphabetically
    std::sort(vs.begin(), vs.end());
    for (auto element : vs)
        std::cout << element
                  <<" ";
    std::cout <<"\n";


    //! put all duplicates at the end of the vector
    //! and get the iterator pointing to the one past
    //! the last unique element.
    auto unique_iterator = std::unique(vs.begin(),vs.end());
    for (auto element : vs)
        std::cout << element
                  <<" ";
    std::cout <<"\n";


    vs.erase(unique_iterator, vs.end());
    for (auto element : vs)
        std::cout << element
                  <<" ";
    std::cout <<"\n";
}

//! Exercise 10.16
void
wy_biggies(std::vector<std::string> &vs, const std::vector<std::string>::size_type sz)
{
    wy_elimdups(vs);

    // sort words by size, but maintain alphabetical order for words of the same size
    std::stable_sort(vs.begin(), vs.end(),
                     [](const std::string &s1, const std::string &s2){return s1.size() < s2.size();});

    // get an iterator to the first element whose size() is >= sz
    auto wc = std::find_if(vs.begin(), vs.end(),
                           [sz](const std::string &s)
                                {return s.size() > sz;});

    std::for_each(wc, vs.end(), [](const std::string &s)
                                         {std::cout << s;});
}

//! Exercise 10.18
void wy_biggies_partition(std::vector<std::string> &vs, const std::vector<std::string>::size_type sz)
{
    wy_elimdups(vs);

    // sort words by size, but maintain alphabetical order for words of the same size
    std::stable_sort(vs.begin(), vs.end(),
                     [](const std::string &s1, const std::string &s2){return s1.size() < s2.size();});

    auto wc = std::partition(vs.begin(), vs.end(),
                             [sz](const std::string &s)
                                        {return s.size() >= sz;});
    std::for_each(vs.begin(),wc, [](const std::string &s)
                                         {std::cout << s<<" ";});

}

//! Exercise 10.19
void wy_biggies_STpartition(std::vector<std::string> &vs, const std::vector<std::string>::size_type sz)
{
    wy_elimdups(vs);

    // sort words by size, but maintain alphabetical order for words of the same size
    std::stable_sort(vs.begin(), vs.end(),
                     [](const std::string &s1, const std::string &s2){return s1.size() < s2.size();});

    auto wc = std::stable_partition(vs.begin(), vs.end(),
                             [sz](const std::string &s)
                                        {return s.size() > sz;});

    std::for_each(wc, vs.end(), [](const std::string &s)
                                         {std::cout << s;});
}





