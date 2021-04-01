#ifndef QUERY_H
#define QUERY_H

#include "QueryBase.h"
#include "WordQuery.h"

class Query {
friend ostream& operator<< ( ostream &, const Query &);
friend Query    operator~  ( const Query &);
friend Query    operator&  ( const Query &, const Query &);
friend Query    operator|  ( const Query &, const Query &);

public:
    Query( const string &s) : QB_ptr( new WordQuery(s)){}
    Query( const Query &Q ): QB_ptr(Q.QB_ptr->clone()){}
    Query( Query &&Q ): QB_ptr(std::move(Q.QB_ptr)->clone()){}

    ~Query()
    {
        delete QB_ptr;
    }

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
    /*
     * This constructor transforms what pointer pointing to: 
     * from pointing to derived class to pointing to base 
     * class.
    */
    Query( QueryBase* query ) : QB_ptr(query){}

    QueryBase*  QB_ptr;
};

inline ostream&
operator<<( ostream &out, const Query &Q)
{
    out << Q.rep();
    return out;
}


#endif
