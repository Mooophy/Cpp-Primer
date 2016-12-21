#ifndef QUERY_BASE_H
#define QUERY_BASE_H

#include "TextQuery.h"
#include "QueryResult.h"

class Query;

class QueryBase {

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
