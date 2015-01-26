//! @Alan
//!
//! Exercise 10.34:
//! Use reverse_iterators to print a vector in reverse order.
//!
//! Exercise 10.35:
//! Now print the elements in reverse order using ordinary iterators.
//!
//! Exercise 10.36:
//! Use find to find the last element in a list of ints with value 0.
//!
//! Exercise 10.37:
//! Given a vector that has ten elements, copy the elements from positions
//! 3 through 7 in reverse order to a list.
//!

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <list>

//! Exercise 10.34
void
r_print(const std::vector<std::string> &v);

//! Exercise 10.35
void
r_withOrdinary_print(const std::vector<std::string> &v);

//! Exercise 10.36
std::list<int>::iterator
find_last_0(std::list<int> &l);

//! Exercise 10.37
void
vec2list_3_7_reverse(const std::vector<int> &v, std::list<int> &l);

int main()
{

    std::vector<std::string> v={"aa","bb","cc"};

    //! test for 10.34
    r_print(v);
    std::cout << "\n";

    //! test for 10.35
    r_withOrdinary_print(v);
    std::cout << "\n";

    //! test for 10.36
    std::list<int>  l = {1,2,3,4,0,5,6};
    auto it = find_last_0(l);
    std::cout << *it << "\n";

    //! test for 10.37
    std::vector<int> vi = {1,2,3,4,5,6,7,8,9,10};
    std::list<int>  lst;
    vec2list_3_7_reverse(vi,lst);
    for(auto e : lst)
        std::cout << e <<" ";
    std::cout << std::endl;

    return 0;
}

//! Exercise 10.34
inline void
r_print(const std::vector<std::string> &v)
{
    std::for_each(v.crbegin(), v.crend(), [](const std::string &s)
    {
        std::cout << s << " ";
    });
}

//! Exercise 10.35
inline void
r_withOrdinary_print(const std::vector<std::string> &v)
{
    for (auto it = std::prev(v.cend()); it != std::prev(v.cbegin()); --it)
        std::cout << *it << " ";
}

//! Exercise 10.36
//! @note   reverse iterator can not conver to oridinary directly
//!         it may be done via the member base().
inline std::list<int>::iterator
find_last_0(std::list<int> &l)
{
    //! assumimg : 1 2 3 4 0 5 6

    //! 1 2 3 4 0 5 6
    //!         ^
    //! to which r_it refer.
    auto r_it = std::find(l.rbegin(), l.rend(), 0);

    //! 1 2 3 4 0 5 6
    //!           ^
    //! to which it refer.
    auto it = r_it.base();

    //! 1 2 3 4 0 5 6
    //!         ^
    //! to which --it refer.
    return std::prev(it);

}

//! Exercise 10.37:
//! Given a vector that has ten elements, copy the elements from positions
//! 3 through 7 in reverse order to a list.
inline void
vec2list_3_7_reverse(const std::vector<int> &v, std::list<int> &l)
{
    //!     1 2 3 4 5 6 7 8 9 10
    //!    ^                  ^^
    //! rend                  rbegin
    std::copy(v.crbegin() + 3, v.crbegin() + 8, std::back_inserter(l));
    //!                                  ^
    //! @note: std::copy copies the range [first,last) into result.
    //!        hence, the arguments here denote:
    //!        [7 6 5 4 3 2)
    //!                   ^ this one is specified but not included.
    //! @note: also const vecrions if functions can be used.  v.crbegin() and v.crbegin()
}
