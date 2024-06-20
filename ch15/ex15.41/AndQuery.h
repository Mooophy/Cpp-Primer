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

    AndQuery( const AndQuery &AQ ) : BinaryQuery(AQ){}
    AndQuery( AndQuery &&AQ ) : BinaryQuery(std::move(AQ)){}

    AndQuery* clone() & override 
    {
        return new AndQuery(*this);
    }

    AndQuery* clone() && override
    {
        return new AndQuery(std::move(*this));
    }
};


QueryResult 
AndQuery::eval( const TextQuery &TQ ) const
{
    auto Result_Lhs =  lhs.eval(TQ);
    auto Result_Rhs =  rhs.eval(TQ);
    auto ret =  Result_Lhs.get_file();
    auto And_Set = make_shared<set<size_t>>();

    set_intersection(Result_Lhs.begin(),Result_Lhs.end(),
                                Result_Rhs.begin(),Result_Rhs.end(),inserter( *And_Set,And_Set->begin()));
    return QueryResult(rep(),ret,And_Set);
}

inline Query
operator& ( const Query &lhs, const Query &rhs)
{
    return new AndQuery(lhs,rhs);
}
#endif
