#ifndef QUERY_BASE_H
#define QUERY_BASE_H

#include "TextQuery.h"
#include "QueryResult.h"

class Query;

class QueryBase {
/*
 * Query class will call private member functions of QueryBase,
 * so it's needed to be friend class of QueryBase.
*/
friend class Query;
/*
 * members of derived class of QueryBase can access constructor
 * QueryBase::QueryBase() and destructor QueryBase::~QueryBase(). 
*/
protected:
    QueryBase() = default;
    virtual ~QueryBase() = default;
private:
    virtual QueryResult eval( const TextQuery & ) const = 0;
    virtual string rep() const  = 0;
    virtual QueryBase* clone() & = 0;
    virtual QueryBase* clone() && = 0;
};

#endif
