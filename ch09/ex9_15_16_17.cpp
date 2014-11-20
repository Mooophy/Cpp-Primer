//! @Alan
//!
//! Exercise 9.15:
//! Write a program to determine whether two vector<int>s are equal.
//!
//! Exercise 9.16:
//! Repeat the previous program,
//! but compare elements in a list<int> to a vector<int>.
//!
//! Exercise 9.17:
//! Assuming c1 and c2 are containers, what (if any) constraints does
//! the following usage place on the types of c1 and c2?
//  First, ther must be the identical container and same type holded.
//  Second,the type holded must support relational operation.
//!
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>

bool is_equal(const std::vector<int> &v1, const std::vector<int> &v2);
bool is_equal2(const std::vector<int> &v, const std::list<int> &l);
int main()
{
	std::vector<int> iv{ 10, 1 };
	std::vector<int> iv2{ 10, 1 };
	std::list<int> il{ 10, 2 };
	
	if (is_equal(iv, iv2))//EX9.15
		std::cout << "iv and iv2 are equal;" << std::endl;
	else std::cout << "iv and iv2 are different;" << std::endl;

	if (is_equal2(iv, il))//EX9.16
		std::cout << "iv and il are equal." << std::endl;
	else std::cout << "iv and il are different." << std::endl;
	
	return 0;
}


bool is_equal(const std::vector<int> &v1, const std::vector<int> &v2)
{
    return  v1==v2;
}


bool is_equal2(const std::vector<int> &v, const std::list<int> &l)
{
    bool result = true;

    if(v.size()==l.size())
    {
        std::vector<int>::const_iterator vit = v.begin();
        std::list<int>::const_iterator lit = l.begin();
        while(vit != v.end())
        {
            if(*vit++ != *lit++)
            {
                result = false;
                break;
            }
        }

    }
    else
    {
        result = false;
    }
    return result;
}
