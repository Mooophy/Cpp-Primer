//! @Alan
//!
//! Exercise 9.43:
//! Write a function that takes three strings, s, oldVal, and newVal.
//! Using iterators, and the insert and erase functions replace all instances of
//! oldVal that appear in s by newVal.
//! Test your function by using it to replace common abbreviations,
//! such as “tho” by “though” and “thru” by “through”.
//!

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

//!
//! \brief  Exercise 9.43
//! @note   Using iterators, and the insert and erase functions
//! \return 0 : replace operation happenned ; -1 : otherwise.
//!
int abbrv_handler(std::string&, const std::string&, const std::string&);
int main()
{
    std::string s("thru   _  thru ");
    abbrv_handler(s,"thru","through");
    std::cout << s;

    return 0;
}
int abbrv_handler(std::string &s, const std::string &oldVal, const std::string &newVal)
{
    if(oldVal.size() > s.size())    return -1;

    auto it = s.begin();
    while(it != s.end())
    {
        if (*it == *oldVal.begin())
        {
            //! @note   build sub_str from s to compare the oldVal laterly
            auto tmp = s.substr(it - s.begin(), oldVal.size());

            if (tmp.compare(oldVal) == 0)
            {
                //! @note   Store the offset has been checked
                int offSet = it - s.begin();


                //! @note   Remove  [first,last) and update itterator using the return.
                it = s.erase(it, it + oldVal.size());


                //! @note   No proper iterator returned by all overloaded insert memeber.
                s.insert(it, newVal.begin(), newVal.end());


                //! @note   Manually, move the iterator to point to the last of the added element:
                //!         Assuming "through" is newly added:
                //!         ********through******
                //                        ^
                //!         above is where it points to.
                //!         by the statement ++it, it will move to the next element as shown below:
                //!         ********through******
                //                         ^
                it = s.begin() + offSet + newVal.size() - 1;
            }
        }
        ++it;
    }

    return 0;
}


