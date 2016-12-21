#ifndef WORD_QUERY_H
#define WORD_QUERY_H

#include "QueryBase.h"

class Query;

class WordQuery : public QueryBase {
friend class Query;
private:
    WordQuery( const string &s ):key_word(s){}
    WordQuery( const WordQuery &WQ ) : key_word(WQ.key_word){}
    WordQuery( WordQuery &&WQ ) : key_word(std::move(WQ.key_word)){}

    WordQuery* clone() & override 
    {
        return new WordQuery(*this);
    }

    WordQuery* clone() && override
    {
        return new WordQuery(std::move(*this));
    }

    QueryResult eval( const TextQuery & ) const override;
    string rep() const override;

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
