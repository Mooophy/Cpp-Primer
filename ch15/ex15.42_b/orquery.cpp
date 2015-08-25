#include "orquery.h"

#include <memory>
using std::make_shared;

#include <set>
using std::set;

#include "queryresult.h"
#include "textquery.h"
#include "query.h"

QueryResult
OrQuery::eval(const TextQuery &text) const
{
	auto right = rhs.eval(text);
	auto left = lhs.eval(text);
	auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult(rep(), ret_lines, left.get_file());
}
