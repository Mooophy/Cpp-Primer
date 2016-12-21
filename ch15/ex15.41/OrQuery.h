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

    OrQuery( const OrQuery &OQ ) : BinaryQuery(OQ){}
    OrQuery( OrQuery &&OQ ) : BinaryQuery(std::move(OQ)){}

    OrQuery* clone() & override 
    {
        return new OrQuery(*this);
    }

    OrQuery* clone() && override
    {
        return new OrQuery(std::move(*this));
    }
};


QueryResult 
OrQuery::eval( const TextQuery &TQ ) const
{
    auto Result_Lhs =  lhs.eval(TQ);
    auto Result_Rhs =  rhs.eval(TQ);
    auto ret =  Result_Lhs.get_file();
    auto Or_Set = make_shared<set<size_t>>();

    set_union(Result_Lhs.begin(),Result_Lhs.end(),
                                Result_Rhs.begin(),Result_Rhs.end(),inserter( *Or_Set,Or_Set->begin()));
    return QueryResult(rep(),ret,Or_Set);
}

inline Query
operator| ( const Query &lhs, const Query &rhs)
{
    return new OrQuery(lhs,rhs);
}
#endif
