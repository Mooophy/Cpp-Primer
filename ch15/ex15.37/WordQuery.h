#ifndef WORD_QUERY_H
#define WORD_QUERY_H

#include "QueryBase.h"

class Query;

class WordQuery : public QueryBase {
friend class Query;
private:
    QueryResult eval( const TextQuery & ) const override;
    string rep() const override;
    WordQuery( const string &s ):key_word(s){}
    string       key_word;   
};

QueryResult 
WordQuery::eval( const TextQuery &TQ ) const
{
    return TQ.query(key_word);
}

string 
WordQuery::rep() const 
{
    return key_word;
}

#endif
