//
//  ex13_26.cpp
//  Exercise 13.26
//
//  Created by pezy on 1/19/15.
//
//  Write your own version of the StrBlob class described in the previous exercise.
//
//  @See    ex12_22 and ex13_25

#include "ex13_26.h"

ConstStrBlobPtr StrBlob::begin() const // should add const
{
    return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr StrBlob::end() const // should add const
{
    return ConstStrBlobPtr(*this, data->size());
}

StrBlob& StrBlob::operator=(const StrBlob& sb)
{
    data = std::make_shared<vector<string>>(*sb.data);
    return *this;
}

int main()
{
    return 0;
}
