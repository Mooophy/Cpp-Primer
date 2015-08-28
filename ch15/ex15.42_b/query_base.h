#ifndef _QUERY_BASE_H
#define _QUERY_BASE_H

#include <string>
using std::string;

#include "textquery.h"

class Query_base
{
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual string rep() const = 0;
};

#endif
