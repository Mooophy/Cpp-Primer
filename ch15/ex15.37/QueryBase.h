#ifndef QUERY_BASE_H
#define QUERY_BASE_H

#include "TextQuery.h"
#include "QueryResult.h"

class Query;

class QueryBase {
/*
 * To call private member functions of QueryBase,
 * so it's needed to be friend class of QueryBase.
*/
friend class Query;
friend class WordQuery;
friend class NotQuery;
friend class AndQuery;
friend class OrQuery;
friend class BinaryQuery;

private:
    QueryBase() = default;
    ~QueryBase() = default;
    virtual QueryResult eval( const TextQuery & ) const = 0;
    virtual string rep() const  = 0;
};

#endif
