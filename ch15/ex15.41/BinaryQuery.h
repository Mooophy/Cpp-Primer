#ifndef BINARY_QUERY_H
#define BINARY_QUERY_H

#include "QueryBase.h"
#include "Query.h"

class BinaryQuery : public QueryBase {
protected:
    BinaryQuery( const Query &Q_L, const Query &Q_R, const string &op ) : lhs(Q_L),rhs(Q_R),Bit_Op(op) {}
    BinaryQuery( const BinaryQuery &BQ ) : lhs(BQ.lhs),rhs(BQ.rhs),Bit_Op(BQ.Bit_Op){} 
    BinaryQuery( BinaryQuery &&BQ ) : lhs(std::move(BQ.lhs)),rhs(std::move(BQ.rhs)),Bit_Op(std::move(Bit_Op)){} 
    string rep() const override;
    Query lhs, rhs;
    string Bit_Op;
};

string
BinaryQuery::rep() const
{
    return "(" + lhs.rep() + " " + Bit_Op + " " + rhs.rep() + ")";
}

#endif
