//
//  ex7_13.cpp
//  Exercise 7.13
//
//  Created by pezy on 11/9/14.
//

#include "ex7_12.h"

int main()
{
	Sales_data total(cin);

	if (cin)
	{
		while (cin)
		{
			Sales_data trans(cin);
			if (cin)
			{
				if (total.isbn() == trans.isbn())
				{
					total.combine(trans);
				}
				else
				{
					print(cout, total) << endl;
					total = trans;
				}
			}
		}		
		print(cout, total) << endl;
	}
	else
	{
		std::cerr << "No data!" << endl;
		return -1;
	}
	return 0;
}
