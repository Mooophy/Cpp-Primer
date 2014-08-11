//! @Alan
//!
//! Exercise 9.31:
//! The program on page 354 to remove even-valued elements and duplicate odd ones will not work
//! on a list or forward_list.
//! Why?
//  no += defined for list or forward_list.
//! Revise the program so that it works on these types as well.
//  use ++++it instead of it += 2
//!
//! Exercise 9.32:
//! In the program onpage 354 would it be legal to write the call to insert as follows? If not, why not?
//! iter = vi.insert(iter, *iter++);
//  ilegal.
//  As the priority of ++ is higher than *,  *iter++  can result in deferencing an item out of range
//  causing a runtime error.
//
//! Exercise 9.34:
//! Assuming vi is a container of ints that includes even and odd values, predict the behavior of the following
//! loop. After you’ve analyzed this loop, write a program to test whether your expectations were correct.
//  This code will cause a dead loop. Refer to comments for more.
//!



#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>


//! Exercise 9.31
void ex931(void)
{
    std::list<int> li = {0,1,2,3,4,5,6,7,8,9};

    auto it = li.begin();
    while (it != li.end())
    {
        if(*it % 2)
        {
            it = li.insert(it, *it);
            ++++it;
        //! ^^^^^^  no += operator defined for list container
        //!         Hence, ++++ was used instead.
        }
        else
        {
            it = li.erase(it);
        }
    }

    for(auto it = li.begin(); it != li.end(); ++it)
    {
        std::cout << *it << " ";
    }
}

//! Exercise 9.32
void ex932(void)
{
    std::vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin();
    while (iter != vi.end())
    {
        if (*iter % 2)
        {

            iter = vi.insert(iter, *iter++);
            //!                    ^^^^^^^^
            //! Exercise 9.32:
            //! ilegal.
            //! As the priority of ++ is higher than *,  *iter++ could deference an item out of range.


            iter += 2;
        }
        else
            iter = vi.erase(iter);

    }

    for(auto it = vi.begin(); it != vi.end(); ++it)
    {
        std::cout << *it << " ";
    }
}

int main()
{
    std::vector<int> vi = {0,1,2,3,4,5};

    auto iter = vi.begin();
    while (iter != vi.end())
        if (*iter % 2)
            iter = vi.insert(iter, *iter);
        ++iter;
    //! ^^^^^^
    //! Exercise 9.34:
    //! A dead loop.
    //! The memeber insert() inserted it before the position specified and
    //! return an iterator pointing here . If increment only one time, as
    //! it did here, the iterator will not move to the next element.That's
    //! why a dead loop happened here.
    //!




    return 0;
}

