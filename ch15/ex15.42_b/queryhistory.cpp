#include "queryhistory.h"

#include <memory>
using std::shared_ptr; using std::make_shared;

size_t QueryHistory::add_query(const Query &query)
{
	shared_ptr<Query> p = make_shared<Query>(query);
	query_vec.push_back(p);
	return query_vec.size() - 1;
}
