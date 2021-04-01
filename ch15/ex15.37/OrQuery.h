#ifndef OR_QUERY_H
#define OR_QUERY_H

#include "Query.h"
#include "QueryBase.h"
#include "BinaryQuery.h"
#include <iterator>
#include <algorithm>

class OrQuery : public BinaryQuery {
friend Query operator| ( const Query &, const Query &);
    OrQuery( const Query &Q_L, const Query &Q_R ) : BinaryQuery(Q_L,Q_R,"|") {}
    QueryResult eval( const TextQuery & ) const override;
};


QueryResult 
OrQuery::eval( const TextQuery &TQ ) const
{
    auto Result_Lhs =  lhs->eval(TQ);
    auto Result_Rhs =  rhs->eval(TQ);
    auto TextPtr =  Result_Lhs.get_file();
    auto OrSet = make_shared<set<size_t>>();

    set_union(Result_Lhs.begin(),Result_Lhs.end(),
                                Result_Rhs.begin(),Result_Rhs.end(),inserter( *OrSet,OrSet->begin()));
    return QueryResult(rep(),TextPtr,OrSet);
}

inline Query
operator| ( const Query &lhs, const Query &rhs)
{
    return shared_ptr<QueryBase>( new OrQuery(lhs,rhs));
}
#endif
