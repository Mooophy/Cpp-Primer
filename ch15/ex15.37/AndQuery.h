#ifndef AND_QUERY_H
#define AND_QUERY_H

#include "Query.h"
#include "QueryBase.h"
#include "BinaryQuery.h"
#include <iterator>
#include <algorithm>

class AndQuery : public BinaryQuery {
friend Query operator& ( const Query &, const Query &);
    AndQuery( const Query &Q_L, const Query &Q_R) : BinaryQuery(Q_L,Q_R,"&") {}
    QueryResult eval( const TextQuery & ) const override;
};


QueryResult 
AndQuery::eval( const TextQuery &TQ ) const
{
    /*
     * rhs and lhs are members of derived class(Binary) pointing to 
     * base class(QueryBase). this pointer can access QueryBase's
     * protected member only if AndQuery is friend of QueryBase.
    */
    auto Result_Lhs =  lhs->eval(TQ);
    auto Result_Rhs =  rhs->eval(TQ);
    auto TextPtr =  Result_Lhs.get_file();
    auto AndSet = make_shared<set<size_t>>();

    set_intersection(Result_Lhs.begin(),Result_Lhs.end(),
                                Result_Rhs.begin(),Result_Rhs.end(),inserter( *AndSet,AndSet->begin()));
    return QueryResult(rep(),TextPtr,AndSet);
}

inline Query
operator& ( const Query &lhs, const Query &rhs)
{
    return shared_ptr<QueryBase>( new AndQuery(lhs,rhs));
}
#endif
