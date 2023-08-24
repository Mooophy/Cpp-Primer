#ifndef NOT_QUERY_H
#define NOT_QUERY_H

#include "QueryBase.h"
#include "Query.h"

class NotQuery: public QueryBase {
friend Query operator~ ( const Query &);
    NotQuery( const Query &Q ):q(Q){}

    NotQuery( const NotQuery &NQ ) : q(NQ.q){}
    NotQuery( NotQuery &&NQ ) : q(std::move(NQ.q)){}

    NotQuery* clone() & override 
    {
        return new NotQuery(*this);
    }

    NotQuery* clone() && override
    {
        return new NotQuery(std::move(*this));
    }

    QueryResult eval( const TextQuery & ) const override;
    string rep() const override;
    Query   q;
};

QueryResult 
NotQuery::eval( const TextQuery &TQ ) const
{
    auto ret =  q.eval(TQ);
    auto ptr =  ret.get_file();
    auto Not_in = make_shared<set<size_t>>();
    auto beg = ret.begin(), last = ret.end();

    for ( size_t i = 0; i != ptr->size(); ++i ){
        if ( beg == last || i != *beg )
            Not_in->insert(i);
        else if ( beg != last )
            ++beg;
    }
    return QueryResult(rep(),ptr,Not_in);
}

string 
NotQuery::rep() const 
{
    return string("~") + "(" + q.rep() + ")";
}

inline Query
operator~ ( const Query &Q)
{
    return new NotQuery(Q);
}
#endif
