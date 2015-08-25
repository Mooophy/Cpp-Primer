#ifndef _QUERYHISTORY_H
#define _QUERYHISTORY_H

#include <memory>
using std::shared_ptr;

#include <vector>
using std::vector;

#include "query.h"

class QueryHistory
{
public:
	Query& operator[](size_t n)
	{
		return *(query_vec[n]);
	}

	//return the assigned number of the  new query
	size_t add_query(const Query&);
private:
	vector<shared_ptr<Query>> query_vec;
};

#endif
