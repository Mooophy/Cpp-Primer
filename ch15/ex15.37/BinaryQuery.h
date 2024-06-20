#ifndef BINARY_QUERY_H
#define BINARY_QUERY_H

#include "QueryBase.h"
#include "Query.h"

class BinaryQuery : public QueryBase {
protected:
    BinaryQuery( const Query &Q_L, const Query &Q_R, const string &op ) : 
                                                        lhs(Q_L.QB_ptr),rhs(Q_R.QB_ptr),Bit_Op(op) {}

    string rep() const override;
    shared_ptr<QueryBase>  lhs, rhs;
    string Bit_Op;
};

string
BinaryQuery::rep() const 
{
   return "(" + lhs->rep() + " " + Bit_Op + " " + rhs->rep() + ")";
}

#endif
