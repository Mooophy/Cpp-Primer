/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Alan.W
 *  @date       26  DEC 2013
 *  @remark
 ***************************************************************************/

//!
//! Exercise 12.26:
//! Rewrite the program on page 481 using an allocator.
//!

#include <iostream>
#include <memory>
int main()
{
	allocator<string> salloc;
	auto p = salloc.allocate(3);
	auto q = p;
	string str;
	while (cin >> str && q != p + 3)
	{
		salloc.construct(q, str);
		++q;
	}
	const size_t size = q - p;
	q = p;
	while (q != p + 3)
	{
		cout << *q << " ";
		++q;
	}
	cout << std::endl;
	
	while (q != p)
	{
		salloc.destroy(--q);
	}
	salloc.deallocate(p, 3);
        

    return 0;
}
