#ifndef NOT_QUERY_H
#define NOT_QUERY_H

#include "QueryBase.h"
#include "Query.h"

class NotQuery: public QueryBase {
friend Query operator~ ( const Query &);
    NotQuery( const Query &q):ptr(q.QB_ptr){}
    QueryResult eval( const TextQuery & ) const override;
    string rep() const override;
    shared_ptr<QueryBase>  ptr;
};

QueryResult 
NotQuery::eval( const TextQuery &TQ ) const
{
    auto Result  =  ptr->eval(TQ);
    auto TextPtr =  Result.get_file();
    auto NotSetPtr = make_shared<set<size_t>>();
    auto beg = Result.begin(), last = Result.end();

    for ( size_t i = 0; i != TextPtr->size(); ++i ){
        if ( beg == last || i != *beg )
            NotSetPtr->insert(i);
        else if ( beg != last )
            ++beg;
    }
    return QueryResult(rep(),TextPtr,NotSetPtr);
}

string 
NotQuery::rep() const 
{
    return string("~") + "(" + ptr->rep() + ")";
}

inline Query
operator~ ( const Query &q)
{
    return shared_ptr<QueryBase>( new NotQuery(q));
}
#endif
