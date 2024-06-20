#ifndef QUERY_H
#define QUERY_H

#include "QueryBase.h"
#include "WordQuery.h"

class Query {
/*
 * Overloaded bit operations need to use private constructor
 * Query::Query( shared_ptr<QueryBase> ) to construct a Query 
 * object as return value.
*/
friend Query    operator~  ( const Query &);
friend Query    operator&  ( const Query &, const Query &);
friend Query    operator|  ( const Query &, const Query &);

/*
 * To construct a NotQuery or Binary object, we need to access QB_ptr
 * in Query object, so it's needed to be friend of Query class.
*/
friend class NotQuery;
friend class AndQuery;
friend class OrQuery;
friend class BinaryQuery;

public:
    Query( const string &s) : QB_ptr( new WordQuery(s)){} // Not well if using makde_shared<WordQuery>(s)

    QueryResult 
    eval( const TextQuery &TQ ) const
    {
        return QB_ptr->eval( TQ );
    }

    string 
    rep() const
    {
        return QB_ptr->rep();
    }
private:
    Query(shared_ptr<QueryBase> query) : QB_ptr(query){}
    shared_ptr<QueryBase>   QB_ptr;
};

inline ostream&
operator<<( ostream &out, const Query &Q)
{
    out << Q.rep();
    return out;
}
#endif
