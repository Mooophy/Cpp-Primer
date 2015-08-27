#include "queryresult.h"

#include <iostream>
using std::ostream;

ostream&
print(ostream &os, const QueryResult &qr)
{
    os <<"The result of your query "<< qr.sought <<" is: \n";
    for (const auto &index: *qr.lines)
        os << "\t(line " << index + 1 << ")"
           << *(qr.file->begin() + index) << "\n";
    return os;
}

/*
Head is the first line of the range.
Trail is the last line of the range.
*/
ostream&
print(ostream& os, const QueryResult &qr, size_t head, size_t trail)
{
	if (head > trail)
	{
		os << "illegal range!\n";
		return os;
	}
	else
	{
		os << "The result of your query " << qr.sought << " is: \n";
		for (const auto &index : *qr.lines)
		{
			if (index + 1 >= head&&index + 1 <= trail)
			{
				os << "\t(line " << index + 1 << ")"
					<< *(qr.file->begin() + index) << "\n";
			}
		}
		return os;
	}
}
