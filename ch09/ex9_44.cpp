//! @Alan
//!
//! Exercise 9.43:
//! Write a function that takes three strings, s, oldVal, and newVal.
//! Using iterators, and the insert and erase functions replace all instances of
//! oldVal that appear in s by newVal.
//! Test your function by using it to replace common abbreviations,
//! such as “tho” by “though” and “thru” by “through”.
//!
//! Exercise 9.44:
//! Rewrite the previous function using an index and replace.
//!

#include <iostream>
#include <string>

//! Exercise 9.44
std::string&
ex944(std::string &s, const std::string &oldVal, const std::string &newVal);

int main()
{
    std::string s("thru   _  thru ");
    ex944(s,"thru","through");
    std::cout << s;

    return 0;
}

//! Exercise 9.44
std::string &
ex944(std::string &s, const std::string &oldVal, const std::string &newVal)
{
    //! @note   Return without process,if size too large.
    if(oldVal.size() > s.size())    return s;

    std::string::size_type i=0;
    while(i != s.size())
    {
        if(s[i] == oldVal[0])
        {
            //! @note   build sub_str from s to compare the oldVal laterly
            auto tmp = s.substr(i, oldVal.size());
            //! @note to make sure that i will not be out of range 
            if (s.size() - i > oldVal.size())
			{
                if (tmp.compare(oldVal) == 0)
                {
                    s.replace(i,oldVal.size(),newVal);

                    //! @note   Manually, move the index to denote the last of the added element:
                    //!         Assuming "through" is newly added:
                    //!         ********through******
                    //                        ^
                    //!         above is where the index i denotes now .
                    //!         by the statement ++i , it will denote the next element as shown below:
                    //!         ********through******
                    //                         ^
                    i = i + newVal.size() - 1;
                }
            }
            ++i;
        }
    }
    return s;
}

