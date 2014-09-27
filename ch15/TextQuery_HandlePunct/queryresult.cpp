#include "queryresult.h"

#include <iostream>
using std::ostream;

ostream&
print(ostream &os, const QueryResult &qr)
{
    os <<"The result of your query "<< qr.sought <<" is: \n";
    for (const auto &index: *qr.lines)
        os << "\t(line " << index + 1 << ")"
           << *(qr.file->begin() + index) << "\n";
    return os;
}
