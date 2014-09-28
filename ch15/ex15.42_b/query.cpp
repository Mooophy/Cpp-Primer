#include"query.h"

#include<ostream>
using std::ostream;

ostream&
operator<<(ostream &os, const Query &query)
{
	return os << query.rep();
}