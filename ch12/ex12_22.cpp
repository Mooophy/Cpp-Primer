//
//  ex12_22.cpp
//  CP5
//
//  Created by pezy on 1/2/15.
//  Copyright (c) 2015 pezy. All rights reserved.
//

#include "ex12_22.h"

ConstStrBlobPtr StrBlob::begin() const // should add const
{
    return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr StrBlob::end() const // should add const
{
    return ConstStrBlobPtr(*this, data->size());
}